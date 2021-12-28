#pragma once
#include "Base.h"
class Hulkc :
    public Base
{
public:
    Hulkc();
    Hulkc(int px, int py, int pw, int ph);
    ~Hulkc();
    void Mover(Graphics^ g);

};

