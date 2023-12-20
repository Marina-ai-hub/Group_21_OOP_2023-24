#include "User.h"
#include <string>
using namespace std;

//class User
User::User() {
    name = "Noname";
    email = "Noemail";
    password = "Nopassword";
}
User::User(string _name, string _email, string _password) : name(_name), email(_email), password(_password) {}
User::User(const User& other) :name(other.name), email(other.email), password(other.password), result(other.result) {}
User::~User() {}
string User::getName() const {
    return name;
}
User& User::setName(string newName) {
    name = newName;
    return *this;
}
string User::getEmail() const {
    return email;
}
User& User::setEmail(string newEmail) {
    email = newEmail;
    return *this;
}
string User::getPassword() const {
    return password;
}
User& User::setPassword(string newPassword) {
    password = newPassword;
    return *this;
}
Generation User::getResult() const {
    return result;
}
User& User::setResult(Generation _result) {
    result = _result;
    return *this;
}
void User::show() {
    cout << " Name : " << name << endl;
    cout << " Email : " << email << endl;
    cout << " Password : " << password << endl;
    //cout << " Result : ";
    result.show();
    cout << endl;
}
bool User:: operator ==(const User& u) const{
    if(name==u.name) return true;
    return false;
};
bool User:: operator !=(const User& u1) const{
    return !(*this==u1);
};
