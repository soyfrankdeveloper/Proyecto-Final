#include "fisicasubmarina.h"
#include <cmath>

FisicaSubmarina::FisicaSubmarina()
{
    resistencia = 0.02;
    gravedad = 9.8;
}

/*aca valorBase =velocidad inicial
  retorna v=v0* e^(-k*t)
            (v= velocidad actual
            v0=velocidad inicial(valorBase)
            e=2.71828(numero euler)
            k=constante de resistencia o frenado
            t=tiempo transcurrido
  la velocidad se va reduciendo progresivamente con el tiempo*/

 float FisicaSubmarina::aplicarEfectoEspecial(float valorBase,
                                             float tiempo)
{
    return valorBase * exp(-resistencia*tiempo); //pd: con exp calculamos la funcion exponencial en base e(euler que equivalente a 2.71828)
}

float FisicaSubmarina::calcularPosicionX(float velocidad,
                                         float angulo,
                                         float tiempo)
{
    float anguloRad =angulo *3.1416/180.0;
    float velocidadActual = aplicarEfectoEspecial(velocidad, tiempo);
    return velocidadActual * cos(anguloRad)*tiempo;
}
float FisicaSubmarina::calcularPosicionY(float velocidad, float angulo, float tiempo)
{
    float anguloRad=angulo *3.1416/180.0;
    float velocidadActual= aplicarEfectoEspecial(velocidad, tiempo);
    return velocidadActual * sin(anguloRad)*tiempo -0.5*gravedad*tiempo*tiempo;
}
// float FisicaSubmarina::aplicarResistencia(float velocidadInicial,
//                                           float tiempo)
// {
//     return velocidadInicial * exp(-resistencia * tiempo);
// }
