#ifndef JUEGO_H
#define JUEGO_H

#include <vector>

#include "../entidades/jugador.h"
#include "../entidades/enemigo.h"
#include "../entidades/proyectil.h"

using namespace std;

class Juego
{
private:
    Jugador jugador;
    Enemigo enemigo;

    vector<Proyectil*> proyectiles;

public:
    Juego();

    void iniciarJuego();

    void crearProyectil(float velocidad,
                        float angulo);

    void actualizarJuego();

    int cantidadProyectiles();
};

#endif // JUEGO_H