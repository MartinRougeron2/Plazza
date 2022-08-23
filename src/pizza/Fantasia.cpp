/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Fantasia
*/

#include "pizza/Fantasia.hpp"

Fantasia::Fantasia(ipc::PizzaSize size)
{
    this->_name = "Fantasia";
    this->_type = ipc::PizzaType::Fantasia;
    this->_size = size;
    this->_state = WAITING;
    this->_ingredients = stock_s(1, 1, 0, 0, 0, 0, 1, 1, 1);
    this->_cookTime = 4;
}

Fantasia::~Fantasia()
{
}
