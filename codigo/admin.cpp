/**
  * @class admin
  * @brief clase derivada de usuario para los empleados administadores.
  * 
  * Esta clase hereda de User y le da la opcion de modificar usuarios a 
  * aquellos trabajadores que lo sean
  *
  */

#include "admin.h"
#include <iostream>

Admin::Admin() : User() {}  //hereda de user

Admin::Admin(const std::string& name, int id, int nif) : User(name, id, nif) {}

void Admin::modifyUser(UserDatabase& db, const User& oldUser, const User& newUser) {
  /**determina el rol del old User ( admin o employee)*/
  bool isAdmin = db.isAdmin(oldUser);

  if (db.removeUser(oldUser)) {
    db.addUser(newUser, isAdmin); //mantiene el rol original del usuario al modificarlo
    std::cout << "Usuario modificado con éxito.\n";
  } 
  else {
    std::cout << "Usuario a modificar no encontrado.\n";
  }
}

