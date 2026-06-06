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

    fondoNivel2Cargado = false;

    //aca inicializamos las animaciones :3
    frameJugador =0;
    frameEnemigo =0;
    contadorAnimacion=0;

    //cargamos los frames de las acciones que va a realizar el/los personajes

    for(int i =1; i<=6;i++)
        framesJugadorAtaque.append(
            QPixmap(QString(":/Sprites/Sprites acciones/ataque/ataque%1.png").arg(i)));

    for(int i =1; i<=6;i++)
        framesJugadorCorrer.append(
            QPixmap(QString(":/Sprites/Sprites acciones/correr/correr%1.png").arg(i)));

    for(int i =1; i<=4;i++)
        framesJugadorMorir.append(
            QPixmap(QString(":/Sprites/Sprites acciones/morir/morir%1.png").arg(i)));


    for(int i =1; i<=2;i++)
        framesEnemigoAtaque.append(
            QPixmap(QString(":/Sprites/Sprites acciones/ataqueenemigo/ataqueenemigo%1.png").arg(i)));


    for(int i =1; i<=6;i++)
        framesEnemigoCorrer.append(
            QPixmap(QString(":/Sprites/Sprites acciones/correrenemigo/correrenemigo%1.png").arg(i)));


    for(int i =1; i<=4;i++)
        framesEnemigoMorir.append(
            QPixmap(QString(":/Sprites/Sprites acciones/morirenemigo/morirenemigo%1.png").arg(i)));




    //ahora les declaramos un estado inicial
    animacionActualJugador = &framesJugadorCorrer;
    animacionActualEnemigo = &framesEnemigoCorrer;


}

void EscenaJuego::actualizarEscena()
{
    //le decimos que animacion usar segun su estado
    if(juego.getVidasJugador()<=0)
        animacionActualJugador =&framesJugadorMorir;
    else if (juego.getTurnoJugador()==false)
        animacionActualJugador=&framesJugadorAtaque;
    else
        animacionActualJugador=&framesJugadorCorrer;

    if(juego.getVidasEnemigo()<=0)
        animacionActualEnemigo=&framesEnemigoMorir;
    else
        animacionActualEnemigo=&framesEnemigoCorrer;


    //colocamos las animaciones por este lado
    contadorAnimacion++;
    if(contadorAnimacion>=6)//que cambie el frame cada 6ticks o 180ms
    {
        contadorAnimacion =0;       //inicializamos contador en cero

        //hacemos el avance del frame del jugador
        frameJugador =(frameJugador +1)%animacionActualJugador->size();
        jugadorItem->setPixmap(
            animacionActualJugador->at(frameJugador).scaled(
                200,200,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation));

        //avance del frame del enemigo
        frameEnemigo=(frameEnemigo +1)%animacionActualEnemigo->size();
        enemigoItem->setPixmap(
            animacionActualEnemigo->at(frameEnemigo).scaled(
                200,200,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation));


    }

    juego.actualizarJuego();

    if(juego.getNivel() == 2)
    {
        jugadorItem->setPos(
            juego.getJugadorX(),
            600 - juego.getJugadorY());
    }
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

    textoTiempo->setPlainText(
        "Tiempo: " +
        QString::number(
            juego.getTiempoNivel2()));

    if(juego.getNivel2Terminado())
    {
        textoVictoria->setPlainText(
            "FIN NIVEL 2");
    }

    if(juego.getNivel() == 2)
    {
        textoNivel->setPlainText(
            "Nivel 2: Abismo Oceánico");
    }

    if(juego.getNivel() == 2 &&
        !fondoNivel2Cargado)
    {
        QPixmap fondo2(
            ":/Sprites/Sprites Nivel 2/fondo.jpeg");

        fondoItem->setPixmap(
            fondo2.scaled(
                1000,
                600));

        // QPixmap jugador2(
        //     ":/Sprites/Sprites Nivel 2/jugador.png");

        // jugadorItem->setPixmap(
        //     jugador2.scaled(
        //         200,
        //         200));

        // QPixmap enemigo2(
        //     ":/Sprites/Sprites Nivel 2/enemigo.png");

        // enemigoItem->setPixmap(
        //     enemigo2.scaled(
        //         200,
        //         200));

        fondoNivel2Cargado = true;
    }



    if(juego.getTiempoNivel2() <= 0)
    {
        textoVictoria->setPlainText(
            "TIEMPO AGOTADO");
    }

    if(juego.getTiempoNivel2() <= 0)
    {
        if(juego.jugadorGanoNivel2())
        {
            textoVictoria->setPlainText(
                "GANASTE");
        }
        else
        {
            textoVictoria->setPlainText(
                "PERDISTE");
        }
    }

    //jugadorItem->setPos(
      //  jugador.getX(),
        //600 - jugador.getY());

}

void EscenaJuego::inicializarEscena()
{
    juego.iniciarJuego();

    setSceneRect(0,0,1000,600);

    QGraphicsTextItem* ayuda;

    ayuda = addText(
        "W/S/A/D mover\n"
        "Flechas ajustar\n"
        "Espacio disparar");

    ayuda->setPos(750,20);

    QPixmap fondo(
        ":/Sprites/Sprites Nivel 1/fondo.jpeg");

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

    textoTiempo =
        addText("Tiempo: 60");

    textoTiempo->setPos(
        20,
        200);
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

    if(juego.getNivel() == 2)
    {
        if(event->key() == Qt::Key_W)
        {
            juego.moverJugadorArriba();
        }

        if(event->key() == Qt::Key_S)
        {
            juego.moverJugadorAbajo();
        }

        if(event->key() == Qt::Key_A)
        {
            juego.moverJugadorIzquierda();
        }

        if(event->key() == Qt::Key_D)
        {
            juego.moverJugadorDerecha();
        }
    }

    textoAngulo->setPlainText(
        "Angulo: " +
        QString::number(jugador.getAngulo()));

    textoPotencia->setPlainText(
        "Potencia: " +
        QString::number(jugador.getPotencia()));

}

