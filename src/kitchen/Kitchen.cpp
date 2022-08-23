/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include <iomanip>

Kitchen::Kitchen(kitchen_t info, int cooksCount_, float pizzaTime_, float stockTime_)
{
    this->id = info.pid;
    this->pipefds = std::make_pair(info.pipefds1, info.pipefds2);
    this->_lastActiveTime = time(nullptr);
    cooks = new std::thread[cooksCount_];
    this->pizzaTime = pizzaTime_;
    this->totalCooks = cooksCount_;
    this->freeCooks = cooksCount_;
    this->stockTime = stockTime_ / 1000;
    this->_lastStockFill = time(nullptr);
    this->stock = stock_s(5, 5, 5, 5, 5, 5, 5, 5, 5);
    std::cout << "Kitchen: " << this->id << " is created" << std::endl;
}

Kitchen::~Kitchen()
{
    char code[2] = {ipc::answer::YES, 0};
    sendMessage(code);
    std::cout << "Kitchen: " << this->id << " is destroyed" << std::endl;
    close(this->pipefds.first[0]);
    close(this->pipefds.first[1]);
    close(this->pipefds.second[1]);
    close(this->pipefds.second[0]);
    free(this->pipefds.first);
    free(this->pipefds.second);
    delete[] this->cooks;
    exit(0);
}

std::pair<int *, int *> Kitchen::getPipeFds() const
{
    return this->pipefds;
}

std::vector<IPizza> &Kitchen::getPizzas()
{
    return this->pizzas;
}

size_t Kitchen::getLastActiveTime() const
{
    return this->_lastActiveTime;
}

float Kitchen::getPizzaTime() const
{
    return this->pizzaTime;
}

size_t Kitchen::getNumberPizzaWaiting() const
{
    size_t pizzaWainting = 0;

    for (auto &i: this->pizzas) {
        if (i.getState() == pizzaState::WAITING) {
            pizzaWainting++;
        }
    }
    return pizzaWainting;
}

int Kitchen::getFirstPizzaWaiting()
{
    for (size_t i = 0; i < this->pizzas.size(); i++) {
        if (this->pizzas[i].getState() == pizzaState::WAITING) {
            return i;
        }
    }
    return -1;
}

void Kitchen::setLastActiveTime(time_t time)
{
    this->_lastActiveTime = time;
}

void Kitchen::lowerStock(kitchenStock stock)
{
    this->stock -= stock;
}

void Kitchen::removeFreeCooks()
{
    this->freeCooks--;
}

void Kitchen::addFreeCooks()
{
    this->freeCooks++;
}

void Kitchen::sendMessage(char *msg) const
{
    write(this->pipefds.second[1], msg, strlen(msg));
}

void Kitchen::runKitchen()
{
    std::thread reader(receiveCommand, this);

    for (int i = 0; i < this->totalCooks; i++) {
        this->cooks[i] = std::thread(cooking, this, std::ref(this->mtx), i);
        this->cooks[i].detach();
    }
    while (true) {
        fillStock();
        if (this->isInactive())
            this->~Kitchen();
        for (size_t i = 0; i < this->pizzas.size(); i++)
            if (this->pizzas[i].getState() == pizzaState::UNDEFINED)
                removeAtIndex(this->pizzas, i);
    }
}

bool Kitchen::isInactive() const
{
    std::time_t actualTime = time(nullptr);

    if (actualTime - this->_lastActiveTime >= 5) {
        return true;
    }
    return false;
}

void Kitchen::fillStock()
{
    time_t actualTime = std::time(nullptr);

    if (actualTime - this->_lastStockFill >= this->stockTime) {
            this->stock += 1;
            this->_lastStockFill = actualTime;
    }
}

void Kitchen::sendStatus() const
{
    std::cout <<  "\tnumber cook free: " << std::to_string(this->freeCooks) << "\n";
    std::cout <<  "\tpizza: " << this->pizzas.size() << std::endl;
    std::cout <<  "\tpizza cooking:\n";
    for (auto &i: this->pizzas)
        if (i.getState() == COOKING)
            std::cout <<  "\t\t- " << i << "\n";
    std::cout <<  "\tpizza waiting:\n";
    for (auto &i: this->pizzas)
        if (i.getState() == WAITING)
            std::cout <<  "\t\t- " << i <<  "\n";

    std::cout <<  "\nIngredients:\n";
    std::cout << "\tdoe" << std::setw(11 - std::strlen("doe")) << " : " << stock.doe << " | ";
    std::cout << "tomato" << std::setw(14 - std::strlen("tomato")) << " : " << stock.tomato << " | ";
    std::cout << "gruyere" << std::setw(12 - std::strlen("gruyere")) << " : " << stock.gruyere << std::endl;
    std::cout << "\tham" << std::setw(11 - std::strlen("ham")) << " : " << stock.ham << " | ";
    std::cout << "mushrooms" << std::setw(14 - std::strlen("mushrooms")) << " : " << stock.mushrooms << " | ";
    std::cout << "steak" << std::setw(12 - std::strlen("steak")) << " : " << stock.steak << std::endl;
    std::cout << "\teggplant" << std::setw(11 - std::strlen("eggplant")) << " : " << stock.eggplant << " | ";
    std::cout << "goat cheese" << std::setw(14 - std::strlen("goat cheese")) << " : " << stock.goatChesse << " | ";
    std::cout << "chief love" << std::setw(12 - std::strlen("chief love")) << " : " << stock.chiefLove << std::endl << std::endl;
}
