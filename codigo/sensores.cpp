/**
  * @class sensores
  * @brief clase de los sensores
  * 
  * de esta clase heredan todos los distintos tipos de sensores
  *  que existen en el sistema
  */

#include "sensores.h"
#include <stdexcept>

void Sensor::agregarSensor(int nuevoSensor) {
    static int count = 0;
    if (count >= maxSensores) {
        throw std::overflow_error("No se pueden agregar más sensores. Límite alcanzado.");
    }
    misSensores[count++] = nuevoSensor;
}

void Sensor::imprimirSensores() const {
    std::cout << "Lista de sensores: ";
    for (int i = 0; i < maxSensores && misSensores[i] != 0; ++i) {
        std::cout << misSensores[i] << " ";
    }
    std::cout << std::endl;
}

