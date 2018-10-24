#include "Pokemon.h"
#include <string.h>

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(int pzoomx, int pzoomy, char* pNombre, int pnivel, int pvidamaxima, int pvidaactual, int pexperiencia, 
	int ptipo, char* pnataque1, char* pnataque2,char* pnataque3, char* pnataque4, int pataque1, int pataque2, 
	int pataque3, int pataque4, int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto,int pTipo, 
	bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX, int pIndiceSpriteY, int pDeltaSpriteY
	, int pevo)
{
	zoomx = pzoomx;
	zoomy = pzoomy;
	Nombre = new char[100];
	strcpy(Nombre, pNombre);
	nataque1 = new char[100];
	strcpy(nataque1, pnataque1);
	nataque2 = new char[100];
	strcpy(nataque2, pnataque2);
	nataque3 = new char[100];
	strcpy(nataque3, pnataque3);
	nataque4 = new char[100];
	strcpy(nataque4, pnataque4);
	nivel=pnivel;
	vidamaxima=pvidamaxima;
	vidaactual=pvidaactual;
	experiencia=pexperiencia;
	tipo1=ptipo;
	ataque = pnivel;
	ataque1 = pataque1;
	ataque2 = pataque2;
	ataque3 = pataque3;
	ataque4 = pataque4;
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
	evo = pevo;
}

char* Pokemon::GetNombre()
{
	return Nombre;
}

int Pokemon::Getnivel()
{
	return nivel;
}
int Pokemon::Getataque()
{
	return ataque;
}
int Pokemon::Getevo()
{
	return evo;
}
int Pokemon::Getvidamaxima()
{
	return vidamaxima;
}

int Pokemon::Getvidaactual()
{
	return vidaactual;
}

int Pokemon::Getexperiencia()
{
	return experiencia;
}

int Pokemon::Gettipo()
{
	return tipo1;
}

int Pokemon::Getataque1()
{
	return ataque1;
}
int Pokemon::Getataque2()
{
	return ataque2;
}
int Pokemon::Getataque3()
{
	return ataque3;
}
int Pokemon::Getataque4()
{
	return ataque4;

}
void Pokemon::Setataque(int value)
{
	ataque = value;
}
void Pokemon::Setataque1(int value)
{
	ataque1 = value;
}
void Pokemon::Setataque2(int value)
{
	ataque2 = value;
}
void Pokemon::Setataque3(int value)
{
	ataque3 = value;
}
void Pokemon::Setataque4(int value)
{
	ataque4 = value;
}
char* Pokemon::Getnataque1()
{
	return nataque1;
}
char* Pokemon::Getnataque2()
{
	return nataque2;
}
char* Pokemon::Getnataque3()
{
	return nataque3;
}
char* Pokemon::Getnataque4()
{
	return nataque4;
}
void Pokemon::SetNombre(char* value)
{
	strcpy(Nombre, value);
}

void Pokemon::Setnivel(int value)
{
	nivel = value;
	ataque = value;
}

void Pokemon::Setvidamaxima(int value)
{
	vidamaxima = value;
}

void Pokemon::Setexperiencia(int value)
{
	experiencia = value;
}

void Pokemon::Setvidaactual(int value)
{
	vidaactual = value;
}

void Pokemon::Mostrar(System::Drawing::Graphics ^gr)
{
	if (Visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Ancho*IndiceSpriteX, Alto*IndiceSpriteY, Ancho, Alto );
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(PosX, PosY, Ancho+zoomx, Alto+zoomy);
		bmp->MakeTransparent(bmp->GetPixel(1, 1));


		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		delete bmp;
	}
}
void Pokemon::Settipo(int value)
{
	tipo1 = value;
}
Pokemon::~Pokemon()
{
	delete[]NombreArchivo;
	delete[]Nombre;
	delete[]nataque1;
	delete[]nataque2;
	delete[]nataque3;
	delete[]nataque4;
}
