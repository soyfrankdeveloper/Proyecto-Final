#ifndef PROYECTIL_H
#define PROYECTIL_H

#include "entidad.h"

class Proyectil : public Entidad


{
private:
    float angulo;
    float velocidadInicial;
    float tiempo;

public:
    Proyectil();

    void lanzar(float velocidadInicial, float angulo);

    void actualizar();

    float getAngulo();
    float getVelocidadInicial();
};

#endif // PROYECTIL_H