#include "fisicasubmarina.h"
#include <cmath>

FisicaSubmarina::FisicaSubmarina()
{
    resistencia = 0.2;
}

float FisicaSubmarina::aplicarResistencia(float velocidadInicial,
                                          float tiempo)
{
    return velocidadInicial * exp(-resistencia * tiempo);
}