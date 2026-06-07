#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

class Enemigo : public Personaje

{
private:
    bool moviendo;
    float tiempoMovimiento;
    float posicionBase;
    float dirX;
    float dirY;
    int contadorCambio;

public:
    Enemigo();

    void tomarDecision();
    void esquivar();

    bool getMoviendo();

    void actualizarMovimiento(
        float jugadorX, float jugadorY);
};

#endif // ENEMIGO_H
