/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "IPizza.hpp"

class Margarita: public IPizza {
    public:
        Margarita(ipc::PizzaSize _size);
        ~Margarita();

    protected:
    private:
};

#endif /* !MARGARITA_HPP_ */
