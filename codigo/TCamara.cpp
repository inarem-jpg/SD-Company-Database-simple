/**
  * @class TCamara
  * @brief clase de sensor para medir los datos de la Tcamara
  * 
  * Un sensor que sirve para medir los datos de la camara de temperatura
  * 
  */

#include "TCamara.h"
#include <iostream>
#include <stdexcept>

void TCamara::capturarDato(float nuevoDato) {
    if (datoCont >= maxSensores) {
        throw std::overflow_error("No se pueden agregar más datos a la cámara de temp. Límite alcanzado.");
    }
    datos[datoCont++] = nuevoDato;
}

void TCamara::imprimirDatos() const {
    if (datoCont == 0) {
        throw std::runtime_error("La cámara de temperatura no ha capturado ningún dato.");
    }
    std::cout << "Datos capturados por la cámara de temperatura: ";
    for (int i = 0; i < datoCont; ++i) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;
}

