#pragma once
#include "Objetoanimado.h"
class Zonas :
	public Objetoanimado
{
private:
	int zoomx;
	int zoomy;
	int color;
public:
	Zonas(int pzoomx, int pzoomy, int pPosX, int pPosY, int pDeltax, int pDeltay, int pAncho, int pAlto, int pcolor);
	~Zonas();
	void Mostrar(System::Drawing::Graphics ^gr);
};

