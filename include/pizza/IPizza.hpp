/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** IPizza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_

#include <iostream>
#include <string>
#include "ipc.hpp"
#include <map>

enum pizzaState {
    WAITING, COOKING, UNDEFINED
};

class IPizza {
    public:
        ~IPizza() = default;

        const std::string &getName() const {return this->_name;}
        ipc::PizzaType getType() const {return this->_type;}
        ipc::PizzaSize getSize() const {return this->_size;}
        struct stock_s getIngredients() const {return this->_ingredients;}
        time_t getCookTime(int cookTimeMultiplier) const {return this->_cookTime * cookTimeMultiplier;}
        pizzaState getState() const {return this->_state;}

        void setState(pizzaState state) {this->_state = state;}

    protected:
        std::string _name;
        ipc::PizzaType _type;
        ipc::PizzaSize _size;
        struct stock_s _ingredients;
        pizzaState _state;
        time_t _cookTime;

    private:
};

#endif /* !IPIZZA_HPP_ */
