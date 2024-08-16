#include "Header/staff.hpp"

Order::Order(Food *food)
{
    this->id = food->getID();
    this->name = food->getName();
    this->price = food->getPrice();
    this->quantity = 0;
}

void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int Order::getQuantity()
{
    return this->quantity;
}

void Order::displayFood(int count) const
{
    cout << "No.   " << "ID        " << "Name       " << "Price    " << "Quantity" << endl;
    cout << count << "     " << this->id << "      " << this->name << "      " << this->price << "        " << this->quantity << endl;
}

void Staff::orderFood()
{
    // Print menu
    cout << "Menu:" << endl;
    restaurantDatabase->displayMenu();

    // Input ID and quantity
    int id;
    int quantity;
    INPUT_INFO("Enter food ID you want to order: ", id);

    foodInfoType_t foundfood = restaurantDatabase->searchFood(id);
    if (foundfood.first != NULL)
    {
        foundfood.first->displayFood(1);
        Order *newOrder = new Order(foundfood.first);

        INPUT_INFO("Enter quantity: ", quantity);
        newOrder->setQuantity(quantity);

        order.push_back(newOrder);
        newOrder->displayFood(order.size());
    }
    else
    {
        cout << "Food not found with the given ID" << endl;
    }
}

void Staff::cancelFood()
{
    // Print order
    this->displayOrder();

    // Input ID and quantity
    int id;
    int quantity;
    INPUT_INFO("Enter food ID you want to cancel: ", id);

    foodInfoType_t foundfood = restaurantDatabase->searchFood(id);
    if (foundfood.first != NULL)
    {
        Order *cancelOrder = new Order(foundfood.first);
        cancelOrder->displayFood(1);

        INPUT_INFO("Enter the quantity you want to cancel: ", quantity);

        if (cancelOrder->getQuantity() >= quantity)
        {
            cancelOrder->setQuantity(cancelOrder->getQuantity() - quantity);
                }
        else
        {
            cout << "You cannot cancel more than you ordered" << endl;
        }
    }
    else
    {
        cout << "Food not found with the given ID" << endl;
    }
}

void Staff::displayOrder()
{
    int count = 1;
    for (Order *item : order)
    {
        item->displayFood(count);
        count++;
    }
}