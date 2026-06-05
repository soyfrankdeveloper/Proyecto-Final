#include "enemigo.h"
#include <cmath>

Enemigo::Enemigo()

{
    moviendo = false;
    tiempoMovimiento = 0;
    posicionBase = 800;
}

void Enemigo::tomarDecision()

{
    moviendo = true;
}

void Enemigo::esquivar()

{
    x += 5;
}

bool Enemigo::getMoviendo()

{
    return moviendo;
}

void Enemigo::actualizarMovimiento()
{
    tiempoMovimiento += 0.05;

    x = posicionBase +
        150 * sin(tiempoMovimiento);

    y = 200;
}
