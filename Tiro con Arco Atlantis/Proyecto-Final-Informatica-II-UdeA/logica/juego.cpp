#include "juego.h"

Juego::Juego()
{
    turnoJugador = true;

    enemigoYaDisparo = false;

    vidasJugador = 3;

    nivelActual = new Nivel2();
}


Juego::~Juego()
{
    for(unsigned int i = 0;
         i < proyectiles.size();
         i++)
    {
        delete proyectiles[i];
    }

    for(unsigned int i = 0;
         i < obstaculos.size();
         i++)
    {
        delete obstaculos[i];
    }

    delete nivelActual;
}

void Juego::iniciarJuego()
{

    jugador.setPosicion(100, 200);

    enemigo.setPosicion(800,200);
}

void Juego::crearProyectil(float velocidad,
                           float angulo,
                           bool delJugador)
{
    Proyectil* nuevoProyectil;

    nuevoProyectil = new Proyectil();

    nuevoProyectil->setFisica(
        nivelActual->crearFisica());

    if(delJugador)
    {
        nuevoProyectil->lanzar(
            velocidad,
            angulo,
            jugador.getX() + 25,
            jugador.getY() + 25);
    }
    else
    {
        nuevoProyectil->lanzar(
            velocidad,
            angulo,
            enemigo.getX() + 25,
            enemigo.getY() + 25);
    }

    nuevoProyectil->setDelJugador(
        delJugador);

    proyectiles.push_back(
        nuevoProyectil);

    if(delJugador)
    {
        turnoJugador = false;
    }
}

void Juego::dispararEnemigo()
{
    if(proyectiles.size() > 0)
    {
        return;
    }

    crearProyectil(
        agenteIA.getPotenciaDisparo(),
        agenteIA.getAnguloDisparo(),
        false);
}

void Juego::actualizarJuego()
{
    for(int i = 0; i < proyectiles.size(); i++)
    {
        proyectiles[i]->actualizar();

        bool proyectilEliminado = false;

        for(unsigned int j = 0;
             j < obstaculos.size();
             j++)
        {
            if(obstaculos[j]->verificarColision(
                    proyectiles[i]->getX(),
                    proyectiles[i]->getY()))
            {
                delete proyectiles[i];

                proyectiles.erase(
                    proyectiles.begin() + i);

                proyectilEliminado = true;

                break;
            }
        }

        if(proyectilEliminado)
        {
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

        if(proyectiles[i]->getY() < 0 ||
            proyectiles[i]->getX() > 1200 ||
            proyectiles[i]->getX() < -200)
        {
            if(!proyectiles[i]->getDelJugador())
            {
                agenteIA.registrarFallo();
            }

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

                jugador.sumarPuntos(100);

                delete proyectiles[i];

                proyectiles.erase(
                    proyectiles.begin() + i);

                turnoJugador = false;

                dispararEnemigo();

                enemigoYaDisparo = true;

                i--;

                continue;
            }
        }

        else
        {

            if(proyectiles[i]->verificarColision(
                    jugador.getX(),
                    jugador.getY()))
            {
                if(vidasJugador > 0)
                {
                    vidasJugador--;
                }

                delete proyectiles[i];

                proyectiles.erase(
                    proyectiles.begin() + i);

                turnoJugador = true;
                enemigoYaDisparo = false;

                i--;
                continue;
            }
        }
    }

    agenteIA.percibir(jugador);

    agenteIA.decidir(enemigo);

    agenteIA.actuar(enemigo);

    static int contador = 0;

    contador++;


    if(contador >= 100)
    {
        if(obstaculos.size() < 5)
        {
            obstaculos.push_back(
                new Obstaculo());
        }

        contador = 0;
    }

    for(unsigned int i = 0;
         i < obstaculos.size();
         i++)
    {
        obstaculos[i]->actualizar();

        if(obstaculos[i]->fueraDePantalla())
        {
            delete obstaculos[i];

            obstaculos[i] =
                new Obstaculo();
        }
    }

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

int Juego::getPuntajeJugador()
{
    return jugador.getPuntaje();
}

vector<Obstaculo*>& Juego::getObstaculos()
{
    return obstaculos;
}





