#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string user_id;
    string username;
    string phone_number;
    string email_id;

    // Default constructor
    User();
    
    // Parametrized constructor
    User(string user_id, string username, string phone_number, string email_id);
};

#endif
