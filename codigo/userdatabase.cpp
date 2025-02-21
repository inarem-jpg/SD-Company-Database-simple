/**
  * @class userdatabase
  * @brief clase de base de datos de de los ususarios
  * 
  * Guarda los datos de los usuarios, empleados y admins en una base
  * de datos que crea y modifica.
  */

#include "userdatabase.h"
#include <iostream>

bool UserDatabase::addUser(const User& user, bool isAdmin) {
  if (isAdmin) {
    auto result = admins.insert(user);
    return result.second; //true si se ha agregado new admin
  } 
  else {
    auto result = employees.insert(user);
    return result.second; //true si se ha agregado new employee
  }
}

bool UserDatabase::removeUser(const User& user) {
  if (admins.erase(user) > 0 || employees.erase(user) > 0) {
    return true; // Eliminado de cualquiera de las listas
  }
  return false;
}

//itera y busca el user pedido
bool UserDatabase::findUser(const User& user) const {
  return admins.find(user) != admins.end() || employees.find(user) != employees.end();
}

void UserDatabase::displayUsers() const { //para mostrar los admins y empleados
  std::cout << "\nAdmins en la base de datos:\n";
  for (const auto& admin : admins) {
    std::cout << "ID: " << admin.getID() 
              << ", NIF: " << admin.getNIF() 
              << ", Nombre: " << admin.getName() << "\n";
  }

  std::cout << "\nEmpleados en la base de datos:\n";
  for (const auto& employee : employees) {
    std::cout << "ID: " << employee.getID() 
              << ", NIF: " << employee.getNIF() 
              << ", Nombre: " << employee.getName() << "\n";
  }
}

/**modifica un usuario en la base de datos, cuando se cierra el programa se reinicia
*/
bool UserDatabase::modifyUser(const User& oldUser, const User& newUser) {
  /**seguro que hay una forma más eficiente de hacer esto, pero funciona so idc*/

  for (auto it = admins.begin(); it != admins.end(); ++it) {
    if (it->getID() == oldUser.getID() && it->getNIF() == oldUser.getNIF()) {
      admins.erase(it);  //elimina el antiguo admin
      admins.insert(newUser); //inserta el nuevo admin
      return true;  //si admin modificado correctamente
    }
  }
  for (auto it = employees.begin(); it != employees.end(); ++it) {
    if (it->getID() == oldUser.getID() && it->getNIF() == oldUser.getNIF()) {
       employees.erase(it);  //elimina el antiguo empleado
       employees.insert(newUser); //inserta el nuevo empleado
       return true;  //si empleado modificado correctamente
    }
  }
  return false;  //si no se encontró el usuario para modificarlo
}
/**métodos para verificar si el user es admin o empleado:*/

bool UserDatabase::isAdmin(const User& user) const {
    return admins.find(user) != admins.end();
}

bool UserDatabase::isEmployee(const User& user) const {
    return employees.find(user) != employees.end();
}

const std::set<User>& UserDatabase::getAdmins() const {
    return admins;
}

const std::set<User>& UserDatabase::getEmployees() const {
    return employees;
}


