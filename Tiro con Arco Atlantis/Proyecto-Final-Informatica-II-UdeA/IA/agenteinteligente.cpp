#include "agenteinteligente.h"

AgenteInteligente::AgenteInteligente()
{
    jugadorDetectado = false;
    proyectilCercano = false;
}

void AgenteInteligente::percibir(Jugador jugador)
{
    if(jugador.getX() >= 0)
    {
        jugadorDetectado = true;
    }
}

void AgenteInteligente::decidir(Enemigo& enemigo)
{
    if(jugadorDetectado)
    {
        enemigo.tomarDecision();
    }
}

void AgenteInteligente::actuar(Enemigo& enemigo)
{
    if(proyectilCercano)
    {
        enemigo.esquivar();
    }
}

bool AgenteInteligente::getJugadorDetectado()
{
    return jugadorDetectado;
}