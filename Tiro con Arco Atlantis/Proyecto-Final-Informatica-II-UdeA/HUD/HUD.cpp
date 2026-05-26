#include "HUD.h"

HUD::HUD() {
    vidas =3;
    puntaje=0;
}
void HUD::mostrar()
{

}
void HUD::actualizar(int nuevasVidas, int nuevoPuntaje)
{
    vidas=nuevasVidas;
    puntaje=nuevoPuntaje;
}
