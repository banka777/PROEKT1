#pragma once
#include <string>

class User {
public:
    User(const std::string& _name, const std::string& _password, const std::string& _login)
        : name(_name), password(_password), login(_login) {
    }
    const std::string& getName() const {
        return name;
    }
    const std::string& getPassword() const {
        return password;
    }
    const std::string& getLogin() const {
        return login;
    }
    void setName(const std::string& _name) {
        name = _name;
    }
    void setPassword(const std::string& _password) {
        password = _password;
    }
    void setLogin(const std::string& _login) {
        login = _login;
    }
private:
    std::string name;
    std::string password;
    std::string login;
};