#include "fisicacorriente.h"
#include <cmath>

FisicaCorriente::FisicaCorriente()
{
    aceleracionCorriente = 2;
    gravedad =9.8;
}


/*aca tenemos que valorBase representa la posicion X a modificar, sería
 valorBase= posicion x sin corriente
retorna x=posX +0.5 * ac*t^2
        (x= posicion horizontal final
        posX = posicion horizontal inicial(valorbase)
        ac=aceleracion producida por la corriente
        t=tiempo transcurrido)

la flecha es empujada por la corriente horizontalmente*/

 float FisicaCorriente::aplicarEfectoEspecial(float valorBase,
                                              float tiempo)
{
    return valorBase +0.5*aceleracionCorriente*tiempo*tiempo;
}
/*ahora sobreescribimos calcularPosicionX:
 * calcular posicion base y luego le aplicamos la corriente
 */
float FisicaCorriente::calcularPosicionX(float velocidad, float angulo, float tiempo)
{
    float anguloRad = angulo *3.1416/180.0;
    float posicionBase = velocidad*cos(anguloRadX)tiempo;

    return aplicarEfectoEspecial(posicionBase,tiempo);
}
// float FisicaCorriente::aplicarCorriente(float posicionX,
//                                         float tiempo)
// {
//     return posicionX +
//            0.5 * aceleracionCorriente * tiempo * tiempo;
// }
