#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

class Jugador : public Personaje

{
private:
    float angulo;
    float potencia;

public:
    Jugador();

    void apuntar(float angulo);

    float getAngulo();

    void setPotencia(float potencia);

    float getPotencia();
};

#endif // JUGADOR_H