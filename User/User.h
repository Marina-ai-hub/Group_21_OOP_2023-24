#ifndef GROUP_21_OOP_2023_24_USER_H
#define GROUP_21_OOP_2023_24_USER_H
#include <string>


class User {
    string name;
    string email;
    string password;
    Generation result;
public:
    User();
    User(string _name, string _email, string _password);
    User(const User& other);
    ~User();
    string getName() const;
    User& setName(string newName);
    string getEmail() const;
    User& setEmail(string newEmail);
    string getPassword() const;
    User& setPassword(string newPassword);
    Generation getResult() const;
    User& setResult(Generation _result);
    void show();
     bool operator ==(const User& u) const;
     bool operator !=(const User& u) const;
};


#endif //GROUP_21_OOP_2023_24_USER_H
