#include "fisicacorriente.h"

FisicaCorriente::FisicaCorriente()
{
    aceleracionCorriente = 2;
}


/*aca tenemos que valorBase representa la posicion X a modificar, sería
 float FisicaCorriente::aplicarEfectoEspecial(float valorBase, float tiempo)
{
    return valorBase +0.5*aceleracionCorriente*tiempo*tiempo;*/

float FisicaCorriente::aplicarCorriente(float posicionX,
                                        float tiempo)
{
    return posicionX +
           0.5 * aceleracionCorriente * tiempo * tiempo;
}
