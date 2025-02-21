/**
  * @class main
  * @brief clase main
  * 
  * donde se implementan el resto de clases todas juntas
  * 
  * @author Henar Contreras
  * @date 2024/2025
  */

#include "alarm_security.h"
#include "alarm_sensor.h"
#include "sensores.h"
#include "sensor_database.h"
#include "AirQuality.h"
#include "LightSens.h"
#include "RGBCamara.h"
#include "TCamara.h"
#include "TempSens.h"
#include "HumiditySens.h"
#include "admin.h"
#include "userdatabase.h"
#include "login.h"
#include "ManejoExcept.h"

#include <iostream>
#include <string>
#include <fstream>

template <typename T>
void writeToFile(std::ofstream& file, const T& data) {
    file.write(reinterpret_cast<const char*>(&data), sizeof(T));
}

//Función para guardar datos al fichero
void saveUsersToFile(const UserDatabase& db, const std::string& filename) {
  std::ofstream outputFile(filename, std::ios::binary | std::ios::trunc);
  if (!outputFile) {
    std::cerr << "Error al abrir el fichero para guardar.\n";
    return;
  }

  for (const auto& admin : db.getAdmins()) {
    bool isAdmin = true; //si es administrador
    writeToFile(outputFile, isAdmin); // Guardar indicador
    writeToFile(outputFile, admin.getID());
    writeToFile(outputFile, admin.getNIF());
    size_t nameSize = admin.getName().size();
    writeToFile(outputFile, nameSize);
    outputFile.write(admin.getName().c_str(), nameSize);
  }

  for (const auto& employee : db.getEmployees()) {
    bool isAdmin = false;
    writeToFile(outputFile, isAdmin); // Guardar indicador
    writeToFile(outputFile, employee.getID());
    writeToFile(outputFile, employee.getNIF());
    size_t nameSize = employee.getName().size();
    writeToFile(outputFile, nameSize);
    outputFile.write(employee.getName().c_str(), nameSize);
  }

  outputFile.close();
  std::cout << "Datos guardados correctamente en el fichero.\n";
}
//usamos un template para hacer las funciones read más claras y menos repetitivas
template <typename T>
void readFromFile(std::ifstream& file, T& data) {
  file.read(reinterpret_cast<char*>(&data), sizeof(T));
}
// Función para cargar datos de users desde el fichero
void loadUsersFromFile(UserDatabase& db, const std::string& filename) {
  std::ifstream inputFile(filename, std::ios::binary);
  if (!inputFile) {
    std::cout << "No se encontró el fichero, se creará uno nuevo al guardar.\n";
    return;
  }
  while (!inputFile.eof()) {
    std::string name;
    int id, nif;
    bool isAdmin;

    readFromFile(inputFile, isAdmin);
    readFromFile(inputFile, id);
    readFromFile(inputFile, nif);

    size_t nameSize;
    readFromFile(inputFile, nameSize);
    name.resize(nameSize);
    inputFile.read(&name[0], nameSize);

    if (inputFile.eof()) break;
    User user(name, id, nif);
    db.addUser(user, isAdmin);
  }
  inputFile.close();
  std::cout << "Datos cargados correctamente desde el fichero.\n";
}



void MenuAdmin() {  //menú que ven los administradores
  std::cout << "\n--- Menú ---\n";
  std::cout << "1. Agregar usuario\n";
  std::cout << "2. Eliminar usuario\n";
  std::cout << "3. Buscar usuario\n";
  std::cout << "4. Mostrar todos los usuarios\n";
  std::cout << "5. Modificar usuario\n"; 
  std::cout << "6. Mostrar detalles de los sensores\n";
  std::cout << "7. Mostrar detalles de la alarma\n";
  std::cout << "8. Verificar datos de sensores\n";
  std::cout << "9. Salir\n";
  std::cout << "\n";
  std::cout << "Elige una opción: ";
}

void MenuEmployee() {  //menú que ven los empleados
  std::cout << "\n--- Menú ---\n";
  std::cout << "1. Buscar usuario\n";
  std::cout << "2. Mostrar todos los usuarios\n";
  std::cout << "3. Mostrar detalles de los sensores\n";
  std::cout << "4. Verificar datos de sensores\n";
  std::cout << "5. Salir\n";
  std::cout << "\n";
  std::cout << "Elige una opción: ";
}

