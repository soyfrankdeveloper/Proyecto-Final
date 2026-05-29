#include "fisica.h"
#include <cmath>

Fisica::Fisica()
{
    gravedad = 9.8;
}

float Fisica::calcularPosicionX(float velocidad,
                                float angulo,
                                float tiempo)
{
    float radianes;

    radianes = angulo * 3.1416 / 180;

    return velocidad * cos(radianes) * tiempo;
}

float Fisica::calcularPosicionY(float velocidad,
                                float angulo,
                                float tiempo)
{
    float radianes;

    radianes = angulo * 3.1416 / 180;

    return velocidad * sin(radianes) * tiempo
           - 0.5 * gravedad * tiempo * tiempo;
}