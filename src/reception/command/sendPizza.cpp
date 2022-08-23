/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** sendPizza
*/

#include "plazza.hpp"
#include "ipc.hpp"
#include "pizza/pizzas.hpp"

int Plazza::findKitchen()
{
    static char msg[] = {ipc::command::NBR_PIZZA, 0};
    size_t leastBusyKitchen = this->numberCooks * 2;
    int value = 0;
    size_t index = 0;

    for (size_t i = 0; i < this->kitchen.size(); i++) {
        this->sendMessage(this->kitchen[i], msg);
        value = static_cast<int>(this->receiveMessage(this->kitchen[i])[0]) - 1;
        if (value < static_cast<int>(leastBusyKitchen)) {
            index = i;
            leastBusyKitchen = value;
        }
    }
    if (leastBusyKitchen == this->numberCooks * 2)
        return -1;
    return static_cast<int>(index);
}

void Plazza::sendPizzaToKitchen(kitchen_t &k, const std::string &pizzaName, const std::string &pizzaSize)
{
    char msg[4] = {ipc::command::PIZZA, 0, 0, 0};

    msg[1] = getPizzaNameToEnum(pizzaName);
    msg[2] = getPizzaSizeToEnum(pizzaSize);
    this->sendMessage(k, msg);
    if (this->receiveMessage(k)[0] != ipc::answer::YES) {
        std::cout << "Cannot send a pizza." << std::endl;
        exit(84);
    }
}

void Plazza::sendPizza(std::string command)
{
    std::string split;
    std::string pizza;
    std::string size;
    size_t quantity;
    size_t pos;
    int index = 0;

    while (!command.empty()) {
        pos = command.find(';');

        if (pos == std::string::npos)
            pos = command.length();
        else
            ++pos;
        split = command.substr(0, pos);
        if (split[0] == ' ')
            split.erase(0, 1);
        pizza = split.substr(0, split.find(' '));
        split.erase(0, pizza.size() + 1);
        size = split.substr(0, split.find(' '));
        split.erase(0, size.size() + 1);
        quantity = static_cast<size_t>(std::atol(split.substr(split.find('x') + 1, split.find_last_not_of(' ')).c_str()));

        for (size_t i = 0; i < quantity; i++) {
            index = this->findKitchen();
            if (index == -1) {
                if (!this->createKitchen()) {
                    std::cerr << "Can't create a kitchen." << std::endl;
                    exit(84);
                } else
                    index = static_cast<int>(this->kitchen.size()) - 1;
            }
            sendPizzaToKitchen(this->kitchen[static_cast<unsigned long>(index)], pizza, size);
        }

        command.erase(0, pos);
    }
}
