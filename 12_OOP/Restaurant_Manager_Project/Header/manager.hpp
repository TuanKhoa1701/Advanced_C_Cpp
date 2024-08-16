#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "restaurant_manager.hpp"

class Manager : public RestaurantManager
{
public:
    void setTable();
    void addFood();
    void editFood();
    void removeFood();
};

#endif