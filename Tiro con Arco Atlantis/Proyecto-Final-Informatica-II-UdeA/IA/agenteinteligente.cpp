#include "agenteinteligente.h"
#include <cmath>
#include <cstdlib>
#include <ctime>


AgenteInteligente::AgenteInteligente()
{
    jugadorDetectado = false;
    proyectilCercano = false;

    anguloDisparo = 135;

    potenciaDisparo = 50;

    posicionJugadorX = 0;

    disparosFallidos = 0;

    variacionAngulo = 0;        //inicializamos la variacion de angulo en 0

    variacionPotencia = 0;      //inicializamos la variacion de potencia en 0

    srand(time(0));     //inicializamos con time pq el rand solito nos da siempre la misma secuencia, el ctime cambia cada segundo, xd
}

/*generamos una variacion aleatoria*/
void AgenteInteligente::calcularVariacion()
{
    variacionAngulo=(rand()%31)-15;
    variacionPotencia =(rand()%41)-20;
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
    float distancia =
        enemigo.getX() -
        posicionJugadorX;

    //le pedimos que calcule una nueva variacion para cada disparo
    int rangoVariacion=15-disparosFallidos*2;
    if(rangoVariacion<3) rangoVariacion=3;

    variacionAngulo =(rand()%(rangoVariacion*2+1))-rangoVariacion;
    variacionPotencia= (rand()%(rangoVariacion*2+1))-rangoVariacion;

    if(distancia > 500)
    {
        //lejos del jugaror va ajustando con fallidos + variacion
        potenciaDisparo =
            100 + disparosFallidos * 8+
        variacionPotencia;

        anguloDisparo =
            135 + disparosFallidos * 2+
        variacionAngulo;
    }

    else
    {
        /*cerca del jugador lo ponemos mas preciso pero con variaciones
        la variacion se reduce a la mitad para que tenga mayor dificultad
        */
        potenciaDisparo = 120+ disparosFallidos*5+variacionPotencia;
        anguloDisparo = 132+variacionAngulo;
    }
    //le pedimos que el angulo no pueda salirse dentro de los rangos logicos
    if(anguloDisparo <100)anguloDisparo=100;
    if(anguloDisparo>170)anguloDisparo=170;

    //la potencia tampoco puede ser negativa o absurda
    if(potenciaDisparo<50) potenciaDisparo=50;
    if(potenciaDisparo>200)potenciaDisparo=200;
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
