#include "obstaculo.h"
#include <cstdlib>

Obstaculo::Obstaculo()
{
    x = 200 + rand() % 600;

    y = 700;

    velocidad = 2;
}

void Obstaculo::actualizar()
{
    y -= velocidad;
}

float Obstaculo::getX()
{
    return x;
}

float Obstaculo::getY()
{
    return y;
}

bool Obstaculo::fueraDePantalla()
{
    return y < -50;
}

bool Obstaculo::verificarColision(float px,
                                  float py)
{
    return px >= x - 10 &&
           px <= x + 40 &&
           py >= y - 10 &&
           py <= y + 40;
}