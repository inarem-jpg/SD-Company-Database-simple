#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include "sensores.h"

class AirQuality : public Sensor {
public:
    AirQuality() : valorActual(0.0f) {}

    void medirCalidad(float valor); // Guarda un único valor
    void imprimirDatos() const; // Imprime el valor 

private:
    float valorActual; // Valor actual del sensor
};

#endif

