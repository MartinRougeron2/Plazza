/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Fantasia
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_

#include "IPizza.hpp"

class Fantasia: public IPizza {
    public:
        Fantasia(ipc::PizzaSize _size);
        ~Fantasia();

    protected:
    private:
};

#endif /* !FANTASIA_HPP_ */
