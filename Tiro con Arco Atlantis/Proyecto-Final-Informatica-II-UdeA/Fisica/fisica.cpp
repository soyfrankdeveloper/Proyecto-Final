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
    float anguloRadianes;

    anguloRadianes = angulo * 3.1416 / 180.0;

    return velocidad *
           cos(anguloRadianes) *
           tiempo;
}

float Fisica::calcularPosicionY(float velocidad,
                                float angulo,
                                float tiempo)
{
    float anguloRadianes;

    anguloRadianes = angulo * 3.1416 / 180.0;

    return velocidad *
               sin(anguloRadianes) *
               tiempo
           - 0.5 *
                 gravedad *
                 tiempo *
                 tiempo;
}