#ifndef LOGIN_H
#define LOGIN_H

#include "userdatabase.h"

class Login {
public:
  Login(UserDatabase& database); // Constructor que usa UserDatabase

  //verifica las credenciales (ID y NIF)
  bool checkCredentials(const User& user);

  //mensajes de login
  void printLoginSuccess() const;
  void printLoginFailure() const;

private:
  UserDatabase& userDatabase; // Referencia a UserDatabase
};

#endif

