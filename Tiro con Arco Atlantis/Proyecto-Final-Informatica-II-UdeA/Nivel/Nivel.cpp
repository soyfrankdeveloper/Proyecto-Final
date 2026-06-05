#include "Nivel.h"

Nivel::Nivel() {
    id=0;
    gravedad=9.8;
}
void Nivel::iniciarNivel()
{

}
void Nivel::actualizarNivel()
{

}

int Nivel::getId()
{
    return id;
}
float Nivel::getGravedad()
{
    return gravedad;
}

Fisica* Nivel::crearFisica()
{
    return new Fisica();
}