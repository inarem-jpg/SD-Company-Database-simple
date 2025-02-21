
#ifndef SENSORS_DATA_H
#define SENSORS_DATA_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "sensores.h"

class SensorData {
public:
  SensorData () : dataCount(0){}

  void addData(float newValue);       // Agrega un nuevo valor 
  void printData() const;            // Imprime todos los datos
  void check(float param1, float param2, float param3); // Comprueba los datos
  void printParameters() const;      // Imprime los parámetros 
  int getDataCount() const; // 
  float getDataAt(int index) const; // 
private:
  static const int maxData = 128;
  float allData[maxData];            // Array para almacenar los datos
  int dataCount;                     // Contador

  SensorData* next;                  // Puntero al siguiente dato en la lista
  float parameters[maxData][3];      // Matriz para almacenar parámetros
};

#endif
