#ifndef FISICA_H
#define FISICA_H

class Fisica
{
protected:
    float gravedad;

public:
    Fisica();
    //aplicamos un virtual para permitir que la hija sobreescriba comportamiento

    virtual float calcularPosicionX(float velocidad, float angulo, float tiempo);

    virtual float calcularPosicionY(float velocidad, float angulo, float tiempo);

    /*obligao toca meter el metodo virtual para poder implementar el polimorfismo dinamico, la otra manera
    sería usando polimorfismo estatico, sería más voleo pq tocaria usar sobrecargas o plantillas*/
    virtual float aplicarEfectoEspecial(float valorBase, float tiempo);
};

#endif // FISICA_H
