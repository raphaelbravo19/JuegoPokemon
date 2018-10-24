#pragma once
class Objetoanimado
{
protected:
	int PosX;
	int PosY;
	int DeltaX;
	int DeltaY;
	int Ancho;
	int Alto;
	int Tipo;
	bool Visible;
	char* NombreArchivo;
	int IndiceSpriteX;
	int IndiceSpriteY;
	int DeltaSpriteX;
	int DeltaSpriteY;
public:
	Objetoanimado();
	~Objetoanimado();
	void Mover();
	void CambiarSprite();
	virtual void Mostrar(System::Drawing::Graphics ^gr);
	int GetPosX();
	int GetPosY();
	int GetDeltaX();
	int GetDeltaY();
	int GetAncho();
	int GetAlto();
	int GetTipo();
	bool GetVisible();
	char* GetNombreArchivo();
	void SetPosX(int value);
	void SetPosY(int value);
	void SetDeltaX(int value);
	void SetDeltaY(int value);
	void SetAncho(int value);
	void SetAlto(int value);
	void SetTipo(int value);
	void SetVisible(bool value);
	void SetNombreArchivo(char* value);
	int GetIndiceSpriteX();
	int GetIndiceSpriteY();
	int GetDeltaSpriteX();
	int GetDeltaSpriteY();
	void SetIndiceSpriteX(int value);
	void SetIndiceSpriteY(int value);
	void SetDeltaSpriteX(int value);
	void SetDeltaSpriteY(int value);
};

