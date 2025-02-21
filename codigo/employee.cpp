/**
  * @class employee
  * @brief clase de los empleados.
  * 
  * clase simple que hereda de User, para los empleados no admins
  * 
  */

#include "employee.h"

Employee::Employee() : User() {}

Employee::Employee(const std::string& name, int id, int nif) : User(name, id, nif) {

}
//se llama al constructor de user, no hace nada más.

