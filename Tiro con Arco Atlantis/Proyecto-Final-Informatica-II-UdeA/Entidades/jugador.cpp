#include "jugador.h"

Jugador::Jugador()
{
    angulo = 45;
    potencia = 100;
}

void Jugador::apuntar(float nuevoAngulo)
{
    angulo = nuevoAngulo;
}

float Jugador::getAngulo()
{
    return angulo;
}

void Jugador::setPotencia(float nuevaPotencia)
{
    potencia = nuevaPotencia;
}

float Jugador::getPotencia()
{
    return potencia;
}