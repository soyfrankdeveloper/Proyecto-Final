#ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "../logica/juego.h"
#include "../entidades/obstaculo.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>

#include <vector>
#include <QTimer>

class EscenaJuego : public QGraphicsScene
{
private:

    QGraphicsPixmapItem* jugadorItem;

    QGraphicsPixmapItem* enemigoItem;

    QGraphicsTextItem* textoPotencia;

    QGraphicsTextItem* textoVidaEnemigo;

    QGraphicsTextItem* textoVictoria;

    QGraphicsTextItem* textoVidaJugador;

    QGraphicsTextItem* textoPuntaje;

    vector<QGraphicsPixmapItem*> obstaculosItems;

    Juego juego;

    Jugador jugador;
    vector<QGraphicsPixmapItem*> proyectilesItems;
    vector<QGraphicsPixmapItem*> burbujasProyectiles;

    QTimer timer;

    QGraphicsTextItem* textoAngulo;

    QGraphicsPixmapItem* fondoItem;

    QGraphicsPixmapItem* burbujasItem;

    QGraphicsTextItem* textoNivel;

    QGraphicsTextItem* textoTiempo;

    bool fondoNivel2Cargado;

    //agregamos las animaciones
    /*Nota: Qvector es un contenedor o cajita donde almacenamos QPixmap que es un tipo de
     dato que nos permite mostrar en pantalla una imagen cargada en memoria*/
    QVector<QPixmap> framesJugadorCorrer;
    QVector<QPixmap> framesJugadorAtaque;
    QVector<QPixmap> framesJugadorMorir;

    QVector<QPixmap> framesEnemigoCorrer;
    QVector<QPixmap> framesEnemigoAtaque;
    QVector<QPixmap> framesEnemigoMorir;


    /*Pd: tomamos la decicion de usar punteros para indicar que animacion del jugador/enemigo está activa
     de esta manera, el juego puede cambiar libremente entre diferentes animaciones según las acciones que
     estén realizando los personajes*/
    QVector<QPixmap>* animacionActualJugador;
    QVector<QPixmap>* animacionActualEnemigo;


    int frameJugador;
    int frameEnemigo;
    int contadorAnimacion;

    // int totalFramesJugador;
    // int totalFramesEnemigo;
    // QPixmap spriteSheetJugador;
    // QPixmap spriteSheetEnemigo;


public:

    EscenaJuego(QObject *parent = nullptr);

    void inicializarEscena();

    void actualizarEscena();

    void sumarPuntos(int puntos);

    void keyPressEvent(QKeyEvent *event);

};

#endif // ESCENAJUEGO_H
