/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** reception
*/

#include "plazza.hpp"
#include <regex>
#include <ctype.h>
#include "ipc.hpp"

#define REGEX_COMMAND_PIZZA std::regex("(?:\\s*(regina|margarita|americana|fantasia)\\s+(s|m|l|xl|xxl)\\s+(x\\d+)\\s*(;|$))+")

static void removeSpaces(std::string &str)
{
    std::for_each(str.begin(), str.end(), [](char &c) {
        if (isspace(c))
            c = ' ';
    });
    str.erase(0, str.find_first_not_of(' '));
    for (size_t i = 0; i < str.length();)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i);
        }
        else
            i++;
    }
}

void reception(Plazza &plazza)
{
    std::string line;
    static std::array<std::regex, 3> commands_auths = {
        std::regex("(regina|margarita|americana|fantasia|status|exit)"),
        std::regex("(s|m|l|xl|xxl)"),
        std::regex("(x\\d+)\\s*(;|$)")
    };

    while (std::getline(std::cin, line)) {
        if (line.empty())
            continue;
        std::for_each(line.begin(), line.end(), [](char &c) { c = static_cast<char>(std::tolower(c)); });
        removeSpaces(line);
        plazza.inactiveKitchen();
        if (line == "status")
            plazza.status();
        else if (line == "exit")
            plazza.exitCommand();
        else if (std::regex_match(line, REGEX_COMMAND_PIZZA))
            plazza.sendPizza(line);
        else {
            int i = 0;
            std::istringstream ss(line);
            std::string token;
            while (i < 3 && std::getline(ss, token, ' ')) {
                if (!std::regex_match(token, commands_auths.at(i++))) {
                    std::cout << "Unkown command: " << token << '\n';
                    break;
                }
            }
            if (i == 3)
                std::cerr << "Bad syntax: " << line << std::endl;
        }
    }
}
