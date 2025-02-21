#ifndef SENSORLUZ_H
#define SENSORLUZ_H

#include "sensores.h"

class SensorLuz : public Sensor {
public:
    SensorLuz() : valorActual(0.0f) {}

    void medirLuz(float valor); // Guarda un único valor
    void imprimirDatos() const; // Imprime el valor 

private:
    float valorActual; // Valor actual del sensor 
};

#endif

