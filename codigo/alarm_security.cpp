/**
  * @class alarm_security
  * @brief clase de la alarma de seguridad.
  * 
  * avisa si la puerta o ventana están abiertas.
  * 
  */

#include "alarm_security.h"

// Constructor
AlarmSec::AlarmSec() : DStatus(true), WStatus(true) {}

// Obtiene el estado de la puerta
void AlarmSec::getDStatus(bool status) {
  DStatus = status;
}

// Obtiene el estado de la ventana
void AlarmSec::getWStatus(bool status) {
  WStatus = status;
}

// Imprime el estado de la puerta
void AlarmSec::PrintDStatus() const {
  std::cout << "soy la alrma de la puerta" << std::endl;

}

// Imprime el estado de la ventana
void AlarmSec::PrintWStatus() const {
  std::cout << "yo la de la ventana" << std::endl;

}

