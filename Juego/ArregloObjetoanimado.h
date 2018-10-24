#pragma once
#include "Objetoanimado.h"
class ArregloObjetoanimado
{
private:
	Objetoanimado** Arreglo;
	int Cantidad;
	int Capacidad;
	int Incremento;
public:
	ArregloObjetoanimado();
	void IncrementaCapacidad();
	void AgregaObjetoAnimado(Objetoanimado* pObjetoAnimado);
	void EliminarObjetoAnimado(int pPos);
	Objetoanimado* DameObjetoAnimado(int pPos);
	int GetCantidad();
	~ArregloObjetoanimado();
};

