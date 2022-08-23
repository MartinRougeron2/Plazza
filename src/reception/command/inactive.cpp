/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** inactive
*/

#include "plazza.hpp"
#include "ipc.hpp"

void Plazza::inactiveKitchen()
{
    for (size_t i = 0; i < this->kitchen.size();) {
        if (this->receiveMessage(this->kitchen[i])[0] == ipc::YES) {
            this->kitchen.erase(this->kitchen.begin() + i);
        } else
            i++;
    }
}
