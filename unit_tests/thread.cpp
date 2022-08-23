/*
** EPITECH PROJECT, 2021
** B-CCP-400-LYN-4-1-theplazza-anthony.couhier
** File description:
** thread
*/

#include <gtest/gtest.h>
#include <thread>
#include "Kitchen.hpp"

TEST(threads, dummy_threads)
{
    Kitchen kitchenBase((kitchen_t){0, 0, 0}, 2, 1000.0f);

    kitchenBase.getPizzas().push_back({ipc::Regina, ipc::L, WAITING});
    ASSERT_EQ(kitchenBase.getCooksCount(), 2);
    cooking(&kitchenBase, 0, 0);
    ASSERT_EQ(kitchenBase.getCooksCount(), 1);
    sleep(2);
    EXPECT_EQ(kitchenBase.getCooksCount(), 2);
}
