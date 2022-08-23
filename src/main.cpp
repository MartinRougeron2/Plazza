/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** main
*/

#include "plazza.hpp"
#include <string>
#include <sstream>
#include <signal.h>

int main(int argc, char **argv)
{
    Plazza plazza;

    if (argc != 4) {
        printf("%s\n", USAGE);
        return 84;
    }
    if (!plazza.setCookingTime(argv[1]))
        return 84;
    if (!plazza.setCooksNumber(argv[2]))
        return 84;
    if (!plazza.setStock(argv[3]))
        return 84;
    signal(SIGCHLD, SIG_IGN);
    reception(plazza);
}
