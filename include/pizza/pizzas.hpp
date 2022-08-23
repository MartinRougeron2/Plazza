/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** createPizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "pizza/IPizza.hpp"

IPizza createPizza(ipc::PizzaType pizzaName, ipc::PizzaSize size);
ipc::PizzaSize getPizzaNameToEnum(const std::string size);
ipc::PizzaType getPizzaSizeToEnum(const std::string pizzaName);

std::ostream& operator<<(std::ostream& os, const IPizza &obj);

#endif /* !CREATEPIZZA_HPP_ */
