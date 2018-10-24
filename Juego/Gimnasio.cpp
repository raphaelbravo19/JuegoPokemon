#include "Gimnasio.h"
#include <string.h>

Gimnasio::Gimnasio()
{
}
Gimnasio::Gimnasio(int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY)
{
	PosX = pPosX;
	PosY = pPosY;
	DeltaX = pDeltaX;
	DeltaY = pDeltaY;
	Ancho = pAncho;
	Alto = pAlto;
	Tipo = pTipo;
	Visible = pVisible;
	NombreArchivo = new char[100];
	strcpy(NombreArchivo, pNombreArchivo);
	IndiceSpriteX = pIndiceSpriteX;
	DeltaSpriteY = pDeltaSpriteY;
	IndiceSpriteY = pIndiceSpriteX;
	DeltaSpriteX = pDeltaSpriteY;
}

void Gimnasio::Mostrar(System::Drawing::Graphics ^gr)
{
	if (Visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(0, 0, Ancho-230, Alto-250);
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(0,0, Ancho, Alto);
		
		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		delete bmp;
	}
}


Gimnasio::~Gimnasio()
{
	delete[]NombreArchivo;
}
