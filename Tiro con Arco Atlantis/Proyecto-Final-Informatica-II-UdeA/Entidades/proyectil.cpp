#include "proyectil.h"

Proyectil::Proyectil()
{
    angulo = 0;
    velocidadInicial = 0;
    tiempo = 0;
}

void Proyectil::lanzar(float nuevaVelocidad,
                       float nuevoAngulo)
{
    velocidadInicial = nuevaVelocidad;
    angulo = nuevoAngulo;
}

void Proyectil::actualizar()
{
    tiempo += 0.1;

    x = fisica.calcularPosicionX(
        velocidadInicial,
        angulo,
        tiempo);

    y = fisica.calcularPosicionY(
        velocidadInicial,
        angulo,
        tiempo);
}

bool Proyectil::verificarColision(float objetivoX,
                                  float objetivoY)
{
    if(x >= objetivoX - 5 &&
        x <= objetivoX + 5 &&
        y >= objetivoY - 5 &&
        y <= objetivoY + 5)
    {
        return true;
    }

    return false;
}

float Proyectil::getAngulo()
{
    return angulo;
}


float Proyectil::getVelocidadInicial()
{
    return velocidadInicial;
}