#include "proyectil.h"

Proyectil::Proyectil()
{
    angulo = 0;
    velocidadInicial = 0;
    tiempo = 0;
}

void Proyectil::lanzar(float nuevaVelocidad,
                       float nuevoAngulo,
                       float nuevaX,
                       float nuevaY)
{
    velocidadInicial = nuevaVelocidad;
    angulo = nuevoAngulo;

    xInicial = nuevaX;
    yInicial = nuevaY;
}

void Proyectil::actualizar()
{
    tiempo += 0.1;

    x = xInicial +
        fisica.calcularPosicionX(
            velocidadInicial,
            angulo,
            tiempo);

    y = yInicial +
        fisica.calcularPosicionY(
            velocidadInicial,
            angulo,
            tiempo);
}

bool Proyectil::verificarColision(float objetivoX,
                                  float objetivoY)
{
    if(x >= objetivoX &&
        x <= objetivoX + 50 &&
        y >= objetivoY &&
        y <= objetivoY + 50)
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

void Proyectil::setDelJugador(bool valor)
{
    delJugador = valor;
}

bool Proyectil::getDelJugador()
{
    return delJugador;
}