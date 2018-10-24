#include "ArregloPokemon.h"


ArregloPokemon::ArregloPokemon()
{
	Cantidad = 0;
	Incremento = 5;
	Capacidad = Incremento;
	Arreglo = new Pokemon*[Capacidad];
}

void ArregloPokemon::IncrementaCapacidad()
{
	Pokemon** Temp;
	Temp = Arreglo;
	Capacidad = Capacidad + Incremento;
	Arreglo = new Pokemon*[Capacidad];
	for (int i = 0; i < Cantidad; i++) {
		Arreglo[i] = Temp[i];
	}
}

void ArregloPokemon::AgregaObjetoAnimado(Pokemon* pObjetoanimado)
{
	if (Cantidad == Capacidad)
		IncrementaCapacidad();
	Arreglo[Cantidad] = pObjetoanimado;
	Cantidad++;
}

void ArregloPokemon::EliminarObjetoAnimado(int pPos)
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
void ArregloPokemon::AgregarPokemonEnPosicion(Pokemon* pObjetoAnimado, int pPos)
{
	if (pObjetoAnimado != 0)
	{
		Arreglo[pPos] = pObjetoAnimado;
	}
}
Pokemon* ArregloPokemon::DameObjetoAnimado(int pPos)
{
	return Arreglo[pPos];
}

int ArregloPokemon::GetCantidad()
{
	return Cantidad;
}

ArregloPokemon::~ArregloPokemon()
{
	for (int i = 0; i < Cantidad; i++) {
		if (Arreglo[i] != 0)
			delete Arreglo[i];
	}
	delete[]Arreglo;
}
