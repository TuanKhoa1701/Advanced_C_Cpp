#include "Header/restaurant_manager.hpp"

Food::Food()
{
    static int id = 1000;
    this->id = id;
    id++;
}

int Food::getID()
{
    return this->id;
}

int Food::getPrice()
{
    return this->price;
}

string Food::getName()
{
    return this->name;
}

void Food::setName(string name)
{
    this->name = name;
}

void Food::setPrice(int price)
{
    this->price = price;
}

void Food::displayFood(int count) const
{
    cout << "No.   " << "ID        " << "Name       " << "Price" << endl;
    cout << count << "     " << this->id << "      " << this->name << "      " << this->price << endl;
}

foodInfoType_t RestaurantManager::searchFood(int id)
{
    menuIndex_t it = this->menu.begin();
    Food *foundFood = NULL;
    for (Food *item : menu)
    {
        for (Food *item : this->menu)
        {
            if (item->getID() == id)
            {
                foundFood = item;
                break;
            }
            it++;
        }
    }
    return make_pair(foundFood, it);
}

void RestaurantManager::displayMenu() const
{
    int count = 1;
    for (Food *item : menu)
    {
        item->displayFood(count);
        count++;
    }
}