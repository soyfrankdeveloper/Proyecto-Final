#include "juego.h"

Juego::Juego()
{
    turnoJugador = true;

    enemigoYaDisparo = false;

    vidasJugador = 3;
}

void Juego::iniciarJuego()
{
    jugador.setPosicion(150, 200);

    enemigo.setPosicion(800,100);
}

void Juego::crearProyectil(float velocidad,
                           float angulo,
                           bool delJugador)
{
    Proyectil* nuevoProyectil;

    nuevoProyectil = new Proyectil();

    if(delJugador)
    {
        nuevoProyectil->lanzar(
            velocidad,
            angulo,
            jugador.getX(),
            jugador.getY());
    }
    else
    {
        nuevoProyectil->lanzar(
            velocidad,
            angulo,
            enemigo.getX(),
            enemigo.getY());
    }

    nuevoProyectil->setDelJugador(
        delJugador);

    proyectiles.push_back(
        nuevoProyectil);
}

void Juego::dispararEnemigo()
{
    crearProyectil(
        50,
        135,
        false);
}

void Juego::actualizarJuego()
{
    for(unsigned int i = 0; i < proyectiles.size(); i++)
    {
        proyectiles[i]->actualizar();

        if(proyectiles[i]->getY() < 0)
        {
            delete proyectiles[i];

            proyectiles.erase(
                proyectiles.begin() + i);

            if(!enemigoYaDisparo)
            {
                dispararEnemigo();

                enemigoYaDisparo = true;
            }
            else
            {
                turnoJugador = true;

                enemigoYaDisparo = false;
            }

            i--;

            continue;
        }

        if(proyectiles[i]->getDelJugador())
        {
            if(proyectiles[i]->verificarColision(
                    enemigo.getX(),
                    enemigo.getY()))
            {
                enemigo.recibirDanio(1);

                delete proyectiles[i];

                proyectiles.erase(
                    proyectiles.begin() + i);

                turnoJugador = true;

                i--;
            }
        }
    }

    agenteIA.percibir(jugador);

    agenteIA.decidir(enemigo);

    agenteIA.actuar(enemigo);
}



bool Juego::getTurnoJugador()
{
    return turnoJugador;
}


int Juego::cantidadProyectiles()
{
    return proyectiles.size();
}

vector<Proyectil*>& Juego::getProyectiles()
{
    return proyectiles;
}

int Juego::getVidasEnemigo()
{
    return enemigo.getVidas();
}

float Juego::getEnemigoX()
{
    return enemigo.getX();
}

float Juego::getEnemigoY()
{
    return enemigo.getY();
}

int Juego::getVidasJugador()
{
    return vidasJugador;
}


