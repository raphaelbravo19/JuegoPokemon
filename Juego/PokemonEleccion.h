#pragma once
#include "Objetoanimado.h"
class PokemonEleccion :
	public Objetoanimado
{
private: 
	int zoomx;
	int zoomy;
public:
	PokemonEleccion();
	PokemonEleccion(int pzoomx, int pzoomy,int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY);

	void Mostrar(System::Drawing::Graphics ^gr);
	~PokemonEleccion();
};

