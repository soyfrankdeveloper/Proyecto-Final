#ifndef HUD_H
#define HUD_H

class HUD
{
private:
    int vidas;
    int puntaje;

public:
    HUD();
    void mostrar();
    void actualizar(int nuevasVidas, int nuevoPuntaje);

};

#endif // HUD_H
