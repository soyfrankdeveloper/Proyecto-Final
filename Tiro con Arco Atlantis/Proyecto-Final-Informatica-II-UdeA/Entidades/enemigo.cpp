#include "enemigo.h"
#include <cmath>
#include <cstdlib>

Enemigo::Enemigo()

{
    moviendo = false;
    tiempoMovimiento = 0;
    posicionBase = 800;
    dirX = 1.0f;
    dirY = 1.0f;
    contadorCambio = 0;

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
    tiempoMovimiento += 0.02;
    contadorCambio++;

    if(contadorCambio >=60)
    {
        contadorCambio =0;
        dirX =(float)(rand()%201-100)/100.0f;
        dirY =(float)(rand()%201-100)/100.0f;
    }
    x +=dirX*2.5f;
    y +=dirY*2.5f;

    // //hacemos que el enemigo nos persiga levemente
    // float dx=jugadorX-x;
    // float dy=jugadorY-y;
    // float distancia = sqrt(dx*dx + dy*dy);   //aplicamos algo de pitagoras

    // if(distancia >80)
    // {
    //     x +=(dx/distancia)*1.2f;
    //     y +=(dy/distancia)*1.2f;
    // }
    // //le damos una oscilacion encima del movimiento base
    // x +=25*sin(tiempoMovimiento*1.3f);
    // y +=20*cos(tiempoMovimiento*0.7f);

    //le colocamos unos limites o bordes al mapa en lvl 2
    if(x<500){x=500;
        dirX=fabs(dirX);
    }
    if(x>880){x=880;
        dirX= -fabs(dirX);
    }
    if(y<50){y=50;
        dirY= fabs(dirY);
    }
    if(y>520){y=520;
        dirY= -fabs(dirY);
    }

    // x = posicionBase +
    //     150 * sin(tiempoMovimiento);

    // y = 200;
}
