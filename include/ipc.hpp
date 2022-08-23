/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** ipc
*/

#ifndef IPC_HPP_
#define IPC_HPP_

struct stock_s
{
    long doe;
    long tomato;
    long gruyere;
    long ham;
    long mushrooms;
    long steak;
    long eggplant;
    long goatChesse;
    long chiefLove;

    stock_s(long doe=0, long tomato=0, long gruyere=0, long ham=0, long mushrooms=0, long steak=0, long eggplant=0, long goatChesse=0, long chiefLove=0):
    doe (doe), tomato (tomato), gruyere (gruyere), ham (ham), mushrooms (mushrooms), steak (steak), eggplant (eggplant), goatChesse (goatChesse), chiefLove (chiefLove)
        {
        }

    inline stock_s &operator+=(const stock_s &a)
    {
        doe = a.doe + doe;
        tomato = a.tomato + tomato;
        gruyere = a.gruyere + gruyere;
        ham = a.ham + ham;
        mushrooms = a.mushrooms + mushrooms;
        steak = a.steak + steak;
        eggplant = a.eggplant + eggplant;
        goatChesse = a.goatChesse + goatChesse;
        chiefLove = a.chiefLove + chiefLove;
        return *this;
    }

    inline stock_s &operator+=(const int val)
    {
        doe = val + doe;
        tomato = val + tomato;
        gruyere = val + gruyere;
        ham = val + ham;
        mushrooms = val + mushrooms;
        steak = val + steak;
        eggplant = val + eggplant;
        goatChesse = val + goatChesse;
        chiefLove = val + chiefLove;
        return *this;
    }

    inline stock_s &operator-=(const stock_s &a)
    {
        doe = doe - a.doe;
        tomato = tomato - a.tomato;
        gruyere = gruyere - a.gruyere;
        ham = ham - a.ham;
        mushrooms = mushrooms - a.mushrooms;
        steak = steak - a.steak;
        eggplant = eggplant - a.eggplant;
        goatChesse = goatChesse - a.goatChesse;
        chiefLove = chiefLove - a.chiefLove;
        return *this;
    }

    inline bool operator>=(const stock_s& other) const {
        return (
            doe >= other.doe &&
            tomato >= other.tomato &&
            gruyere >= other.gruyere &&
            ham >= other.ham &&
            mushrooms >= other.mushrooms &&
            steak >= other.steak &&
            eggplant >= other.eggplant &&
            goatChesse >= other.goatChesse &&
            chiefLove >= other.chiefLove
        );
    }
};

typedef struct stock_s kitchenStock;

namespace ipc
{
    enum command
    {
        STATUS = 1,
        COOK_FREE,
        PIZZA,
        IS_INACTIVE,
        NBR_PIZZA,
        EXIT
    };

    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum answer
    {
        NO = 1,
        YES
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
}

#endif /* !IPC_HPP_ */
