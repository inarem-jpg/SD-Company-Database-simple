
# ifndef ALARM_SEC
# define ALARM_SEC

#include <iostream>
#include <string>

class AlarmSec{
public:
  AlarmSec(); //constructor
  void getDStatus(bool);    //get the door's status
  void getWStatus(bool);   //get the window's status
  void PrintDStatus() const ; //prints the door's status
  void PrintWStatus() const ; //prints the window's status 
private:
  bool DStatus;  //True if no problems, False if open
  bool WStatus; //True if no problems, False if open

};

#endif
