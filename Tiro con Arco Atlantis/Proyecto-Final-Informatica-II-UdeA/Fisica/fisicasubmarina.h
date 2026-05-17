#ifndef FISICASUBMARINA_H
#define FISICASUBMARINA_H

#include "Fisica.h"

class FisicaSubmarina : public Fisica
{
private:
    float resistencia;

public:
    FisicaSubmarina();

    float aplicarResistencia(float velocidadInicial,
                             float tiempo);
};

#endif // FISICASUBMARINA_H