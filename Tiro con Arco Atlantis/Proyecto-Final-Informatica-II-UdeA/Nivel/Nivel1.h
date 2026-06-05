#ifndef NIVEL1_H
#define NIVEL1_H
#include "Nivel.h"
#include "../Fisica/fisicasubmarina.h"

class Nivel1 : public Nivel
{
public:
    Nivel1();
    void configurarFisica();
    void iniciarNivel();
    void actualizarNivel();
    virtual Fisica* crearFisica();
};

#endif // NIVEL1_H
