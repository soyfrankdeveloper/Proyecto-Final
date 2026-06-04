#ifndef FISICACORRIENTE_H
#define FISICACORRIENTE_H

#include "Fisica.h"

class FisicaCorriente : public Fisica
{
private:
    float aceleracionCorriente;

public:
    FisicaCorriente();

    //float aplicarCorriente(float posicionX,
     //                      float tiempo);


    /*aplicarEfectoEspecial recibe una posicionX base, y nos retorna una posicion desviadad por la corriente marina*/
     virtual float aplicarEfectoEspecial(float valorBase,
                                         float tiempo);

     //sobreescribimos solo en x puesto que la corriente afecta unicamente el eje horizontal
     virtual float calcularPosicionX(float velocidad,
                                     float angulo,
                                     float tiempo);
};

#endif // FISICACORRIENTE_H
