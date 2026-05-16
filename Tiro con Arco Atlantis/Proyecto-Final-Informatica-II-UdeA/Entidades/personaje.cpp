#include "personaje.h"

Personaje::Personaje()

{
    vidas = 3;
    puntaje = 0;
}

void Personaje::disparar()

{

}

void Personaje::recibirDanio(int danio)

{
    vidas -= danio;

    if (vidas < 0)
    {
        vidas = 0;
    }
}

int Personaje::getVidas()

{
    return vidas;
}

int Personaje::getPuntaje()

{
    return puntaje;
}