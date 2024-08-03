#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DISPLAY_INFO(message, property) \
    cout << message << property << endl;

#define DISPLAY_BOOLEAN_INFO(message, property) \
    cout << message;                            \
    if (property)                               \
    {                                           \
        cout << "Yes" << endl;                  \
    }                                           \
    else                                        \
        cout << "No" << endl;

#define INPUT_STRING_INFO(message, property) \
    cin.ignore();                            \
    cout << message;                         \
    getline(cin, property);

#define INPUT_INFO(message, property) \
    cout << message;                  \
    cin >> property;

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
    DISPLAY_INFO("Model: ", this->model)
    DISPLAY_INFO("Year of manufacture: ", this->year)
    DISPLAY_INFO("Interior Material: ", this->interiorMaterial)
    DISPLAY_BOOLEAN_INFO("Have sunroof?: ", this->sunroof)
}

void Sedan::inputInfo()
{
    INPUT_STRING_INFO("Enter the Sedan model: ", this->model)
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year)
    INPUT_STRING_INFO("Enter the Sedan interior material: ", this->interiorMaterial)
    INPUT_INFO("Do the Sedan have sunroof? [1/0]: ", this->sunroof)
}

void SUV::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model)
    DISPLAY_INFO("Year of manufacture: ", this->year)
    DISPLAY_BOOLEAN_INFO("Have AWD?: ", this->allWheelDrive)
    DISPLAY_INFO("Cargo capacity: ", this->cargoCapacity)
}

void SUV::inputInfo()
{
    INPUT_STRING_INFO("Enter the SUV model: ", this->model)
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year)
    INPUT_INFO("Do the Sedan have AWD? [1/0]: ", this->allWheelDrive)
    INPUT_INFO("Enter the cargo capacity of the car: ", this->cargoCapacity)
}

int main()
{
    vector<Car *> carDatabase;

    int count;
    string carType;
    cout << "Enter the number of cars you want to add: ";
    cin >> count;
    for (count; count > 0; count--)
    {
        cout << "Choose a car type: ";
        cin >> carType;
        if (carType == "Sedan")
        {
            Car *sedan = new Sedan();
            sedan->inputInfo();
            carDatabase.push_back(sedan);
        }
        else if (carType == "SUV")
        {
            Car *suv = new SUV();
            suv->inputInfo();
            carDatabase.push_back(suv);
        }
        else
        {
            cout << "Invalid car type" << endl;
            count++;
        }
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