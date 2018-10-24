#pragma once
#include "Pokemon.h"
class ArregloPokemon
{
private:
	Pokemon** Arreglo;
	int Cantidad;
	int Capacidad;
	int Incremento;
public:
	ArregloPokemon();
	void IncrementaCapacidad();
	void AgregaObjetoAnimado(Pokemon* pObjetoAnimado);
	void EliminarObjetoAnimado(int pPos);
	Pokemon* DameObjetoAnimado(int pPos);
	void AgregarPokemonEnPosicion(Pokemon* pObjetoAnimado, int pPos);
	int GetCantidad();
	~ArregloPokemon();
};

