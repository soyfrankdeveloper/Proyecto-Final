#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

class Enemigo : public Personaje

{
private:
    bool moviendo;
    float tiempoMovimiento;
    float posicionBase;

public:
    Enemigo();

    void tomarDecision();
    void esquivar();

    bool getMoviendo();

    void actualizarMovimiento();
};

#endif // ENEMIGO_H