#ifndef HUMIDITYSENS_H
#define HUMIDITYSENS_H

#include "sensores.h"

class SensorHumedad : public Sensor {
public:
    SensorHumedad();                     // Constructor
    void medirHumedad(float valor);      // Método para medir humedad
    void imprimirDatos() const;          // Método para imprimir datos
private:
    float valorHumedad;                  // Valor actual de humedad
};

#endif

