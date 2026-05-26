#ifndef NIVEL_H
#define NIVEL_H

class Nivel
{
protected:
    int id;
    float gravedad;

public:
    Nivel();
    void iniciarNivel();
    void actualizarNivel();
    int getId();
    float getGravedad();
};

#endif // NIVEL_H
