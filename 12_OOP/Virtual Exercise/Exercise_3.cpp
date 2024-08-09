#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DISPLAY_INFO(message, property) \
    cout << message << property << endl

#define DISPLAY_BOOLEAN_INFO(message, property) \
    cout << message;                            \
    if (property)                               \
    {                                           \
        cout << "Yes" << endl;                  \
    }                                           \
    else                                        \
        cout << "No" << endl

#define INPUT_STRING_INFO(message, property) \
    cin.ignore();                            \
    cout << message;                         \
    getline(cin, property)

#define INPUT_INFO(message, property) \
    cout << message;                  \
    cin >> property

class Vehicle
{
protected:
    string model;
    int year;

public:
    virtual void displayInfo() const = 0;
    virtual void inputInfo() = 0;
};

class Car : public Vehicle
{
protected:
    string interiorMaterial;
    int seatCount;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

class Truck : public Vehicle
{
protected:
    int cargoCapacity;
    int payload;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

void Car::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Interior Material: ", this->interiorMaterial);
    DISPLAY_INFO("The amount of seats: ", this->seatCount);
}

void Car::inputInfo()
{
    INPUT_STRING_INFO("Enter the car model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_STRING_INFO("Enter the interior material in the car: ", this->interiorMaterial);
    INPUT_INFO("Enter the amount of seats in the car: ", this->seatCount);
}

void Truck::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Cargo capacity: ", this->cargoCapacity);
    DISPLAY_INFO("Payload: ", this->payload);
}

void Truck::inputInfo()
{
    INPUT_STRING_INFO("Enter the truck model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the truck: ", this->year);
    INPUT_INFO("Enter the payload of the truck: ", this->payload);
    INPUT_INFO("Enter the cargo capacity of the truck: ", this->cargoCapacity);
}

int main()
{
    vector<Vehicle *> vehicleDatabase;

    int count;
    string vehicleType;
    INPUT_INFO("Enter the number of vehicles you want to add: ", count);
    for (count; count > 0; count--)
    {
        INPUT_INFO("Choose a vehicle type: ", vehicleType);
        if (vehicleType == "Car")
        {
            Vehicle *car = new Car();
            car->inputInfo();
            vehicleDatabase.push_back(car);
        }
        else if (vehicleType == "Truck")
        {
            Vehicle *truck = new Truck();
            truck->inputInfo();
            vehicleDatabase.push_back(truck);
        }
        else
        {
            cout << "Invalid vehicle type" << endl;
            count++;
        }
    }
    cout << "---------------" << endl;
    for (Vehicle *item : vehicleDatabase)
    {
        cout << "..............." << endl;
        item->displayInfo();
    }
    for (Vehicle *item : vehicleDatabase)
    {
        delete item;
    }
}