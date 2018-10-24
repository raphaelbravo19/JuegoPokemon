#pragma once
#include "Objetoanimado.h"
class Marco :
	public Objetoanimado
{
public:
	Marco();
	Marco(int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY);
	
	void Mostrar(System::Drawing::Graphics ^gr);

	~Marco();
};

