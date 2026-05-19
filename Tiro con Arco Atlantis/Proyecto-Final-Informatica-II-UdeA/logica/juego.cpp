#include "juego.h"

Juego::Juego()
{

}

void Juego::iniciarJuego()
{
    jugador.setPosicion(0, 0);

    enemigo.setPosicion(100, 0);
}

void Juego::crearProyectil(float velocidad,
                           float angulo)
{
    Proyectil* nuevoProyectil;

    nuevoProyectil = new Proyectil();

    nuevoProyectil->lanzar(velocidad, angulo);

    proyectiles.push_back(nuevoProyectil);
}

void Juego::actualizarJuego()
{
    for(unsigned int i = 0; i < proyectiles.size(); i++)
    {
        proyectiles[i]->actualizar();
    }
}

int Juego::cantidadProyectiles()
{
    return proyectiles.size();
}