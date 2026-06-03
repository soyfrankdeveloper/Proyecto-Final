#ifndef PROYECTIL_H
#define PROYECTIL_H

#include "entidad.h"
#include "../Fisica/fisica.h"
#include "../Fisica/fisicasubmarina.h"

class Proyectil : public Entidad
{
private:
    float angulo;
    float velocidadInicial;
    float tiempo;

    Fisica* fisica;     //hice que apuntara a fisicasubmarina en tiempo de ejecucion

    float xInicial;
    float yInicial;

    bool delJugador;

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

    void setDelJugador(bool valor);

    bool getDelJugador();
};

#endif // PROYECTIL_H
