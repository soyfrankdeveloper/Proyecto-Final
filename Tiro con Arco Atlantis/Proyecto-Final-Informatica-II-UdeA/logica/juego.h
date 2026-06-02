#ifndef JUEGO_H
#define JUEGO_H

#include <vector>

#include "../entidades/jugador.h"
#include "../entidades/enemigo.h"
#include "../entidades/proyectil.h"

#include "../IA/agenteinteligente.h"

using namespace std;

class Juego
{
private:
    Jugador jugador;

    Enemigo enemigo;

    AgenteInteligente agenteIA;

    vector<Proyectil*> proyectiles;

    bool turnoJugador;

    bool enemigoYaDisparo;

    int vidasJugador;

public:

    Juego();

    void iniciarJuego();

    void crearProyectil(float velocidad,
                        float angulo,
                        bool delJugador);

    void actualizarJuego();

    int cantidadProyectiles();

    vector<Proyectil*>& getProyectiles();

    int getVidasEnemigo();

    float getEnemigoX();
    float getEnemigoY();

    bool getTurnoJugador();

    int getVidasJugador();

    void dispararEnemigo();
};

#endif // JUEGO_H