/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Margarita
*/

#include "pizza/Margarita.hpp"

Margarita::Margarita(ipc::PizzaSize size)
{
    this->_name = "Margarita";
    this->_type = ipc::PizzaType::Margarita;
    this->_size = size;
    this->_state = WAITING;
    this->_ingredients = stock_s(1, 1, 1, 0, 0, 0, 0, 0, 0);
    this->_cookTime = 1;
}

Margarita::~Margarita()
{
}
