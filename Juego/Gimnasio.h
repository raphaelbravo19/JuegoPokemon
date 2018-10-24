#pragma once
#include "Objetoanimado.h"
class Gimnasio :
	public Objetoanimado
{
public:
	Gimnasio();
	Gimnasio(int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY);

	void Mostrar(System::Drawing::Graphics ^gr);
	~Gimnasio();
};

