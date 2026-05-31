#include "juego.h"


Juego::Juego()
{

}

void Juego::iniciarJuego()
{
    jugador.setPosicion(150, 200);

    enemigo.setPosicion(800,100);
}

void Juego::crearProyectil(float velocidad,
                           float angulo)
{
    Proyectil* nuevoProyectil;

    nuevoProyectil = new Proyectil();

    nuevoProyectil->setPosicion(
        jugador.getX(),
        jugador.getY());

    nuevoProyectil->lanzar(
        velocidad,
        angulo,
        jugador.getX(),
        jugador.getY());

    proyectiles.push_back(
        nuevoProyectil);
}

void Juego::actualizarJuego()
{
    for(unsigned int i = 0; i < proyectiles.size(); i++)
    {
        proyectiles[i]->actualizar();

        if(proyectiles[i]->verificarColision(
                enemigo.getX(),
                enemigo.getY()))
        {

            enemigo.recibirDanio(1);

            delete proyectiles[i];

            proyectiles.erase(
                proyectiles.begin() + i);

            i--;
        }
    }


    agenteIA.percibir(jugador);

    agenteIA.decidir(enemigo);

    agenteIA.actuar(enemigo);
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


