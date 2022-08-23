/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Regina
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_

#include "IPizza.hpp"

class Regina: public IPizza {
    public:
        Regina(ipc::PizzaSize _size);
        ~Regina();

    protected:
    private:
};

#endif /* !REGINA_HPP_ */
