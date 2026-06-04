#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
private:
    float x;
    float y;
    float velocidad;


public:
    Obstaculo();

    void actualizar();

    float getX();
    float getY();

    bool fueraDePantalla();

    bool verificarColision(float px,
                           float py);
};

#endif