/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <thread>
#include <vector>
#include "plazza.hpp"
#include <ctime>
#include <mutex>
#include <condition_variable>
#include "pizza/pizzas.hpp"
#include "utils.hpp"

class Kitchen {
    public:
        Kitchen(kitchen_t info, int cooksCount, float pizzaTime, float stockTime);
        ~Kitchen();

        // Getter
        std::pair<int *, int *> getPipeFds() const;
        std::vector<IPizza> &getPizzas();
        size_t getLastActiveTime() const;
        float getPizzaTime() const;
        size_t getNumberPizzaWaiting() const;
        int getFirstPizzaWaiting();
        bool getReady() const;

        // Setter
        void setLastActiveTime(time_t time);
        void setReady(bool r);

        // stock
        void lowerStock(kitchenStock stock);

        // Cooks
        void removeFreeCooks();
        void addFreeCooks();

        // Link to reception
        void sendMessage(char *msg) const;

        void runKitchen();
        bool isInactive() const;
        void fillStock();
        void sendStatus() const;

    protected:
    // Communication
        std::pair<int *, int *> pipefds;
        std::condition_variable cv;
        std::mutex mtx;
        int id;

    // Pizza
        std::vector<IPizza> pizzas;

    // Cooks
        std::thread *cooks;
        int totalCooks;
        int freeCooks;

    // Kitchen timing
        float pizzaTime;
        float stockTime;
        kitchenStock stock;
        std::time_t _lastActiveTime;
        std::time_t _lastStockFill;
    private:
};

void receiveCommand(Kitchen *k);
[[noreturn]] void cooking(Kitchen *k, std::mutex &mtx, int i);

#endif /* !KITCHEN_HPP_ */
