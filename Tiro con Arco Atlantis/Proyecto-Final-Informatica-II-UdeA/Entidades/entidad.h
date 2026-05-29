#ifndef ENTIDAD_H
#define ENTIDAD_H

class Entidad

{
protected:
    float x;
    float y;
    float velocidad;

    float ancho;
    float alto;

public:
    Entidad();

    void setPosicion(float x, float y);

    float getX();
    float getY();

    void mover();
};

#endif // ENTIDAD_H