//Maneja el Login
bool loginUser(Login& login, UserDatabase& db, bool& isAdmin) {
  int id, nif;
  std::cout << "Introduce tu ID: ";
  std::cin >> id;
  std::cout << "Introduce tu NIF: ";
  std::cin >> nif;
/**
@brief Crea un usuario temporal para comprbar los datos de este y hacer el login
a la página correcta, administrador o empleado; o imprimir el mensaje de
login incorrecto
*/
  User tempUser("", id, nif);  //usuario temporal para comprobar los datos metidos
  if (login.checkCredentials(tempUser)) {
    if (db.isAdmin(tempUser)) {  //comprueba si es admin
      isAdmin = true;
    } 
    else if (db.isEmployee(tempUser)) {  
      isAdmin = false; //si credenciales correctas pero no es admin
    }
    login.printLoginSuccess(); //si credenciales correctas, deja hacer login
    return true;  
  } 
  else {
    login.printLoginFailure(); //si no, printea el mensaje de login incorrecto
    return false;
  }
}

//añade un nuevo usuario a la base de datos
void addUser(UserDatabase& db) {
  std::string name;
  int id, nif;
  bool isAdmin;

  std::cout << "\nIntroduce el nombre completo: ";
  std::cin.ignore(); // Limpia el buffer
  std::getline(std::cin, name); //para operar con espacios en el nombre

  std::cout << "Introduce el ID: ";
  std::cin >> id;

  std::cout << "Introduce el NIF: ";
  std::cin >> nif;

  std::cout << "¿Es el nuevo usuario administrador?\n";  
  std::cout << "1. Sí\n";  //crea un user Admin
  std::cout << "2. No\n";  //crea un user employee
  std::cin >> isAdmin;

  User newUser(name, id, nif); //crea un usuario nuevo 
  if (db.addUser(newUser, isAdmin)) {
    std::cout << "Usuario agregado correctamente.\n";
  } 
  else {
    std::cout << "El usuario ya está en la base de datos.\n";
  }
  std::cout << "\n";
}
// Elimina un usuario por su ID
void removeUser(UserDatabase& db) {
  int id;
  std::cout << "\n";
  std::cout << "Introduce el ID del usuario a eliminar: ";
  std::cin >> id;

  User tempUser("", id, 0); //el NIF no importa para eliminar un usuario
  if (db.removeUser(tempUser)) {
    std::cout << "Usuario eliminado correctamente.\n";
  } 
  else {
    std::cout << "Usuario no encontrado.\n";
  }
  std::cout << "\n";
}

//busca un usuario por su ID y NIF
void findUser(UserDatabase& db) {
  int id, nif;
  std::cout << "Introduce el ID del usuario: ";
  std::cin >> id;

  std::cout << "Introduce el NIF del usuario: ";
  std::cin >> nif;

  User tempUser("", id, nif);
  if (db.findUser(tempUser)) {
    std::cout << "El usuario existe en la base de datos.\n";
  } 
  else {
    std::cout << "El usuario no está en la base de datos.\n";
  }
  std::cout << "\n";
}
/**modifica los datos de un usuario (no puede modificarse a sí mismo)*/
void modifyUser(UserDatabase& db) {
  int oldId, oldNif, newId, newNif;
  std::string newName;

  std::cout << "\n";
  std::cout << "Introduce el ID del usuario a modificar: ";
  std::cin >> oldId;
  std::cout << "Introduce el NIF del usuario a modificar: ";
  std::cin >> oldNif;

  std::cout << "Introduce el nuevo nombre: ";
  std::cin.ignore(); //Limpia el buffer
  std::getline(std::cin, newName);

  std::cout << "Introduce el nuevo ID: ";
  std::cin >> newId;
  std::cout << "Introduce el nuevo NIF: ";
  std::cin >> newNif;
  std::cout << "\n";

 User oldUser("", oldId, oldNif);
  if (db.findUser(oldUser)) {  // Verifica si el usuario existe
    User newUser(newName, newId, newNif);  // Crea un nuevo usuario con los nuevos datos
    if (db.modifyUser(oldUser, newUser)) {
      std::cout << "Usuario modificado correctamente.\n";
    } 
    else {
      std::cout << "Error al modificar el usuario.\n";
    }
  } 
  else {
    std::cout << "El usuario no fue encontrado en la base de datos.\n";
  }
  std::cout << "\n";
}

