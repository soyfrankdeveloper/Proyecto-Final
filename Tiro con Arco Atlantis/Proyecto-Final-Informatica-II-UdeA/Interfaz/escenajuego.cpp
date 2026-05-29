#include "escenajuego.h"
#include <QGraphicsRectItem>

EscenaJuego::EscenaJuego(QObject *parent)
    : QGraphicsScene(parent)
{
    connect(&timer,
            &QTimer::timeout,
            this,
            &EscenaJuego::actualizarEscena);

    timer.start(30);
}

void EscenaJuego::actualizarEscena()
{
    juego.actualizarJuego();

    vector<Proyectil*>& proyectiles =
        juego.getProyectiles();

    proyectiles = juego.getProyectiles();

    while(proyectilesItems.size() < proyectiles.size())
    {
        QGraphicsRectItem* nuevoItem;

        nuevoItem = addRect(0,0,20,5);

        proyectilesItems.push_back(nuevoItem);
    }

    for(unsigned int i = 0; i < proyectiles.size(); i++)
    {
        proyectilesItems[i]->setRect(
            proyectiles[i]->getX(),
            500 - proyectiles[i]->getY(),
            20,
            5);
    }
}

void EscenaJuego::inicializarEscena()
{
    setSceneRect(0,0,1000,600);

    jugadorItem = addRect(100,400,50,50);

    enemigoItem = addRect(800,400,50,50);

    jugador.apuntar(45);

    textoAngulo = addText("Angulo: 45");

    textoAngulo->setPos(20,20);
}

void EscenaJuego::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        if(jugador.getAngulo() < 90)
        {
            jugador.apuntar(
                jugador.getAngulo() + 5);
        }
    }

    if(event->key() == Qt::Key_Down)
    {
        if(jugador.getAngulo() > 0)
        {
            jugador.apuntar(
                jugador.getAngulo() - 5);
        }
    }

    if(event->key() == Qt::Key_Space)
    {
        juego.crearProyectil(
            30,
            jugador.getAngulo());
    }

    textoAngulo->setPlainText(
        "Angulo: " +
        QString::number(jugador.getAngulo()));
}

