
#ifndef SENSORES_H
#define SENSORES_H

#include <iostream>
#include <string>

class Sensor {
public:
    Sensor() : next(nullptr) {} // Inicialización de un puntero "next"

    void agregarSensor(int nuevoSensor); // funcionpara agregar un sensor
    void imprimirSensores() const;       // funcion para imprimir sensores

protected:
    static const int maxSensores = 128;  // cantida límite de sensores
    int misSensores[maxSensores]; // array de sensores
    Sensor* next;                 // Puntero al siguiente sensor
};

#endif
