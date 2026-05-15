#include "entidad.h"

Entidad::Entidad()
{
    x = 0;
    y = 0;
    velocidad = 0;
}

void Entidad::setPosicion(float nuevax, float nuevay)
{
    x = nuevax;
    y = nuevay;
}

float Entidad::getX()
{
    return x;
}

float Entidad::getY()
{
    return y;
}

void Entidad::mover()
{

}