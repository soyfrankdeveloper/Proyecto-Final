#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

class Enemigo : public Personaje

{
private:
    bool moviendo;

public:
    Enemigo();

    void tomarDecision();
    void esquivar();

    bool getMoviendo();
};

#endif // ENEMIGO_H