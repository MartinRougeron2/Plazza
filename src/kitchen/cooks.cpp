/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** cooks
*/

#include "Kitchen.hpp"

[[noreturn]] void cooking(Kitchen *k, std::mutex &mtx, int i)
{
    int indexPizza;
    time_t pizzaCookTime;

    while (1) {
        if (k->getPizzas().size() != 0) {
            mtx.lock();
            if ((indexPizza = k->getFirstPizzaWaiting()) != -1) {
                std::cout << "the cook " << i + 1 << " will cook the " << k->getPizzas()[indexPizza] << std::endl;
                pizzaCookTime = k->getPizzas()[indexPizza].getCookTime(k->getPizzaTime());

                k->getPizzas()[indexPizza].setState(pizzaState::COOKING);
                k->lowerStock(k->getPizzas()[indexPizza].getIngredients());
                k->removeFreeCooks();
                k->setLastActiveTime(time(nullptr) + pizzaCookTime);

                mtx.unlock();
                std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(pizzaCookTime)));
                mtx.lock();
                std::cout << "The " << k->getPizzas()[indexPizza] << " is cooked (by cooks " << i + 1 << ")" << std::endl;
                k->addFreeCooks();
                k->getPizzas()[indexPizza].setState(pizzaState::UNDEFINED);
                mtx.unlock();
            } else {
                mtx.unlock();
            }
        } else {
            std::this_thread::yield();
        }
    }
}
