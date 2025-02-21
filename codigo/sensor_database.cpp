/**
  * @class sensor_database
  * @brief clase de la base de datos de los sensores
  * 
  * Esta clase crea la base de datos del sistema
  * 
  */

#include "sensor_database.h"
#include <stdexcept>

void SensorData::addData(float newValue) {
    if (dataCount >= maxData) {
        throw std::overflow_error("No se pueden almacenar más datos. Límite alcanzado.");
    }
    allData[dataCount++] = newValue;
}

void SensorData::printData() const {
    if (dataCount == 0) {
        throw std::runtime_error("No hay datos almacenados para imprimir.");
    }
    std::cout << "Datos almacenados: ";
    for (int i = 0; i < dataCount; ++i) {
        std::cout << allData[i] << " ";
    }
    std::cout << std::endl;
}
/**checkea los parámetros de los sensores*/
void SensorData::check(float param1, float param2, float param3) {
    if (dataCount == 0) {
        throw std::runtime_error("No hay datos para verificar.");
    }
    for (int i = 0; i < dataCount; ++i) {
        if (allData[i] < param1 || allData[i] > param3) {
            std::cout << "Alerta: Dato " << allData[i] << " fuera de parámetros.\n";
        }
    }
}

void SensorData::printParameters() const {
    if (dataCount == 0) {
        throw std::runtime_error("No hay parámetros establecidos para imprimir.");
    }
    std::cout << "Parámetros almacenados:\n";
    for (int i = 0; i < dataCount; ++i) {
        std::cout << "[" << parameters[i][0] << ", " << parameters[i][1] << ", " << parameters[i][2] << "]\n";
    }
}

int SensorData::getDataCount() const {
    return dataCount;
}

// Implementación de getDataAt
float SensorData::getDataAt(int index) const {
    if (index < 0 || index >= dataCount) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return allData[index];
}
