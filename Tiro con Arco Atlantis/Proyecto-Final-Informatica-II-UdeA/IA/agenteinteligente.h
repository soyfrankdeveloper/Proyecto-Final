#ifndef AGENTEINTELIGENTE_H
#define AGENTEINTELIGENTE_H

#include "../entidades/Enemigo.h"
#include "../entidades/Jugador.h"

#include <cstdlib>      //para poder usar rand()

class AgenteInteligente
{
private:
    bool jugadorDetectado;
    bool proyectilCercano;
    float anguloDisparo;
    float potenciaDisparo;
    int disparosFallidos;
    float variacionAngulo;      //variacion aleatoria del angulo de disparo enemigo
    float variacionPotencia;    //variacion aleatoria de la potencia de disparo enemigo


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

    void calcularVariacion();   //para la nueva variacion de manera aleatoria
};

#endif // AGENTEINTELIGENTE_H
