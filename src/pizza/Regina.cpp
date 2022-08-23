/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Regina
*/

#include "pizza/Regina.hpp"

Regina::Regina(ipc::PizzaSize size)
{
    this->_name = "Regina";
    this->_type = ipc::PizzaType::Regina;
    this->_size = size;
    this->_state = WAITING;
    this->_ingredients = stock_s(1, 1, 1, 1, 1, 0, 0, 0, 0);
    this->_cookTime = 2;
}

Regina::~Regina()
{
}
