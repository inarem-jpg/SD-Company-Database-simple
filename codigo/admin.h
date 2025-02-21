#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "userdatabase.h"

class Admin : public User {
public:
    Admin();
    Admin(const std::string& name, int id, int nif);

    void modifyUser(UserDatabase& db, const User& oldUser, const User& newUser);
};

#endif

//modifyUser Permite modificar usuarios en la base de datos userdatabase
