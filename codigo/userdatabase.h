#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "user.h"
#include <set>
#include <iostream>

class UserDatabase {
public:
  bool addUser(const User& user, bool isAdmin); // Agregar usuario con su rol
  bool removeUser(const User& user);           // Eliminar usuario
  bool findUser(const User& user) const;       // Buscar usuario
  void displayUsers() const;                   // Mostrar todos los usuarios
  bool isAdmin(const User& user) const;        // Verifica si es admin
  bool isEmployee(const User& user) const;     // Verifica si es employee
  bool modifyUser(const User& oldUser, const User& newUser); //modifica los datos de user
  const std::set<User>& getAdmins() const;
  const std::set<User>& getEmployees() const;

private:
  std::set<User> admins;       // conjunto de admins
  std::set<User> employees;    // conjunto de empleados
};

#endif

//Define la clase UserDatabase, que contiene y gestiona un conjunto (std::set)
//de usuarios (employees y admins).


