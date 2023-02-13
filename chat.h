#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "message.h"

struct UserLogin : public std::exception {
    const char* what() const noexcept override {
        return "Error in UserLogin";
    }
};
struct UserName : public std::exception {
    const char* what() const noexcept override {
        return "Error in UserName";
    }
};
class Chat
{
    bool workChat = true;
    std::vector<User> users;
    std::vector<Message> messages;
    std::shared_ptr<User> currentUser;

    void login();
    void signUp();
    void showChat()const;
    void addMessage();
    void showUsers();

    std::vector<User>& getUsers() {
        return users;
    }
    std::vector<Message>& getMessages() {
        return messages;
    }
    std::shared_ptr<User>getUserbyLogin(const std::string& login) const;
    std::shared_ptr<User>getUserbyName(const std::string& name) const;
public:
    void start();
    bool isChatWork() const {
        return workChat;
    }
    std::shared_ptr<User> getCurrentUser() const {
        return currentUser;
    }
    void showLoginMenu();
    void showUserMenu();
};