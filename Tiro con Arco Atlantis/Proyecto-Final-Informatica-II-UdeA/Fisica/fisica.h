#ifndef FISICA_H
#define FISICA_H

class Fisica
{
protected:
    float gravedad;

public:
    Fisica();

    float calcularPosicionX(float velocidad, float angulo, float tiempo);

    float calcularPosicionY(float velocidad, float angulo, float tiempo);
};

#endif // FISICA_H