#include "Header/manager.hpp"

void Manager::setTable()
{
    // Input table count
    int tableCount;
    INPUT_INFO("Enter number of table: ", tableCount);

    // Initialize table status
    tableStatus.resize(tableCount);
    for (bool item : tableStatus)
    {
        item = false;
    }

    // Print success message
    PRINT_MENU("------------------",
               "Set up the number of tables to serve successfully");
}

void Manager::addFood()
{
    // Input food info
    string name;
    int price;
    INPUT_STRING_INFO("Enter food name: ", name);
    INPUT_INFO("Enter the price of the food: ", price);

    // Initialize new food
    Food *newFood = new Food();
    newFood->setName(name);
    newFood->setPrice(price);

    // Add new food to food list
    this->menu.push_back(newFood);
    cout << "Food info:" << endl;
    newFood->displayFood(this->menu.size());
    PRINT_MENU("------------------",
               "Added new food successfully");
}

void Manager::editFood()
{
    // Print menu
    cout << "Menu:" << endl;
    this->displayMenu();

    int id;
    INPUT_INFO("Enter food ID you want to edit: ", id);

    // Search food
    foodInfoType_t foundFood = this->searchFood(id);

    // Display found food info
    cout << "--------------------" << endl;
    if (foundFood.first != NULL)
    {
        int newPrice;
        foundFood.first->displayFood(1);

        // Input and save new price
        INPUT_INFO("Enter new price: ", newPrice);
        foundFood.first->setPrice(newPrice);

        // Print success message
        PRINT_MENU("------------------",
                   "Updated food info successfully");
    }
    else
    {
        cout << "Food not found with the given ID" << endl;
    }
}

void Manager::removeFood()
{
    // Print menu
    cout << "Menu:" << endl;
    this->displayMenu();

    int id;
    INPUT_INFO("Enter food ID you want to delete: ", id);

    // Search food
    foodInfoType_t foundFood = this->searchFood(id);

    // Display found food info
    cout << "--------------------" << endl;
    if (foundFood.first != NULL)
    {
        foundFood.first->displayFood(1);

        // Delete the food from the menu
        this->menu.erase(foundFood.second);

        // Print success message
        PRINT_MENU("------------------",
                   "Deleted food successfully");
    }
    else
    {
        cout << "Food not found with the given ID" << endl;
    }
}