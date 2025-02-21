/**
  * @class RGBCamara
  * @brief clase de sensor para medir los datos de la camara RGB
  * 
  * Un sensor que sirve para medir los datos de la camara RGB
  * 
  */

#include "RGBCamara.h"
#include <iostream>
#include <stdexcept>

/**los datos de las cámaras se guardan en un array*/
void RGBCamara::capturarDato(float nuevoDato) {
    if (datoCont >= maxSensores) {
        throw std::overflow_error("No se pueden agregar más datos a la cámara RGB. Límite alcanzado.");
    }
    datos[datoCont++] = nuevoDato;
}

void RGBCamara::imprimirDatos() const {
    if (datoCont == 0) {
        throw std::runtime_error("La cámara RGB no ha capturado ningún dato.");
    }
    std::cout << "Datos capturados por la cámara RGB: ";
    for (int i = 0; i < datoCont; ++i) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;
}

