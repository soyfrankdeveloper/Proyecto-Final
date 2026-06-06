#include "enemigo.h"
#include <cmath>

Enemigo::Enemigo()

{
    moviendo = false;
    tiempoMovimiento = 0;
    posicionBase = 800;
}

void Enemigo::tomarDecision()

{
    moviendo = true;
}

void Enemigo::esquivar()

{
    x += 5;
}

bool Enemigo::getMoviendo()

{
    return moviendo;
}

void Enemigo::actualizarMovimiento(
    float jugadorX,
    float jugadorY)
{
    tiempoMovimiento += 0.03;

    //hacemos que el enemigo nos persiga levemente
    float dx=jugadorX-x;
    float dy=jugadorY-y;
    float distancia = sqrt(dx*dx + dy*dy);   //aplicamos algo de pitagoras

    if(distancia >80)
    {
        x +=(dx/distancia)*1.2f;
        y +=(dy/distancia)*1.2f;
    }
    //le damos una oscilacion encima del movimiento base
    x +=10*sin(tiempoMovimiento);
    y +=10*cos(tiempoMovimiento);

    //le colocamos unos limites o bordes al mapa en lvl 2
    if(x<500)x=500;
    if(x>900)x=900;
    if(y<50)y=50;
    if(y>500)y=500;

    // x = posicionBase +
    //     150 * sin(tiempoMovimiento);

    // y = 200;
}
