#pragma once
#include "Hulkc.h"
#include "ZonaP.h"
using namespace System::Drawing;
class Controladora
{
private:
	Hulkc* objHulkc;
	ZonaP* objZP;
public:
	Controladora();
	~Controladora();
	void Dibujar_Hulkc(Graphics^ g, Bitmap^ bmp);
	void Desplazar_Hulkc(direccion nuevo);
	bool Colision();

};

