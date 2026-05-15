#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Entidad.h"

class Personaje : public Entidad
{
protected:
    int vidas;
    int puntaje;

public:
    Personaje();

    void disparar();
    void recibirDanio(int danio);

    int getVidas();
    int getPuntaje();
};

#endif // PERSONAJE_H