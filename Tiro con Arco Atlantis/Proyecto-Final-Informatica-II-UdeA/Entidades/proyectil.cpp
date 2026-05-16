#include "proyectil.h"
#include <cmath>

Proyectil::Proyectil()

{
    angulo = 0;
    velocidadInicial = 0;
    tiempo = 0;
}

void Proyectil::lanzar(float nuevaVelocidad, float nuevoAngulo)

{
    velocidadInicial = nuevaVelocidad;
    angulo = nuevoAngulo;
}

void Proyectil::actualizar()

{
    tiempo += 0.1;

    x = velocidadInicial * cos(angulo) * tiempo;

    y = velocidadInicial * sin(angulo) * tiempo
        - 0.5 * 9.8 * tiempo * tiempo;
}

float Proyectil::getAngulo()

{
    return angulo;
}

float Proyectil::getVelocidadInicial()

{
    return velocidadInicial;
}