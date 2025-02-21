/**
  * @class LigthSens
  * @brief clase de sensor para medir la luz.
  * 
  * Un sensor que sirve para medir la luz.
  * 
  */

#include "LightSens.h"
#include <stdexcept>

void SensorLuz::medirLuz(float valor) {
    if (valor < 0) {
        throw std::invalid_argument("El valor de luz no puede ser negativo.");
    }
    valorActual = valor;
}

void SensorLuz::imprimirDatos() const {
    if (valorActual == 0) {
        throw std::runtime_error("El sensor de luz no ha medido ningún valor.");
    }
    std::cout << "Valor del sensor de luz: " << valorActual << std::endl;
}

