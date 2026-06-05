 #include "escenajuego.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>

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

    enemigoItem->setPos(
        juego.getEnemigoX(),
        600 - juego.getEnemigoY());

    vector<Proyectil*>& proyectiles =
        juego.getProyectiles();

    proyectiles = juego.getProyectiles();

    while(proyectilesItems.size() >
           proyectiles.size())
    {
        removeItem(
            proyectilesItems.back());

        delete proyectilesItems.back();

        proyectilesItems.pop_back();
    }

    while(proyectilesItems.size() < proyectiles.size())
    {
        QGraphicsPixmapItem* nuevoItem;

        QPixmap flechaSprite(
            ":/Sprites/Sprites Nivel 1/Flecha.png");

        nuevoItem =
            addPixmap(
                flechaSprite.scaled(
                    400,
                    160,
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation));

        nuevoItem->setTransformOriginPoint(
            nuevoItem->boundingRect().center());

        proyectilesItems.push_back(
            nuevoItem);
    }

    for(unsigned int i = 0; i < proyectiles.size(); i++)
    {
        proyectilesItems[i]->setPos(
            proyectiles[i]->getX(),
            600 - proyectiles[i]->getY());


        proyectilesItems[i]->setRotation(
            -proyectiles[i]->getAnguloActual());
    }

    textoVidaEnemigo->setPlainText(
        "Vida enemigo: " +
        QString::number(
            juego.getVidasEnemigo()));

    textoPuntaje->setPlainText(
        "Puntaje: " +
        QString::number(
            juego.getPuntajeJugador()));

    textoVidaJugador->setPlainText(
        "Vida jugador: " +
        QString::number(
            juego.getVidasJugador()));



    if(juego.getVidasEnemigo() <= 0)
    {
        enemigoItem->hide();

        textoVictoria->setPlainText(
            "¡VICTORIA!");

        textoVictoria->setDefaultTextColor(
            Qt::green);

        textoVictoria->setScale(3);
    }

    if(juego.getVidasJugador() <= 0)
    {
        jugadorItem->hide();

        textoVictoria->setPlainText(
            "DERROTA");

        textoVictoria->setDefaultTextColor(
            Qt::red);

        textoVictoria->setScale(3);
    }

    vector<Obstaculo*>& obstaculos =
        juego.getObstaculos();

    while(obstaculosItems.size() >
           obstaculos.size())
    {
        removeItem(
            obstaculosItems.back());

        delete obstaculosItems.back();

        obstaculosItems.pop_back();
    }

    while(obstaculosItems.size() <
           obstaculos.size())
    {
        QGraphicsPixmapItem* nuevo;

        QPixmap obstaculoSprite(
            ":/Sprites/Sprites Nivel 1/obstaculo.png");

        nuevo =
            addPixmap(
                obstaculoSprite.scaled(
                    50,
                    50,
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation));

        obstaculosItems.push_back(
            nuevo);
    }

    for(unsigned int i = 0;
         i < obstaculos.size();
         i++)
    {
        obstaculosItems[i]->setPos(
            obstaculos[i]->getX(),
            600 - obstaculos[i]->getY());
    }

}

void EscenaJuego::inicializarEscena()
{
    juego.iniciarJuego();

    setSceneRect(0,0,1000,600);

    QPixmap fondo(
        ":/Sprites/Sprites Nivel 1/fondo.png");

    fondoItem = addPixmap(
        fondo.scaled(
            1000,
            600));

    fondoItem->setZValue(-100);

    QPixmap jugadorSprite(
        ":/Sprites/Sprites Nivel 1/jugador.png");

    jugadorItem =
        addPixmap(
            jugadorSprite.scaled(
                200,
                200));

    jugadorItem->setPos(
        100,
        400);

    QPixmap enemigoSprite(
        ":/Sprites/Sprites Nivel 1/enemigo.png");

    enemigoItem =
        addPixmap(
            enemigoSprite.scaled(
                200,
                200));

    enemigoItem->setPos(
        800,
        400);

    textoVictoria = addText("");

    textoVictoria->setPos(400,200);


    jugador.apuntar(45);

    textoAngulo = addText("Angulo: 45");

    textoAngulo->setPos(20,20);

    textoPotencia = addText("Potencia: 30");

    textoPotencia->setPos(20,50);

    textoVidaEnemigo = addText("Vida enemigo: 3");

    textoNivel = addText(
        "Nivel: Atlantis");

    textoNivel->setPos(
        20,
        170);

    textoVidaEnemigo->setPos(20,80);

    textoPuntaje = addText("Puntaje: 0");

    textoPuntaje->setPos(20,140);

    textoVidaJugador = addText(
        "Vida jugador: 3");

    textoVidaJugador->setPos(
        20,
        110);
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

