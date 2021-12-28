#include "Hulkc.h"

Hulkc::Hulkc()
{
}

Hulkc::Hulkc(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 4, 4,0,0)
{
	fraccion_movimientoX = 2;
	fraccion_movimientoY = 2;
	orientacion = direccion::derecha;
}

Hulkc::~Hulkc()
{
}

void Hulkc::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy = 0;
	x += dx;
	y += dy;
}


