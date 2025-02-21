/**
  * @class HumiditySens
  * @brief clase de sensor para medir le humedad en el aire.
  * 
  * Un sensor que sirve para medir la humedad porcentual en el aire.
  * 
  */

#include "HumiditySens.h"
#include <iostream>

// Constructor
SensorHumedad::SensorHumedad() : valorHumedad(0.0f) {}

// Método para medir humedad
void SensorHumedad::medirHumedad(float valor) {
    if (valor < 0.0f || valor > 100.0f) {  // Validar el rango
        throw std::out_of_range("El valor de humedad debe estar entre 0 y 100.");
    }
    valorHumedad = valor;
}

// Método para imprimir los datos del sensor
void SensorHumedad::imprimirDatos() const {
    std::cout << "Humedad actual: " << valorHumedad << "%\n";
}

