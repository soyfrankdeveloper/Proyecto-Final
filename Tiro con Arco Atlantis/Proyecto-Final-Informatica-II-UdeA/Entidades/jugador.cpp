#include "jugador.h"

Jugador::Jugador()
{
    angulo = 0;
}

void Jugador::apuntar(float nuevoAngulo)
{
    angulo = nuevoAngulo;
}

float Jugador::getAngulo()
{
    return angulo;
}