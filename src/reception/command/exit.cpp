/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** exit
*/

#include "plazza.hpp"
#include "ipc.hpp"

void Plazza::exitCommand()
{
    char msg[2] = {ipc::command::EXIT, 0};

    for (auto &i: this->kitchen) {
        sendMessage(i, msg);
        if (receiveMessage(i)[0] != ipc::answer::YES) {
            std::cerr << "Can't destroy a kitchen." << std::endl;
            exit(84);
        } else {
            close(i.pipefds2[0]);
        }
    }
    std::exit(0);
}
