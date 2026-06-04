#include "agenteinteligente.h"
#include <cmath>

AgenteInteligente::AgenteInteligente()
{
    jugadorDetectado = false;
    proyectilCercano = false;

    anguloDisparo = 135;

    potenciaDisparo = 50;

    posicionJugadorX = 0;

    disparosFallidos = 0;
}

void AgenteInteligente::percibir(Jugador jugador)
{
    posicionJugadorX =
        jugador.getX();

    jugadorDetectado = true;
}

void AgenteInteligente::decidir(
    Enemigo& enemigo)
{
    float distancia;

    distancia =
        enemigo.getX() -
        posicionJugadorX;

    if(distancia > 500)
    {
        potenciaDisparo =
            100 + disparosFallidos * 10;

        anguloDisparo =
            135 + disparosFallidos * 2;
    }

    else
    {
        potenciaDisparo = 130;
        anguloDisparo = 130;
    }
}

void AgenteInteligente::actuar(Enemigo& enemigo)
{

}

bool AgenteInteligente::getJugadorDetectado()
{
    return jugadorDetectado;
}

void AgenteInteligente::detectarProyectil(
    float proyectilX,
    float enemigoX)
{
    if(abs(proyectilX - enemigoX) < 100)
    {
        proyectilCercano = true;
    }
    else
    {
        proyectilCercano = false;
    }
}

float AgenteInteligente::getAnguloDisparo()
{
    return anguloDisparo;
}

float AgenteInteligente::getPotenciaDisparo()
{
    return potenciaDisparo;
}

void AgenteInteligente::registrarFallo()
{
    disparosFallidos++;

}
