#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "restaurant_manager.hpp"

class Order : public Food
{
private:
    int quantity;

public:
    Order(Food *food);

    void setQuantity(int quantity);
    int getQuantity();

    void displayFood(int count) const override;
};

class Staff
{
private:
    list<Order *> order;
    RestaurantManager *restaurantDatabase = new RestaurantManager();

public:
    void orderFood();
    void cancelFood();
    void changeFood(int id, int quantity);
    void displayOrder();
    void checkOut();
};

#endif