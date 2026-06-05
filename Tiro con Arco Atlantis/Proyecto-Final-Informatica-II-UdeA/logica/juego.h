#ifndef JUEGO_H
#define JUEGO_H

#include <vector>

#include "../entidades/jugador.h"
#include "../entidades/enemigo.h"
#include "../entidades/proyectil.h"
#include "../entidades/obstaculo.h"
#include "../Nivel/Nivel.h"
#include "../Nivel/Nivel1.h"
#include "../Nivel/Nivel2.h"

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

    vector<Obstaculo*> obstaculos;

    Nivel* nivelActual;


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

    int getPuntajeJugador();

    vector<Obstaculo*>& getObstaculos();

    ~Juego();
};

#endif // JUEGO_H