#include<iostream>
#include <string>
#include "chat.h"

void Chat::start()
{
    workChat = true;
}
std::shared_ptr<User> Chat::getUserbyLogin(const std::string& login) const
{
    for (const auto& user : users)
    {
        if (login == user.getLogin())
            return std::make_shared<User>(user);
    }
    return nullptr;
}
std::shared_ptr<User> Chat::getUserbyName(const std::string& name) const
{
    for (const auto& user : users)
    {
        if (name == user.getName())
            return std::make_shared<User>(user);
    }
    return nullptr;
}
void Chat::showLoginMenu()
{
    currentUser = nullptr;
    char choice;
    do {
        std::cout << "1. Sign in" << std::endl;
        std::cout << "2. Register an account" << std::endl;
        std::cout << "3. Sign out" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            login();
            break;
        case '2':
            signUp();
            break;
        case '3':
            workChat = false;
            break;
        default:
            std::cout << "Wrong choice" << std::endl;
            break;
        }
    } while (!currentUser && workChat);
}
void Chat::login()
{
    std::string login;
    std::string password;
    char choice;
    do {
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;

        currentUser = getUserbyLogin(login);
        if (currentUser == nullptr || (password != currentUser->getPassword()))
        {
            currentUser = nullptr;
            std::cout << "Wrong login or password" << std::endl;
            std::cout << "1. Try again" << std::endl;
            std::cin >> choice;
            if (choice == '1')
                break;
        }
    } while (!currentUser);

}


void Chat::showChat()const {
    std::string from;
    std::string to;
    std::cout << "________CHAT________" << std::endl;
    for (auto& message : messages)
    {
        if (currentUser->getLogin() == message.getFrom() || currentUser->getLogin() == message.getTo() || message.getTo() == "all")
        {
            from = (currentUser->getLogin() == message.getFrom()) ? "me" : getUserbyLogin(message.getTo())->getName();
            if (message.getTo() == "all")
                to = "all";

            else {
                to = (currentUser->getLogin() == message.getTo()) ? "me" : getUserbyLogin(message.getFrom())->getName();
            }
            std::cout << "Message from" << from << "to" << to << ": " << std::endl;
            std::cout << "text:" << message.getMessage() << std::endl;
        }
    }
    std::cout << "__________________________________" << std::endl;
}

void Chat::signUp()
{
    std::string login;
    std::string password;
    std::string name;
    std::cout << "Enter login: ";
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter name: ";
    std::cin >> name;
    if (getUserbyLogin(login) || login == "all")
    {
        throw UserLogin();
    }
    if (getUserbyName(name) || name == "all")
    {
        throw UserName();
    }
    User user = User(name, password, login);
    users.push_back(user);
    std::cout << "User created" << std::endl;
    currentUser = std::make_shared<User>(user);
}


void Chat::showUserMenu()
{
    char choise;
    std::cout << "Hello," << currentUser->getName() << std::endl;
    while (currentUser)
    {
        std::cout << "1. Show chat" << std::endl;
        std::cout << "2. ADD messages" << std::endl;
        std::cout << "3. Users" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choise;
        switch (choise)
        {
        case '1':
            showChat();
            break;
        case '2':
            addMessage();
            break;
        case '3':
            showUsers();
            break;
        case '4':
            currentUser = nullptr;
            break;
        default:
            std::cout << "Wrong choice" << std::endl;
            break;
        }
    }
}
void Chat::addMessage()
{
    std::string to;
    std::string text;
    std::cout << "Enter to: (name or all) ";
    std::cin >> to;
    std::cout << "Enter text: ";
    std::cin.ignore();
    getline(std::cin, text);
    if (!(to == "all" || getUserbyName(to)))
    {
        std::cout << "Wrong to" << to << std::endl;
        return;
    }
    if (to == "all")
        messages.push_back(Message{ currentUser->getLogin(),"all", text });
    else
        messages.push_back(Message{ currentUser->getLogin(), getUserbyName(to)->getLogin(),text });

}
void Chat::showUsers()
{
    std::cout << "________USERS________" << std::endl;
    for (const auto& user : users)
    {
        std::cout << "Name: " << user.getName() << std::endl;
        if (currentUser->getLogin() == user.getLogin())
            std::cout << "Login: me" << std::endl;
    }
    std::cout << "__________________________________" << std::endl;
}