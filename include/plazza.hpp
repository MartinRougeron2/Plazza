/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include <thread>
#include <vector>
#include <regex>
#include "unistd.h"
#include "sys/types.h"
#include <thread>
#include "ipc.hpp"
#include "pizza/IPizza.hpp"

struct __attribute__((packed)) kitchen_s {
    int pid;
    int *pipefds1;
    int *pipefds2;
};

typedef struct kitchen_s kitchen_t;

class Plazza {
    public:
        Plazza();
        ~Plazza();

        // setter
        bool setCookingTime(char *cookingTime);
        bool setCooksNumber(char *cooksNumber);
        bool setStock(char *timeStock);

        // getter
        float getCookingTime();
        unsigned int getNumberCooks();
        std::vector<kitchen_t> getKitchen();
        size_t getStock();

        // link to kitchen
        void sendMessage(kitchen_t kitchen, const char *msg);
        char *receiveMessage(kitchen_t kitchen);

        // command kitchen
        bool createKitchen();
        void status();
        void exitCommand();
        void inactiveKitchen();
        void sendPizza(std::string command);
        int findKitchen();
        void sendPizzaToKitchen(kitchen_t &k, const std::string &pizzaName, const std::string &pizzaSize);


    protected:
        float cookingTime;
        unsigned int numberCooks;
        float stockTime;
        std::vector<kitchen_t> kitchen;
        kitchenStock stock;

};

#define USAGE "\
USAGE:\n\
    plazza <TIME> <COOK> <STOCK>\n\
\n\
Args:\n\
\tTIME\tMultiplier for the cooking time of the pizzas.\n\
\tCOOK\tNumber of cook per kitchen\n\
\tSTOCK\ttime in milliseconds, used by the kitchen\
stock to replace ingredients.\n"

void reception(Plazza &plazza);

template <typename T>
void removeAtIndex(std::vector<T> *vec, size_t pos);

#endif /* !PLAZZA_HPP_ */
