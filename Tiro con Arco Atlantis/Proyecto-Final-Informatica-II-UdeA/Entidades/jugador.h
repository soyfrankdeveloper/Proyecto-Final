#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

class Jugador : public Personaje

{
private:
    float angulo;

public:
    Jugador();

    void apuntar(float angulo);

    float getAngulo();
};

#endif // JUGADOR_H