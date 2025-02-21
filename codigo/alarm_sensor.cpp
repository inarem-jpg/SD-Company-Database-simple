/**
  * @class alarm_sensor
  * @brief clase de la alarma de los sensores.
  * 
  * avisa si los sensores se han pasado de los parametros establecidos.
  * 
  */

#include "alarm_sensor.h"
#include "sensor_database.h" 
#include <stdexcept>
#include <iostream>

AlarmSensor::AlarmSensor() : Ud(0), sensorDatabase(nullptr){}
/** hace una referencia a las base de datos de los sensores, si no hay, salta
el error de referencia nula
*/
void AlarmSensor::AttachDatabase(SensorData* database) {
  if (!database) {
    throw std::invalid_argument("Referencia nula para la base de datos del sensor.");
  }
  sensorDatabase = database;
}
/**
checkea si el valor medidio es mayor o menor a los parametros establecidos
y avisa en caso de serlo
*/
void AlarmSensor::CheckDatabase(float lower, float upper) {
  if (!sensorDatabase) {
    throw std::runtime_error("No se ha vinculado ninguna base de datos de sensor.");
  }
  try {
    for (int i = 0; i < sensorDatabase->getDataCount(); ++i) {
      float value = sensorDatabase->getDataAt(i);
      if (value < lower || value > upper) {
        std::cout << "Alerta: El valor " << value << " está fuera de los parámetros.\n";
      } 
      else {
          std::cout << "El valor " << value << " está dentro de los parámetros.\n";
      }
    }
  } catch (const std::exception& e) {
      std::cerr << "Error al verificar los datos: " << e.what() << std::endl;
    }
}
void AlarmSensor::getUd(float value) {
    Ud = value;
}

void AlarmSensor::SetUd(float value) {
    Ud = value;
}

void AlarmSensor::PrintData() const {
    if (Ud == 0) {
        throw std::runtime_error("No hay datos para imprimir.");
    }
    std::cout << "Datos actuales: " << Ud << std::endl;
}

void AlarmSensor::PrintParameters() const {
    if (parameters[0] == 0) {
        throw std::runtime_error("No se han establecido parámetros.");
    }
    std::cout << "Parámetros establecidos: ";
    for (const auto& param : parameters) {
        std::cout << param << " ";
    }
    std::cout << std::endl;
}

void AlarmSensor::Check(float lower, float upper, float value) {
    if (lower >= upper) {
        throw std::invalid_argument("El límite inferior debe ser menor que el superior.");
    }
    if (value < lower || value > upper) {
        std::cout << "Alerta: El valor " << value << " está fuera de los parámetros.\n";
    } else {
        std::cout << "El valor está dentro de los parámetros.\n";
    }
}

