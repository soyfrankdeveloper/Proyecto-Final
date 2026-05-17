#include "fisicacorriente.h"

FisicaCorriente::FisicaCorriente()
{
    aceleracionCorriente = 2;
}

float FisicaCorriente::aplicarCorriente(float posicionX,
                                        float tiempo)
{
    return posicionX +
           0.5 * aceleracionCorriente * tiempo * tiempo;
}