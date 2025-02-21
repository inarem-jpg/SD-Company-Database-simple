
#ifndef ALARM_SENS
#define ALARM_SENS

#include <iostream>
#include <string>

#include "sensor_database.h"
class AlarmSensor{
public:
  AlarmSensor(); //constructor
  void getUd(float);    //get the sensor's readings one by one
  void SetUd(float);    //sets each reading
  void PrintData() const; //print the data array or the parameter you're checking
  void PrintParameters() const;//print the status 
  void Check(float,float,float);   //checks if the ud is between the parameters
  void AttachDatabase(SensorData* database);
  // Nueva función para comprobar datos desde SensorData
  void CheckDatabase(float lower, float upper);

private:
  float parameters [12];  //the parameters the sensors should be between.
  float Ud; // variable where the data is read before it's saved

  //array where the data read is saved, with each new reading , tha data is
  //deleted and re-saved
  float Data [6] = {};  
  SensorData* sensorDatabase; // Puntero a SensorData para integrarlo
}; 

#endif
