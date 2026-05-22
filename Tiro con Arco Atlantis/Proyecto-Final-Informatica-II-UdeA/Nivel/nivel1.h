#ifndef NIVEL1_H
#define NIVEL1_H
#include "nivel.h"

class nivel1 : public Nivel
{
public:
    nivel1();
    void configurarFisica();
    void iniciarNivel();
    void actualizarNivel();
};

#endif // NIVEL1_H
