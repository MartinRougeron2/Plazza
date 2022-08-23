/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** status
*/

#include "plazza.hpp"
#include "ipc.hpp"

void Plazza::status()
{
    static char msg[2] = {ipc::STATUS, 0};

    std::cout << "Status:" << std::endl;
    if (this->kitchen.size() == 0) {
        std::cout << "No kitchen in activity." << std::endl;
        return;
    }
    for (size_t i = 0; i < this->kitchen.size(); i++) {
        this->sendMessage(this->kitchen[i], msg);
        std::cout << "KITCHEN #" << i + 1 << ": " << std::endl;
        if (this->receiveMessage(this->kitchen[i])[0] != ipc::answer::YES) {
            std::cerr << "Wrong status" << std::endl;
            exit(84);
        };
    }
}
