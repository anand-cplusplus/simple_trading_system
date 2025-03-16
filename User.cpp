#include "User.hpp"

User::User() : user_id(""), username(""), phone_number(""), email_id("") {}

User::User(string user_id, string username, string phone_number, string email_id)
    : user_id(user_id), username(username), phone_number(phone_number), email_id(email_id) {}
