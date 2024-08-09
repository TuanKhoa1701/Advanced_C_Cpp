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

#define INPUT_ENGINE_INFO(message)           \
    string choseEngine;                      \
    INPUT_STRING_INFO(message, choseEngine); \
    if (choseEngine == "Petrol")             \
    {                                        \
        engine = new PetrolEngine();         \
    }                                        \
    else if (choseEngine == "Diesel")        \
    {                                        \
        engine = new DieselEngine();         \
    }                                        \
    else if (choseEngine == "Electric")      \
    {                                        \
        engine = new ElectricEngine();       \
    }                                        \
    else                                     \
        cout << "Invalid engine" << endl;    \
    engine->inputInfo();                     \
    engine->setType(choseEngine)

class Engine
{
protected:
    string type;

public:
    virtual void displayInfo() const = 0;
    virtual void inputInfo() = 0;
    void setType(string type);
};

class PetrolEngine : public Engine
{
protected:
    float fuelTankCapacity;
    bool turboCharged;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

class DieselEngine : public Engine
{
protected:
    float torque;
    bool intercooler;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

class ElectricEngine : public Engine
{
protected:
    float batteryCapacity;
    int maxRange;

public:
    void displayInfo() const override;
    void inputInfo() override;
};

class Car
{
protected:
    string model;
    int year;
    Engine *engine;

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

void Engine::setType(string type)
{
    this->type = type;
}

void PetrolEngine::inputInfo()
{
    INPUT_INFO("Enter the fuel tank capacity of the engine: ", this->fuelTankCapacity);
    INPUT_INFO("Do the engine have turbo charged? [1/0]: ", this->turboCharged);
}

void DieselEngine::inputInfo()
{
    INPUT_INFO("Enter the torque of the engine: ", this->torque);
    INPUT_INFO("Do the engine have intercooler? [1/0]: ", this->intercooler);
}

void ElectricEngine::inputInfo()
{
    INPUT_INFO("Enter the battery capacity of the engine: ", this->batteryCapacity);
    INPUT_INFO("Enter the max travel range of the engine: ", this->maxRange);
}

void PetrolEngine::displayInfo() const
{
    DISPLAY_INFO("Type: ", this->type);
    DISPLAY_INFO("Fuel tank capacity: ", this->fuelTankCapacity);
    DISPLAY_BOOLEAN_INFO("Have turbo charged?[1/0]: ", this->turboCharged);
}

void DieselEngine::displayInfo() const
{
    DISPLAY_INFO("Type: ", this->type);
    DISPLAY_INFO("Torque: ", this->torque);
    DISPLAY_BOOLEAN_INFO("Have intercooler?[1/0]: ", this->intercooler);
}

void ElectricEngine::displayInfo() const
{
    DISPLAY_INFO("Type: ", this->type);
    DISPLAY_INFO("Battery Capacity: ", this->batteryCapacity);
    DISPLAY_INFO("Max range: ", this->maxRange);
}

void Sedan::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Interior Material: ", this->interiorMaterial);
    DISPLAY_BOOLEAN_INFO("Have sunroof?: ", this->sunroof);
    engine->displayInfo();
}

void Sedan::inputInfo()
{
    INPUT_STRING_INFO("Enter the Sedan model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_STRING_INFO("Enter the Sedan interior material: ", this->interiorMaterial);
    INPUT_INFO("Do the Sedan have sunroof? [1/0]: ", this->sunroof);
    INPUT_ENGINE_INFO("Enter an engine type: ");
}

void SUV::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_BOOLEAN_INFO("Have AWD?: ", this->allWheelDrive);
    DISPLAY_INFO("Cargo capacity: ", this->cargoCapacity);
    engine->displayInfo();
}

void SUV::inputInfo()
{
    INPUT_STRING_INFO("Enter the SUV model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_INFO("Do the Sedan have AWD? [1/0]: ", this->allWheelDrive);
    INPUT_INFO("Enter the cargo capacity of the car: ", this->cargoCapacity);
    INPUT_ENGINE_INFO("Enter an engine type: ");
}

int main()
{
    vector<Car *> carDatabase;

    int count;
    string carType;
    INPUT_INFO("Enter the number of cars you want to add: ", count);
    for (count; count > 0; count--)
    {
        INPUT_INFO("Choose a car type: ", carType);
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