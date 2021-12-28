#include "ZonaP.h"

ZonaP::ZonaP()
{
	x = 0;
	y = 0;
	w = 324;
	h = 519;
}

ZonaP::~ZonaP()
{
}

Rectangle ZonaP::retonar_r()
{
	return Rectangle(x,y,w,h);
}


