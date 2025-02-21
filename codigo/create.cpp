#include <iostream>
#include <fstream>
#include <string>

int main() {
  const std::string filename = "users.dat";

  // Crear el fichero binario
  std::ofstream outputFile(filename, std::ios::binary | std::ios::trunc);
  if (!outputFile) {
    std::cerr << "Error al crear el fichero.\n";
    return 1;
  }

  // Usuario 1
  bool isAdmin = true; // Solo como dato adicional, no afecta a la lógica
  int id = 101;
  int nif = 1234;
  std::string name = "Henar Contreras";
  size_t nameSize = name.size();

  outputFile.write(reinterpret_cast<const char*>(&isAdmin), sizeof(isAdmin));
  outputFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
  outputFile.write(reinterpret_cast<const char*>(&nif), sizeof(nif));
  outputFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
  outputFile.write(name.c_str(), nameSize);

  // Usuario 2
  isAdmin = false; // Solo como dato adicional, no afecta a la lógica
  id = 102;
  nif = 5678;
  name = "Jasón Grace";
  nameSize = name.size();

  outputFile.write(reinterpret_cast<const char*>(&isAdmin), sizeof(isAdmin));
  outputFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
  outputFile.write(reinterpret_cast<const char*>(&nif), sizeof(nif));
  outputFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
  outputFile.write(name.c_str(), nameSize);

  outputFile.close();
  std::cout << "Fichero 'users.dat' creado correctamente.\n";

  return 0;
}

