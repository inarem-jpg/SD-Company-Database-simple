/**
  * @class TempSens
  * @brief clase de sensor para medir la temperatura
  * 
  * Un sensor que sirve para medir la temperatura del invernadero.
  * 
  */

#include "TempSens.h"
#include <iostream>
#include <stdexcept>

// Guarda un nuevo valor
void SensorTemp::medirTemp(float valor) {
  if (valor < 0) {
        throw std::invalid_argument("El valor de temperatura no puede ser negativo.");
    }
    valorActual = valor;
}
// Imprime el valor medido
void SensorTemp::imprimirDatos() const {
     if (valorActual == 0) {
        throw std::runtime_error("El sensor de temperatura no ha medido ningún valor.");
    }
    std::cout << "Valor del sensor de temperatura: " << valorActual << std::endl;
}

