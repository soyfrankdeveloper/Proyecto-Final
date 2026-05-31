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

    float xInicial;
    float yInicial;

public:
    Proyectil();

    void lanzar(float nuevaVelocidad,
                float nuevoAngulo,
                float nuevaX,
                float nuevaY);

    void actualizar();

    bool verificarColision(float objetivoX,
                           float objetivoY);

    float getAngulo();
    float getVelocidadInicial();
};

#endif // PROYECTIL_H