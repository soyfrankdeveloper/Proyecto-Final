#include "fisicasubmarina.h"
#include <cmath>

FisicaSubmarina::FisicaSubmarina()
{
    resistencia = 0.2;
}

/*aca valorBase representa una velocidad inicial a modificar
 float FisicaSubmarina::aolicarEfectoEspecial(float valorBase, float tiempo)
{
    return valorBase * exp(-resistencia*tiempo; //pd: con expcalculamos la funcion exponencial en base e(euler que equivalente a 2.71828)
}*/

float FisicaSubmarina::aplicarResistencia(float velocidadInicial,
                                          float tiempo)
{
    return velocidadInicial * exp(-resistencia * tiempo);
}
