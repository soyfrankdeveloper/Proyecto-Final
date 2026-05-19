#ifndef PROYECTIL_H
#define PROYECTIL_H

#include "entidad.h"
#include "../Fisica/fisica.h"

class Proyectil : public Entidad
{
private:
    float angulo;
    float velocidadInicial;
    float tiempo;

    Fisica fisica;

public:
    Proyectil();

    void lanzar(float nuevaVelocidad,
                float nuevoAngulo);

    void actualizar();

    float getAngulo();
    float getVelocidadInicial();
};

#endif // PROYECTIL_H