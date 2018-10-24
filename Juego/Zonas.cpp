#include "Zonas.h"


Zonas::Zonas(int pzoomx, int pzoomy, int pPosX, int pPosY, int pDeltax, int pDeltay, int pAncho, int pAlto, int pcolor)
{
	zoomx = pzoomx;
	zoomy = pzoomy;
	PosX = pPosX;
	PosY = pPosY;
	Ancho = pAncho;
	Alto = pAlto;
	DeltaX = pDeltax;
	DeltaY = pDeltay;
	color = pcolor;
}
void Zonas::Mostrar(System::Drawing::Graphics ^gr)
{
	if (Visible) {
		//if (color == 1) gr->DrawRectangle(System::Drawing::Pens::Red, PosX, PosY, Ancho, Alto);
		//if (color == 2) gr->DrawRectangle(System::Drawing::Pens::Blue, PosX, PosY, Ancho, Alto);
		
	}
	
}

Zonas::~Zonas()
{
}
