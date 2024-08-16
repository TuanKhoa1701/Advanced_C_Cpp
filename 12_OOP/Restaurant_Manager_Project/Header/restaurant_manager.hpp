#ifndef __RESTAURANT_MANAGER_HPP__
#define __RESTAURANT_MANAGER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

#define INPUT_STRING_INFO(message, property) \
    cin.ignore();                            \
    cout << message;                         \
    getline(cin, property)

#define INPUT_INFO(message, property) \
    cout << message;                  \
    cin >> property

#define PRINT_MENU_ITEM(item) cout << item << endl

#define PRINT_MENU(...)                           \
    do                                            \
    {                                             \
        vector<string> items = {__VA_ARGS__};     \
        for (size_t i = 0; i < items.size(); ++i) \
        {                                         \
            PRINT_MENU_ITEM(items[i]);            \
        }                                         \
    } while (0)

class Food
{
protected:
    int id;
    string name;
    int price;

public:
    Food();
    int getID();
    string getName();
    int getPrice();

    void setName(string name);
    void setPrice(int price);

    virtual void displayFood(int count) const;
};

typedef list<Food *>::iterator menuIndex_t;
typedef pair<Food *, menuIndex_t> foodInfoType_t;

class RestaurantManager
{
protected:
    vector<bool> tableStatus;
    list<Food *> menu;

public:
    foodInfoType_t searchFood(int id);
    void displayMenu() const;
};

#endif