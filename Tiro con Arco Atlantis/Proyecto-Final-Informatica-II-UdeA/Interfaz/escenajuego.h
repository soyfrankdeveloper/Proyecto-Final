#ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H

#include <QGraphicsScene>

class EscenaJuego : public QGraphicsScene
{
    Q_OBJECT

public:
    EscenaJuego(QObject *parent = nullptr);

    void inicializarEscena();
};

#endif // ESCENAJUEGO_H