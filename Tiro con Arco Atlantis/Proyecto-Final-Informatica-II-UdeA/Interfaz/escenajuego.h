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

    vector<QGraphicsPixmapItem*> proyectilesItems;
    vector<QGraphicsPixmapItem*> burbujasProyectiles;

    QTimer timer;

    Jugador jugador;

    QGraphicsTextItem* textoAngulo;

    QGraphicsPixmapItem* fondoItem;

    QGraphicsPixmapItem* burbujasItem;

    QGraphicsTextItem* textoNivel;

public:

    EscenaJuego(QObject *parent = nullptr);

    void inicializarEscena();

    void actualizarEscena();

    void sumarPuntos(int puntos);

    void keyPressEvent(QKeyEvent *event);

};

#endif // ESCENAJUEGO_H