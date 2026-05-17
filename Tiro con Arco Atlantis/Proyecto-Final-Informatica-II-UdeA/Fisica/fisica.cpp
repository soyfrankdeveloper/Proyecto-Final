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
    return velocidad * cos(angulo) * tiempo;
}

float Fisica::calcularPosicionY(float velocidad,
                                float angulo,
                                float tiempo)
{
    return velocidad * sin(angulo) * tiempo
           - 0.5 * gravedad * tiempo * tiempo;
}