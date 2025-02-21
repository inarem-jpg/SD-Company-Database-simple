/**
  * @class user
  * @brief clase user para los empleados
  * 
  * Crea las funcionalidades basicas de un empleado que usa el sistema,
  * incluyendo los datos de este y las acciones basicas a realizar.
  */

#include "user.h"

User::User() : Name(""), ID(0), NIF(0) {}

//todos los user tienen nombre, ID y NIF
User::User(const std::string& name, int id, int nif) : Name(name), ID(id), NIF(nif) {}

std::string User::getName() const {
  return Name;
}

int User::getID() const {
  return ID;
}

int User::getNIF() const {
  return NIF;
}
/**sobrecarga del operador < para comparar usuarios según su ID*/
bool User::operator<(const User& other) const {
  return ID < other.ID;
}
/**implementación del operador = para modify user*/
User& User::operator=(const User& other) {
  if (this != &other) {  //comprobamos si no es el mismo objeto
    Name = other.Name;
    ID = other.ID;
    NIF = other.NIF;
  }
  return *this;  //devuelve el objeto actual
}

/**Sobrecarga del operador < para comparar usuarios según su ID. Es necesario
para el orden en std::set, el operador = lo implementamos para poder hacer y usar
el método de modify user
*/
