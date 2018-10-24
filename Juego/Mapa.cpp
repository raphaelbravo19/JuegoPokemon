#include "Mapa.h"
#include <string.h>

Mapa::Mapa()
{
}


Mapa::Mapa(int pzoomx2, int pzoomy2, int pzoomx, int pzoomy, int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY)
{
	zoomx2 = pzoomx2;
	zoomy2 = pzoomy2;
	zoomx = pzoomx;
	zoomy = pzoomy;
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

Mapa::~Mapa()
{
	delete[]NombreArchivo;
}

void Mapa::Mostrar(System::Drawing::Graphics ^gr)
{
	if (Visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(PosX, PosY, Ancho - zoomx, Alto - zoomy);
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(0, 0, Ancho+zoomx2, Alto+zoomy2);
		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		delete bmp;
	}
}