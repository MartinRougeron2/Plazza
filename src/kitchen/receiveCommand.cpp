/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** receiveCommand
*/

#include "Kitchen.hpp"

void receiveCommand(Kitchen *k)
{
    char msg[8] = {0};
    char code[2] = {0};

    while (1) {
        read(k->getPipeFds().first[0], msg, 8);

        switch (msg[0]) {
            case ipc::command::STATUS:
                k->sendStatus();
                code[0] = ipc::answer::YES;
                break;

            case ipc::command::PIZZA:
                k->getPizzas().push_back(createPizza(static_cast<ipc::PizzaType>(msg[1]), static_cast<ipc::PizzaSize>(msg[2])));
                code[0] = ipc::answer::YES;
                break;

            case ipc::command::NBR_PIZZA:
                code[0] = static_cast<char>(k->getPizzas().size()) + 1;
                break;

            case ipc::command::EXIT:
                k->~Kitchen();
                break;
        }
        k->sendMessage(code);
    }
}
