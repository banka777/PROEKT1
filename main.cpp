#include <iostream>
#include "chat.h"

int main()
{
    Chat chat;
    chat.start();
    while (chat.isChatWork())
    {
        chat.showLoginMenu();
        while (chat.getCurrentUser())
        {
            chat.showUserMenu();
        }
    }
    return 0;
}