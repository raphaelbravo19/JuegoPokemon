#include "PokemonEleccion.h"
#include <string.h>

PokemonEleccion::PokemonEleccion()
{
}
PokemonEleccion::PokemonEleccion(int pzoomx, int pzoomy,int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo, bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY)
{
	PosX = pPosX;
	PosY = pPosY;
	DeltaX = pDeltaX;
	DeltaY = pDeltaY;
	Ancho = pAncho;
	Alto = pAlto;
	Tipo = pTipo;
	zoomx = pzoomx;
	zoomy = pzoomy;
	Visible = pVisible;
	NombreArchivo = new char[100];
	strcpy(NombreArchivo, pNombreArchivo);
	IndiceSpriteX = pIndiceSpriteX;
	DeltaSpriteY = pDeltaSpriteY;
	IndiceSpriteY = pIndiceSpriteX;
	DeltaSpriteX = pDeltaSpriteY;
}

void PokemonEleccion::Mostrar(System::Drawing::Graphics ^gr)
{
	if (Visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Ancho*IndiceSpriteX, Alto*IndiceSpriteY, Ancho, Alto);
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(PosX, PosY, Ancho+zoomx, Alto+zoomy);
		bmp->MakeTransparent(bmp->GetPixel(1, 1));


		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		//gr->DrawRectangle(System::Drawing::Pens::Red, PosX, PosY, Ancho, Alto);
		delete bmp;
	}
}

PokemonEleccion::~PokemonEleccion()
{
}
