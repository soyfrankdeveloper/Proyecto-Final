#ifndef AGENTEINTELIGENTE_H
#define AGENTEINTELIGENTE_H

#include "../entidades/Enemigo.h"
#include "../entidades/Jugador.h"

class AgenteInteligente
{
private:
    bool jugadorDetectado;
    bool proyectilCercano;

public:
    AgenteInteligente();

    void percibir(Jugador jugador);

    void decidir(Enemigo& enemigo);

    void actuar(Enemigo& enemigo);

    bool getJugadorDetectado();
};

#endif // AGENTEINTELIGENTE_H