#ifndef NIVEL2_H
#define NIVEL2_H

#include "Nivel.h"
#include "../Fisica/FisicaCorriente.h"

class Nivel2 : public Nivel
{
public:
    Nivel2();

    void configurarCorrientes();

    void iniciarNivel();

    void actualizarNivel();

    virtual Fisica* crearFisica();
};

#endif // NIVEL2_H