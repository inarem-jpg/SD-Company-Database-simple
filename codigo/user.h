#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
  User();
  User(const std::string& name, int id, int nif);

  std::string getName() const;
  int getID() const;
  int getNIF() const;

  bool operator<(const User& other) const; // Para ordenar y comparar en std::set
  User& operator=(const User& other);
protected:  //para que los que heredan puedan acceder a ellos
  std::string Name; // Nombre completo
  unsigned int ID;  // ID del usuario
  unsigned int NIF; // NIF del usuario
};

#endif

