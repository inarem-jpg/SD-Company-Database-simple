/**
  * @class ManejoExcept
  * @brief clase para manejar las excepciones.
  * 
  */

#include "ManejoExcept.h"

// Implementación de la clase propia de excepción
const char* MiExcepcion::what() const noexcept {
  return "Se ha producido una excepción personalizada";
}

// Función que demuestra el manejo de excepciones
void funcionConExcepciones() {
  // Bloque simple try-catch
  try {
    throw MiExcepcion();
  } catch (const MiExcepcion& e) {
      std::cout << "Capturada excepción personalizada: " << e.what() << std::endl;
  }

  // Bloque try-catch con varios manejadores catch
  try {
    throw 42; // Lanza un número entero
  } catch (int e) {
      std::cout << "Capturada excepción entera: " << e << std::endl;
  } catch (...) {
      std::cout << "Capturada una excepción desconocida." << std::endl;
  }

  // Instrucción throw y relanzamiento de excepción
  try {
    try {
      throw std::runtime_error("Error en la operación");
    } catch (const std::runtime_error& e) {
        std::cout << "Capturada excepción: " << e.what() << std::endl;
        throw; // Relanza la excepción
      }
    } catch (const std::exception& e) {
        std::cout << "Relanzada excepción capturada: " << e.what() << std::endl;
      }

  // Excepción bad_alloc al usar new
  try {
    std::cout << "Intentando asignar mucha memoria..." << std::endl;
    int* arr = new int[100000000000]; // Simula un fallo por memoria insuficiente
    delete[] arr; // Limpieza en caso de éxito
  } catch (const std::bad_alloc& e) {
      std::cout << "Excepción bad_alloc: " << e.what() << std::endl;
    }
}

