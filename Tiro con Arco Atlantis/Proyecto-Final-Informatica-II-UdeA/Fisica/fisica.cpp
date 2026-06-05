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

float Fisica::calcularVelocidadX(float velocidad,
                                 float angulo,
                                 float tiempo)
{
    float anguloRadianes;

    anguloRadianes = angulo * 3.1416 / 180.0;

    return velocidad *
           cos(anguloRadianes);
}

float Fisica::calcularVelocidadY(float velocidad,
                                 float angulo,
                                 float tiempo)
{
    float anguloRadianes;

    anguloRadianes = angulo * 3.1416 / 180.0;

    return velocidad *
               sin(anguloRadianes)
           - gravedad * tiempo;
}

/*aplicamos el comportamiento por defecto del nivel 1, donde no alteramos los valores
*/
float Fisica::aplicarEfectoEspecial(float valorBase, float tiempo)
{
    return valorBase;
}
