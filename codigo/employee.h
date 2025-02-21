#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"

class Employee : public User {
public:
    Employee();
    Employee(const std::string& name, int id, int nif);
};

#endif

//es un user más, no tiene metodos propios
