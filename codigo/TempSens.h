#ifndef TEMPSENS_H
#define TEMPSENS_H

#include "sensores.h"

class SensorTemp : public Sensor {
public:
    SensorTemp() : valorActual(0.0f) {}

    void medirTemp(float valor); // Guarda un único valor 
    void imprimirDatos() const; // Imprime el valor 

private:
    float valorActual; // Valor actual del sensor 
};

#endif

