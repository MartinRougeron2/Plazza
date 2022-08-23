/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** pizzaToEnum
*/

#include "pizza/Americana.hpp"
#include "pizza/Regina.hpp"
#include "pizza/Fantasia.hpp"
#include "pizza/Margarita.hpp"
#include <map>

ipc::PizzaType getPizzaNameToEnum(const std::string pizzaName)
{
    std::map<std::string, ipc::PizzaType> pizzaNameToEnum {
        {"regina", ipc::PizzaType::Regina},
        {"margarita", ipc::PizzaType::Margarita},
        {"americana", ipc::PizzaType::Americana},
        {"fantasia", ipc::PizzaType::Fantasia}
    };
    return pizzaNameToEnum[pizzaName];
}

ipc::PizzaSize getPizzaSizeToEnum(const std::string size)
{
    std::map<std::string, ipc::PizzaSize> sizeToEnum {
        {"s", ipc::PizzaSize::S},
        {"m", ipc::PizzaSize::M},
        {"l", ipc::PizzaSize::L},
        {"xl", ipc::PizzaSize::XL},
        {"xxl", ipc::PizzaSize::XXL}
    };
    return sizeToEnum[size];
}

IPizza createPizza(ipc::PizzaType pizzaName, ipc::PizzaSize size)
{
    std::map<ipc::PizzaType, IPizza> allPizza {
        {ipc::PizzaType::Regina, Regina(size)},
        {ipc::PizzaType::Margarita, Margarita(size)},
        {ipc::PizzaType::Americana, Americana(size)},
        {ipc::PizzaType::Fantasia, Fantasia(size)}
    };
    return allPizza[pizzaName];
}

std::ostream& operator<<(std::ostream& os, const IPizza &obj)
{
    std::map<ipc::PizzaSize, std::string> sizeToEnum {
        {ipc::PizzaSize::S, "s"},
        {ipc::PizzaSize::M, "m"},
        {ipc::PizzaSize::L, "l"},
        {ipc::PizzaSize::XL, "xl"},
        {ipc::PizzaSize::XXL, "xxl"}
    };
    os << obj.getName() << " " << sizeToEnum[obj.getSize()];
    return os;
}
