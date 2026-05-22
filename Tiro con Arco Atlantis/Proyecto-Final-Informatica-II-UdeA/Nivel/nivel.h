#ifndef NIVEL_H
#define NIVEL_H

class Nivel
{
protected:
    int id;
    float gravedad;

public:
    Nivel();
    virtual void iniciarNivel();
    virtual void actualizarNivel();
    int getId();
    float getGravedad();
};

#endif // NIVEL_H
