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

void Jugador::moverArriba()
{
    if(y < 500)
        y += 10;
}

void Jugador::moverAbajo()
{
    if(y > 50)
        y -= 10;
}

void Jugador::moverIzquierda()
{
    if(x > 50)
        x -= 10;
}

void Jugador::moverDerecha()
{
    if(x < 400)
        x += 10;
}
