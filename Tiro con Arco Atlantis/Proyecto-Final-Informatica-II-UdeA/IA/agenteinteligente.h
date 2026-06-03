#ifndef AGENTEINTELIGENTE_H
#define AGENTEINTELIGENTE_H

#include "../entidades/Enemigo.h"
#include "../entidades/Jugador.h"

class AgenteInteligente
{
private:
    bool jugadorDetectado;
    bool proyectilCercano;
    float anguloDisparo;
    float potenciaDisparo;
    int disparosFallidos;


public:
    AgenteInteligente();

    void percibir(Jugador jugador);

    void decidir(Enemigo& enemigo);

    void actuar(Enemigo& enemigo);

    bool getJugadorDetectado();

    float getAnguloDisparo();

    float getPotenciaDisparo();

    float posicionJugadorX;

    void registrarFallo();

    void detectarProyectil(float proyectilX,
                           float enemigoX);
};

#endif // AGENTEINTELIGENTE_H