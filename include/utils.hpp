/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include "pizza/IPizza.hpp"

template <typename T>
void removeAtIndex(std::vector<T> &vec, size_t pos)
{
    typename std::vector<T>::iterator it = vec.begin();
    std::advance(it, pos);
    vec.erase(it);
}

#endif /* !UTILS_HPP_ */
