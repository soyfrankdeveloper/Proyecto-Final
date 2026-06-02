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
            600 - proyectiles[i]->getY(),
            20,
            5);
    }

    textoVidaEnemigo->setPlainText(
        "Vida enemigo: " +
        QString::number(
            juego.getVidasEnemigo()));

    if(juego.getVidasEnemigo() <= 0)
    {
        enemigoItem->hide();

        textoVictoria->setPlainText(
            "¡VICTORIA!");
    }
}

void EscenaJuego::inicializarEscena()
{
    juego.iniciarJuego();

    setSceneRect(0,0,1000,600);

    jugadorItem = addRect(100,400,50,50);

    enemigoItem = addRect(800, 400,50,50);

    textoVictoria = addText("");

    textoVictoria->setPos(400,200);


    jugador.apuntar(45);

    textoAngulo = addText("Angulo: 45");

    textoAngulo->setPos(20,20);

    textoPotencia = addText("Potencia: 30");

    textoPotencia->setPos(20,50);

    textoVidaEnemigo = addText("Vida enemigo: 3");

    textoVidaEnemigo->setPos(20,80);
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
        if(juego.getTurnoJugador())
        {
            juego.crearProyectil(
                jugador.getPotencia(),
                jugador.getAngulo(),
                true);
        }
    }

    if(event->key() == Qt::Key_Right)
    {
        jugador.setPotencia(
            jugador.getPotencia() + 5);
    }

    if(event->key() == Qt::Key_Left)
    {
        if(jugador.getPotencia() >= 10)
        {
            jugador.setPotencia(
                jugador.getPotencia() - 5);
        }
    }

    textoAngulo->setPlainText(
        "Angulo: " +
        QString::number(jugador.getAngulo()));

    textoPotencia->setPlainText(
        "Potencia: " +
        QString::number(jugador.getPotencia()));

}

