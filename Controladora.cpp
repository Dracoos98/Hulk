#include "Controladora.h"

Controladora::Controladora()
{
	objHulkc = new Hulkc(45, 85, 20, 20);
}

Controladora::~Controladora()
{
	delete objHulkc;
}

void Controladora::Dibujar_Hulkc(Graphics^ g, Bitmap^ bmp)
{
	objHulkc->Dibujar_desImagen(g, bmp);
	objHulkc->Mover(g);
}

void Controladora::Desplazar_Hulkc(direccion nuevo)
{
	objHulkc->Desplazamiento(nuevo);
}

bool Controladora::Colision()
{
	bool resultado_colision = false;
	Rectangle rHulkc = objHulkc->retonar_rectangle();
	Rectangle rZP = objZP->retonar_r();
	resultado_colision = rHulkc.IntersectsWith(rZP);
	return resultado_colision;
}
	


