#include "Objetoanimado.h"
#include <string.h>


Objetoanimado::Objetoanimado()
{
	NombreArchivo = new char[100];
}


Objetoanimado::~Objetoanimado()
{
	delete[]NombreArchivo;
}

void Objetoanimado::Mover()
{
	PosX = PosX + DeltaX;
	PosY = PosY + DeltaY;
}

void Objetoanimado::CambiarSprite()
{
	IndiceSpriteX = IndiceSpriteX + DeltaSpriteX;
	IndiceSpriteY = IndiceSpriteY + DeltaSpriteY;

}

void Objetoanimado::Mostrar(System::Drawing::Graphics ^gr)
{

}

int Objetoanimado::GetPosX()
{
	return PosX;
}

int Objetoanimado::GetPosY()
{
	return PosY;
}

int Objetoanimado::GetDeltaX()
{
	return DeltaX;
}

int Objetoanimado::GetDeltaY()
{
	return DeltaY;
}

int Objetoanimado::GetAncho()
{
	return Ancho;
}

int Objetoanimado::GetAlto()
{
	return Alto;
}

int Objetoanimado::GetTipo()
{
	return Tipo;
}

bool Objetoanimado::GetVisible()
{
	return Visible;
}

char* Objetoanimado::GetNombreArchivo()
{
	return NombreArchivo;
}


void Objetoanimado::SetPosX(int value)
{
	PosX = value;
}

void Objetoanimado::SetPosY(int value)
{
	PosY = value;
}

void Objetoanimado::SetDeltaX(int value)
{
	DeltaX = value;
}

void Objetoanimado::SetDeltaY(int value)
{
	DeltaY = value;
}

void Objetoanimado::SetAncho(int value)
{
	Ancho = value;
}

void Objetoanimado::SetAlto(int value)
{
	Alto = value;
}

void Objetoanimado::SetTipo(int value)
{
	Tipo = value;
}

void Objetoanimado::SetVisible(bool value)
{
	Visible = value;
}

void Objetoanimado::SetNombreArchivo(char* value)
{
	strcpy(NombreArchivo, value);
}


int Objetoanimado::GetIndiceSpriteX()
{
	return IndiceSpriteX;
}

int Objetoanimado::GetIndiceSpriteY()
{
	return IndiceSpriteY;
}

int Objetoanimado::GetDeltaSpriteX()
{
	return DeltaSpriteX;
}

int Objetoanimado::GetDeltaSpriteY()
{
	return DeltaSpriteY;
}

void Objetoanimado::SetIndiceSpriteX(int value)
{
	IndiceSpriteX = value;
}

void Objetoanimado::SetIndiceSpriteY(int value)
{
	IndiceSpriteY = value;
}

void Objetoanimado::SetDeltaSpriteX(int value)
{
	DeltaSpriteX = value;
}

void Objetoanimado::SetDeltaSpriteY(int value)
{
	DeltaSpriteY = value;
}

