#include "enemigo.h"

Enemigo::Enemigo()

{
    moviendo = false;
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