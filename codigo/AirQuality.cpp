/**
  * @class airQuality
  * @brief clase de sensor para medir calidad del aire.
  * 
  * Un sensor que sirve para medir la calidad del aire.
  * 
  */

#include "AirQuality.h"
#include <iostream>
#include <stdexcept>

// Guarda un nuevo valor
void AirQuality::medirCalidad(float valor) {
    if (valor < 0) {
        throw std::invalid_argument("El valor de calidad del aire no puede ser negativo.");
    }
    valorActual = valor;
}

// Imprime el valor medido
void AirQuality::imprimirDatos() const {
    if (valorActual == 0) {
        throw std::runtime_error("El sensor de calidad del aire no ha medido ningún valor.");
    }
    std::cout << "Valor del sensor de calidad del aire: " << valorActual << std::endl;
}

