/**
  * @class login
  * @brief clase para efectuar el login al sistema
  * 
  * Clase que efectua el inicio de sesion al sistema.
  * 
  */

#include "login.h"

Login::Login(UserDatabase& db) : userDatabase(db) {}

//verifica las credenciales
bool Login::checkCredentials(const User& user) {
  return userDatabase.findUser(user); // Usa el método de UserDatabase
}

//mensajes de login
void Login::printLoginSuccess() const {
  std::cout << "Login exitoso. Bienvenido!" << std::endl;
}

void Login::printLoginFailure() const {
  std::cout << "Credenciales incorrectas. Intentelo de nuevo." << std::endl;
}