//funcion básica para imprimir los datos de las alarmas
void alarmData(AlarmSec& alarm, AlarmSensor& alarmSensor){
  // Solo llama a las funciones de print
  std::cout << "\n";
  std::cout << "-------------------------------------\n";
  std::cout << "Estado del sistema de alarma:\n";
  alarm.PrintDStatus();
  alarm.PrintWStatus();
  std::cout << "-------------------------------------\n";
  std::cout << "\n";
}

void showSpecificSensorData(RGBCamara& RGBcamara, TCamara& Tcamara, SensorLuz& sensorLuz, 
                            AirQuality& airquality, SensorHumedad& sensorHumedad, 
                            SensorTemp& sensorTemp) {
  int sensorOption;
  std::cout << "\nSelecciona un sensor para ver sus datos:\n";
  std::cout << "1. Cámara RGB\n";
  std::cout << "2. Cámara de Temperatura\n";
  std::cout << "3. Sensor de Luz\n";
  std::cout << "4. Sensor de Calidad del Aire\n";
  std::cout << "5. Sensor de Humedad\n";
  std::cout << "6. Sensor de Temperatura\n";
    std::cout << "\n";
  std::cout << "Elige una opción: ";
  std::cin >> sensorOption;

  switch (sensorOption) {
    case 1:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      RGBcamara.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    case 2:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      Tcamara.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    case 3:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      sensorLuz.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    case 4:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      airquality.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    case 5:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      sensorHumedad.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    case 6:
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      sensorTemp.imprimirDatos();
      std::cout << "-------------------------------------\n";
      std::cout << "\n";
    break;
    default:
      std::cout << "Opción no válida.\n";
    break;
  }
}

//funcion básica para imprimir los datos de los sensores
void sensorData(RGBCamara& RGBcamara, TCamara& Tcamara, SensorLuz& sensorLuz, 
                AirQuality& airquality, SensorHumedad& sensorHumedad, 
                SensorTemp& sensorTemp, SensorData& sensorDatabase) {
  int sensorMenuOption;
  do {
    std::cout << "\n--- Menú de Datos de Sensores ---\n";
    std::cout << "1. Mostrar todos los datos de los sensores\n";
    std::cout << "2. Ver datos de un sensor específico\n";
    std::cout << "3. Volver al menú principal\n";
    std::cout << "\n";
    std::cout << "Elige una opción: ";

    std::cin >> sensorMenuOption;

  switch (sensorMenuOption) {
    case 1: {
      std::cout << "\n";
      std::cout << "-------------------------------------\n";
      std::cout << "Mostrando todos los datos:\n";
    try {
      RGBcamara.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos de la cámara RGB: " << e.what() << "\n";
      }
    try {
      Tcamara.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos de la cámara de temperatura: " << e.what() << "\n";
      }
    try {
      sensorLuz.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos del sensor de luz: " << e.what() << "\n";
      }
    try {
      airquality.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos de calidad del aire: " << e.what() << "\n";
      }
    try {
      sensorHumedad.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos del sensor de humedad: " << e.what() << "\n";
      }
    try {
      sensorTemp.imprimirDatos();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos del sensor de temperatura: " << e.what() << "\n";
      }
    try {
      sensorDatabase.printData();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error al mostrar datos de la base de datos de sensores: " << e.what() << "\n";
    }
    std::cout << "-------------------------------------\n";
    std::cout << "\n";
    break;
  }

    case 2:
      showSpecificSensorData(RGBcamara, Tcamara, sensorLuz, airquality, sensorHumedad, sensorTemp);
    break;
    case 3:
      std::cout << "Volviendo al menú principal...\n";
    break;
    default:
      std::cout << "Opción no válida. Inténtelo de nuevo.\n";
    break;
    }
  } while (sensorMenuOption != 3);
}
//funcion para verificar los datos en SensorData con AlarmSensor
void verifySensorData(AlarmSensor& alarmSensor, SensorData& sensorDatabase, float lower, float upper) {
  std::cout << "\n--- Verificando datos de sensores ---\n";
  try {
    alarmSensor.CheckDatabase(lower, upper);
  } catch (const std::exception& e) {
    std::cerr << "Error durante la verificación: " << e.what() << std::endl;
  }
}

