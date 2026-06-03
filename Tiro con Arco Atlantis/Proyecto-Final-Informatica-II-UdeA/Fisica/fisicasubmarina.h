#ifndef FISICASUBMARINA_H
#define FISICASUBMARINA_H

#include "Fisica.h"

class FisicaSubmarina : public Fisica
{
private:
    float resistencia;

public:
    FisicaSubmarina();


    /*la version que propongo para la sobreescritura del metodo virtual sería la sgte
     virtual float aplicarEfectosEspecial(float valorBase, float tiempo);*/

    float aplicarResistencia(float velocidadInicial,
                             float tiempo);
};

#endif // FISICASUBMARINA_H
