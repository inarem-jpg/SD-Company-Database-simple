#ifndef TCAMARA_H
#define TCAMARA_H

#include "sensores.h"

class TCamara : public Sensor {
public:
  TCamara() : datoCont(0) {} // Inicializa el contador de datos

  void capturarDato(float nuevoDato); // guarda un nuevo dato en el array


  void imprimirDatos() const;  // imprime todos los datos guardados

private:
    float datos[maxSensores]; // Array para almacenar los datos de la cámara
    int datoCont;            // Cantidad de datos capturados
};

#endif
