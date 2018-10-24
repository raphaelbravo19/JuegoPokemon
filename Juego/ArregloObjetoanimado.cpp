#include "ArregloObjetoanimado.h"


ArregloObjetoanimado::ArregloObjetoanimado()
{
	Cantidad = 0;
	Incremento = 5;
	Capacidad = Incremento;
	Arreglo = new Objetoanimado*[Capacidad];
}

void ArregloObjetoanimado::IncrementaCapacidad()
{
	Objetoanimado** Temp;
	Temp = Arreglo;
	Capacidad = Capacidad + Incremento;
	Arreglo = new Objetoanimado*[Capacidad];
	for (int i = 0; i < Cantidad; i++) {
		Arreglo[i] = Temp[i];
	}
}

void ArregloObjetoanimado::AgregaObjetoAnimado(Objetoanimado* pObjetoanimado)
{
	if (Cantidad == Capacidad)
		IncrementaCapacidad();
	Arreglo[Cantidad] = pObjetoanimado;
	Cantidad++;
}
 
void ArregloObjetoanimado::EliminarObjetoAnimado(int pPos)
{
	if (pPos < Cantidad) {
		delete Arreglo[pPos];
		Cantidad--;
		for (int i = pPos; i < Cantidad; i++){
			Arreglo[i] = Arreglo[i + 1];
		}
		for (int i = Cantidad; i < Capacidad; i++){
			Arreglo[i] = 0;
		}

	}
}

Objetoanimado* ArregloObjetoanimado::DameObjetoAnimado(int pPos)
{
	return Arreglo[pPos];
}

int ArregloObjetoanimado::GetCantidad()
{
	return Cantidad;
}

ArregloObjetoanimado::~ArregloObjetoanimado()
{
	for (int i = 0; i < Cantidad; i++) {
		if (Arreglo[i] != 0)
			delete Arreglo[i];
	}
	delete[]Arreglo;
}
