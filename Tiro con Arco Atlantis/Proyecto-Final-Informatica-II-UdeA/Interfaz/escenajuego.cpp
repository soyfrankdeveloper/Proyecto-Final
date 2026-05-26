#include "escenajuego.h"

EscenaJuego::EscenaJuego(QObject *parent)
    : QGraphicsScene(parent)
{

}

void EscenaJuego::inicializarEscena()
{
    setSceneRect(0, 0, 1000, 600);
    addText("Atlantis Archery");
}