/** creación de instancias de clases*/
int main() {
  UserDatabase db;               
  AlarmSec alarm;                
  AlarmSensor alarmSensor;      
  RGBCamara RGBcamara;           
  TCamara Tcamara;                
  SensorLuz sensorLuz;           
  AirQuality airquality;         
  SensorHumedad sensorHumedad;  
  SensorTemp sensorTemp;         
  SensorData sensorDatabase;   

  const std::string filename = "users.dat";

  loadUsersFromFile(db, filename);
  // Usuarios ya en el database
  //db.addUser(User("Henar Contreras", 101, 1234), true); //Admin 1
  //db.addUser(User("Jasón Grace", 102, 5678), false); //Employee 1

  Login login(db);      /**Crea una instancia de login usando el database*/

  //pide hacer login para mostrar el menú principal
  std::cout << "--- Inicio de sesión ---\n";
  bool isAdmin;
  while (!loginUser(login, db, isAdmin)) { //mientras no sean datos correctos
    std::cout << "Por favor, inténtelo de nuevo.\n";
    std::cout << "\n";
  }

  try {
    //crea los sensores
    //configuramos el sensor de luz
    sensorLuz.medirLuz(250.5f);

    //configura la cámara RGB
    RGBcamara.capturarDato(100.1f);
    RGBcamara.capturarDato(150.2f);

    //añadimos datos a la database
    sensorDatabase.addData(250.5f);
    sensorDatabase.addData(150.2f);

  } catch (const std::exception& e) {
      std::cerr << "Excepción: " << e.what() << std::endl;
  }

  int option;
  do {  
    if (isAdmin) { //si isAdmin = True el user es administrador
      MenuAdmin(); //muestra el menú de administrador
      std::cin >> option;
      switch (option) {
      case 1:
        addUser(db);
        break;
      case 2:
        removeUser(db);
        break;
      case 3:
        findUser(db);
        break;
      case 4:
        db.displayUsers();
        break;
      case 5:
        modifyUser(db);
        break;
      case 6:
        sensorData(RGBcamara, Tcamara, sensorLuz, airquality, sensorHumedad, 
                   sensorTemp, sensorDatabase);
        break;
      case 7:
        alarmData(alarm, alarmSensor);
        break;
      case 8:
        verifySensorData(alarmSensor, sensorDatabase, 100.0f, 200.0f);
        break;
      case 9:
        std::cout << "Saliendo del programa...\n";
        break;
      default:
        std::cout << "Opción no válida. Inténtelo de nuevo.\n";
        std::cout << "\n";
        break;
      }
    } 
    else { //si no es administrador
      MenuEmployee(); //muestra el menú de empleado
      std::cin >> option;
      switch (option) {
      case 1:
        findUser(db);
        break;
      case 2:
        db.displayUsers();
        break;
      case 3:
        sensorData(RGBcamara, Tcamara, sensorLuz, airquality, sensorHumedad,
                   sensorTemp, sensorDatabase);
        break;
      case 4:
        verifySensorData(alarmSensor, sensorDatabase, 100.0f, 200.0f);
        break;
      case 5:
        std::cout << "Saliendo del programa...\n";
        break;
      default:
        std::cout << "Opción no válida. Inténtelo de nuevo.\n";
        std::cout << "\n";
        break;
      }
    }
  } while (option != (isAdmin ? 9 : 5));

  //guardamos datos al fichero antes de salir
  saveUsersToFile(db, filename);

  return 0;
}
/*
while (option != (isAdmin ? 8 : 5)); controla cuándo termina el programa, usa
?: para decidir el valor que se compara, dependiendo del isAdmin.
*/
