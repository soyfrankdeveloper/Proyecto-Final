#ifndef FISICASUBMARINA_H
#define FISICASUBMARINA_H

#include "Fisica.h"

class FisicaSubmarina : public Fisica
{
private:
    float resistencia;

public:
    FisicaSubmarina();
    //aplicarEfectoEspecial recibe velocidad y retorna velocidad reducida por la resistencia del agua

    /*la version que propongo para la sobreescritura del metodo virtual sería la sgte*/
    virtual float aplicarEfectoEspecial(float valorBase,
                                        float tiempo);

     //sobreescribimos la calcular posicion para usar la velocidad ya reducida por el agua
    virtual float calcularPosicionX(float velocidad,
                                    float angulo,
                                    float tiempo);

    virtual float calcularPosicionY(float velocidad,
                                    float angulo,
                                    float tiempo);


};

#endif // FISICASUBMARINA_H
