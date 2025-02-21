
#ifndef MANEJO_EXCEPT_H
#define MANEJO_EXCEPT_H

#include <exception>
#include <iostream>
#include <stdexcept>
#include <new>

// Clase propia de excepción
class MiExcepcion : public std::exception {
public:
    const char* what() const noexcept override;
};

void funcionConExcepciones();

#endif 
