#include "proyectil.h"
#include "../Fisica/fisicaSubmarina.h"
#include <cmath>

Proyectil::Proyectil()
{
    angulo = 0;
    velocidadInicial = 0;
    tiempo = 0;

    fisica = new FisicaSubmarina();

    delJugador = false;
}
Proyectil::~Proyectil()//un destructor para que libere la fisica asignada
{
    delete fisica;
}

//nos permite asignar otra fisica desde juego(nivel2)
void Proyectil::setFisica(Fisica*nuevaFisica)
{
    delete fisica;
    fisica= nuevaFisica;
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

    // float velocidadActual;

    // velocidadActual = velocidadInicial;

    // FisicaSubmarina* submarina;

    // submarina =
    //     dynamic_cast<FisicaSubmarina*>(fisica);

    // if(submarina != nullptr)
    // {
    //     velocidadActual =
    //         submarina->aplicarResistencia(
    //             velocidadInicial,
    //             tiempo);
    // }

    x = xInicial +
        fisica->calcularPosicionX(
            velocidadInicial,
            angulo,
            tiempo);

    y = yInicial +
        fisica->calcularPosicionY(
            velocidadInicial,
            angulo,
            tiempo);
}

bool Proyectil::verificarColision(float objetivoX,
                                  float objetivoY)
{
    if(x >= objetivoX - 15 &&
        x <= objetivoX + 65 &&
        y >= objetivoY - 15 &&
        y <= objetivoY + 65)
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

float Proyectil::getAnguloActual()
{
    float vx =
        fisica->calcularVelocidadX(
            velocidadInicial,
            angulo,
            tiempo);

    float vy =
        fisica->calcularVelocidadY(
            velocidadInicial,
            angulo,
            tiempo);

    return atan2(vy, vx) * 180.0 / 3.1416;
}

void Proyectil::setDelJugador(bool valor)
{
    delJugador = valor;
}

bool Proyectil::getDelJugador()
{
    return delJugador;
}
