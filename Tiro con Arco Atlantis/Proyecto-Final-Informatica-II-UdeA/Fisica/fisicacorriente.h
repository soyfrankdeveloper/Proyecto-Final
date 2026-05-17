#ifndef FISICACORRIENTE_H
#define FISICACORRIENTE_H

#include "Fisica.h"

class FisicaCorriente : public Fisica
{
private:
    float aceleracionCorriente;

public:
    FisicaCorriente();

    float aplicarCorriente(float posicionX,
                           float tiempo);
};

#endif // FISICACORRIENTE_H