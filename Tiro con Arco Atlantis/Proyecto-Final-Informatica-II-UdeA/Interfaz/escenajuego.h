#ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "../logica/juego.h"

#include <vector>
#include <QTimer>

class EscenaJuego : public QGraphicsScene
{
private:

    QGraphicsRectItem* jugadorItem;

    QGraphicsRectItem* enemigoItem;

    Juego juego;

    vector<QGraphicsRectItem*> proyectilesItems;

    QTimer timer;

    Jugador jugador;

    QGraphicsTextItem* textoAngulo;

public:

    EscenaJuego(QObject *parent = nullptr);

    void inicializarEscena();

    void actualizarEscena();

    void keyPressEvent(QKeyEvent *event);

};

#endif // ESCENAJUEGO_H