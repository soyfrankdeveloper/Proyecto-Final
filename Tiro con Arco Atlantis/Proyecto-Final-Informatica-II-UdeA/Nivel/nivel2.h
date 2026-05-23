#ifndef NIVEL2_H
#define NIVEL2_H
#include "nivel.h"

class nivel2 : public Nivel
{
public:
    nivel2();
    void configurarCorrientes();
    void iniciarNivel();
    void actualizarNivel();
};

#endif // NIVEL2_H
