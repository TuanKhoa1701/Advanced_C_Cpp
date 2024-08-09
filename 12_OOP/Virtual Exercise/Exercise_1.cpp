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

#define CREATE_VEHICLE(name, vehicleType, vehicleVector) \
    if (choseVehicle == #name)                           \
    {                                                    \
        Car *(object##name) = new vehicleType();         \
        object##name->inputInfo();                       \
        vehicleVector.push_back(object##name);           \
        validVehicle = true;                             \
    }

class Car
{
protected:
    string model;
    int year;

public:
    virtual void displayInfo() const = 0;
    virtual void inputInfo() = 0;
};

class Sedan : public Car
{
protected:
    string interiorMaterial;
    bool sunroof;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

class SUV : public Car
{
protected:
    bool allWheelDrive;
    int cargoCapacity;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

void Sedan::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Interior Material: ", this->interiorMaterial);
    DISPLAY_BOOLEAN_INFO("Have sunroof?: ", this->sunroof);
}

void Sedan::inputInfo()
{
    INPUT_STRING_INFO("Enter the Sedan model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_STRING_INFO("Enter the Sedan interior material: ", this->interiorMaterial);
    INPUT_INFO("Do the Sedan have sunroof? [1/0]: ", this->sunroof);
}

void SUV::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_BOOLEAN_INFO("Have AWD?: ", this->allWheelDrive);
    DISPLAY_INFO("Cargo capacity: ", this->cargoCapacity);
}

void SUV::inputInfo()
{
    INPUT_STRING_INFO("Enter the SUV model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_INFO("Do the Sedan have AWD? [1/0]: ", this->allWheelDrive);
    INPUT_INFO("Enter the cargo capacity of the car: ", this->cargoCapacity);
}

int main()
{
    vector<Car *> carDatabase;

    int count;
    string carType;
    INPUT_INFO("Enter the number of cars you want to add: ", count);
    for (count; count > 0; count--)
    {
        string choseVehicle;
        bool validVehicle = false;
        cout << "-------------------" << endl;
        INPUT_INFO("Enter a vehicle type: ", choseVehicle);
        CREATE_VEHICLE(Sedan, Sedan, carDatabase)
        CREATE_VEHICLE(SUV, SUV, carDatabase)
        if (!validVehicle)
            cout << "Invalid service" << endl;
    }
    cout << "---------------" << endl;
    for (Car *item : carDatabase)
    {
        cout << "..............." << endl;
        item->displayInfo();
    }
    for (Car *item : carDatabase)
    {
        delete item;
    }
}