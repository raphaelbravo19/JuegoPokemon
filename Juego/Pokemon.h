#pragma once
#include "Objetoanimado.h"
class Pokemon :
	public Objetoanimado
{
private:
	char* Nombre;
	int nivel;
	int vidamaxima;
	int vidaactual;
	int experiencia;
	int tipo1;
	int ataque;
	int ataque1;
	int ataque2;
	int ataque3;
	int ataque4;
	char* nataque1;
	char* nataque2;
	char* nataque3;
	char* nataque4;
	int zoomx;
	int zoomy;
	int evo;

public:
	Pokemon();
	Pokemon(int pzoomx, int pzoomy, char* pNombre, int pnivel, int pvidamaxima,
		int pvidaactual, int pexperiencia, int ptipo, char* pnataque1, char* pnataque2,
		char* pnataque3, char* pnataque4, int pataque1, int pataque2, int pataque3, int pataque4,
		int pPosX, int pPosY, int pDeltaX, int pDeltaY, int pAncho, int pAlto, int pTipo,
		bool pVisible, char* pNombreArchivo, int pIndiceSpriteX, int pDeltaSpriteX,
		int pIndiceSpriteY, int pDeltaSpriteY, int pevo);
	char* GetNombre();
	int Getnivel();
	int Getvidamaxima();
	int Getvidaactual();
	int Getexperiencia();
	int Gettipo();
	int Getataque();
	int Getataque1();
	int Getataque2();
	int Getataque3();
	int Getataque4();
	int Getevo();
	void Setataque(int value);
	void Setataque1(int value);
	void Setataque2(int value);
	void Setataque3(int value);
	void Setataque4(int value);
	char* Getnataque1();
	char* Getnataque2();
	char* Getnataque3();
	char* Getnataque4();
	void SetNombre(char* value);
	void Setnivel(int value);
	void Setvidamaxima(int value);
	void Setvidaactual(int value);
	void Setexperiencia(int value);
	void Settipo(int value);
	
	

	void Mostrar(System::Drawing::Graphics ^gr);
	~Pokemon();
};

