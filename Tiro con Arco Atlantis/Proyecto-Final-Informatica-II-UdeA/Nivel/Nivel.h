#ifndef NIVEL_H
#define NIVEL_H

#include "../Fisica/fisica.h"

class Nivel
{
protected:
    int id;
    float gravedad;


public:
    Nivel();
    void iniciarNivel();
    void actualizarNivel();
    int getId();
    float getGravedad();
    virtual Fisica* crearFisica();
};

#endif // NIVEL_H
