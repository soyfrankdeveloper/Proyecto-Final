#include "Nivel2.h"

Nivel2::Nivel2() {
    id=2;
    gravedad=5.0;
}
void Nivel2::configurarCorrientes()
{
    gravedad=5.0;
}
void Nivel2::iniciarNivel()
{
    configurarCorrientes();
}
void Nivel2::actualizarNivel()
{

}

Fisica* Nivel2::crearFisica()
{
    return new FisicaCorriente();
}