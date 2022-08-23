/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Americana
*/

#include "pizza/Americana.hpp"

Americana::Americana(ipc::PizzaSize size)
{
    this->_name = "americana";
    this->_type = ipc::PizzaType::Americana;
    this->_size = size;
    this->_state = WAITING;
    this->_ingredients = stock_s(1, 1, 1, 0, 0, 1, 0, 0, 0);
    this->_cookTime = 2;
}

Americana::~Americana()
{
}
