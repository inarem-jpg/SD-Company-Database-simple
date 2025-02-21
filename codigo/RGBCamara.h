#ifndef RGBCAMARA_H
#define RGBCAMARA_H

#include "sensores.h"

class RGBCamara : public Sensor {
public:
  RGBCamara() : datoCont(0) {} // Inicializa el contador de datos

  void capturarDato(float nuevoDato); //guarda un nuevo dato en el array de la camara

  
  void imprimirDatos() const;

private:
  float datos[maxSensores]; // Array para almacenar datos de la cámara
  int datoCont;            // Cantidad de datos capturados
};

#endif

