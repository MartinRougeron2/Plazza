/*
** EPITECH PROJECT, 2021
** B-CCP-400-LYN-4-1-theplazza-anthony.couhier
** File description:
** Plazza.cpp
*/

#include "plazza.hpp"
#include "Kitchen.hpp"

static bool isInteger(const std::string & s){
    return std::regex_match(s, std::regex("\\d+"));
}

static bool isFloat(const std::string & s){
    return std::regex_match(s, std::regex("\\d+(.\\d+)?"));
}

Plazza::Plazza()
{
}

Plazza::~Plazza()
{

}

bool Plazza::setCookingTime(char *cookingTime)
{
    if (!isFloat(cookingTime)) {
        std::cerr <<"Bad cooking time\n\"" << std::string(cookingTime) << "\" is not a valid cooking time" << std::endl;
        return false;
    }
    this->cookingTime = std::stof(cookingTime);
    return true;
}

bool Plazza::setCooksNumber(char *cooksNumber)
{

    if (!isInteger(cooksNumber)) {
        std::cerr <<"Bad number of cooks\n\"" << std::string(cooksNumber) << "\" is not a valid number of cook" << std::endl;
        return false;
    }
    this->numberCooks = static_cast<unsigned int>(std::stol(cooksNumber, nullptr, 10));
    return true;
}

bool Plazza::setStock(char *timeStock)
{
    if (!isInteger(timeStock)) {
        std::cerr <<"Bad time of replacement\n\"" << std::string(timeStock) << "\" is not a valid number of miliseconds" << std::endl;
        return false;
    }
    this->stockTime = static_cast<float>(std::stof(timeStock));
    return true;
}

float Plazza::getCookingTime()
{
    return this->cookingTime;
}

unsigned int Plazza::getNumberCooks()
{
    return this->numberCooks;
}

size_t Plazza::getStock()
{
    return this->stockTime;
}

std::vector<kitchen_t> Plazza::getKitchen()
{
    return this->kitchen;
}

bool Plazza::createKitchen()
{
    pid_t pid;
    int *pipefds1 = new int[2];
    int *pipefds2 = new int[2];

    pipe(pipefds1);
    pipe(pipefds2);
    pid = fork();
    if (pid == -1)
        return false;
    else if (pid == 0) {
        close(pipefds2[0]);
        close(pipefds1[1]);
        Kitchen kitch({(int) this->kitchen.size() + 1, pipefds1, pipefds2}, static_cast<int>(this->numberCooks), this->cookingTime, this->stockTime);
        kitch.runKitchen();
        exit(0);
    }
    close(pipefds1[0]);
    close(pipefds2[1]);
    this->kitchen.push_back({pid, pipefds1, pipefds2});
    return true;
}

void Plazza::sendMessage(kitchen_t kitchen_, const char *message)
{
    usleep(500);
    write(kitchen_.pipefds1[1], message, sizeof(message));
}

char *Plazza::receiveMessage(kitchen_t kitchen_)
{
    char msg[1025] = {0};

    read(kitchen_.pipefds2[0], msg, 1025);
    return strdup(msg);
}
