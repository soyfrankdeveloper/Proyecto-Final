#ifndef FISICACORRIENTE_H
#define FISICACORRIENTE_H

#include "fisicasubmarina.h"

class FisicaCorriente : public FisicaSubmarina
{
private:
    float aceleracionCorriente;

public:
    FisicaCorriente();

    virtual float aplicarEfectoEspecial(float valorBase,
                                        float tiempo);

    virtual float calcularPosicionX(float velocidad,
                                    float angulo,
                                    float tiempo);
};

#endif