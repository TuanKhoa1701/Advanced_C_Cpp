#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CLASS_CONSTRUCTOR(className, typeName) \
    className::className()                     \
    {                                          \
        this->type = typeName;                 \
    }

#define PRINT_MENU_ITEM(item) cout << item << endl

#define PRINT_MENU(...)                        \
    do                                         \
    {                                          \
        vector<string> items = {__VA_ARGS__};  \
        for (int i = 0; i < items.size(); ++i) \
        {                                      \
            PRINT_MENU_ITEM(items[i]);         \
        }                                      \
        cout << "****************" << endl;    \
    } while (0)

#define DISPLAY_INFO(message, property) \
    cout << message << property << endl

#define DISPLAY_SERVICE()                    \
    cout << "--------------" << endl;        \
    cout << "Services list:" << endl;        \
    for (Service * item : services)          \
    {                                        \
        DISPLAY_INFO("- ", item->getType()); \
    }                                        \
    cout << "--------------" << endl;

#define INPUT_STRING_INFO(message, property) \
    cin.ignore();                            \
    cout << message;                         \
    getline(cin, property)

#define INPUT_INFO(message, property) \
    cout << message;                  \
    cin >> property

#define CREATE_SERVICE(name, serviceType)  \
    if (choseService == #name)             \
    {                                      \
        Service *name = new serviceType(); \
        this->addService(name);            \
        validService = true;               \
    }

#define INPUT_SERVICE_INFO()                                                 \
    int serviceCount = 0;                                                    \
    INPUT_INFO("How many services do you want to perform?: ", serviceCount); \
    for (serviceCount; serviceCount > 0; serviceCount--)                     \
    {                                                                        \
        string choseService;                                                 \
        bool validService = false;                                           \
        INPUT_INFO("Enter a service: ", choseService);                       \
        CREATE_SERVICE(Oil, OilChange)                                       \
        CREATE_SERVICE(Brake, BrakeInspection)                               \
        CREATE_SERVICE(Battery, BatteryCheck)                                \
        CREATE_SERVICE(AC, TransmissionRepair)                               \
        CREATE_SERVICE(Transmission, TransmissionRepair)                     \
        CREATE_SERVICE(Headlight, HeadlightAdjustment)                       \
        if (!validService)                                                   \
            cout << "Invalid service" << endl;                               \
    }

#define CREATE_VEHICLE(name, vehicleType, vehicleVector) \
    if (choseVehicle == #name)                           \
    {                                                    \
        Vehicle *(object##name) = new vehicleType();     \
        object##name->inputInfo();                       \
        vehicleVector.push_back(object##name);           \
        validVehicle = true;                             \
    }

class Service
{
protected:
    string type;

public:
    virtual void performService() const = 0;
    virtual string getType();
};

string Service::getType()
{
    return this->type;
}

class OilChange : public Service
{
public:
    void performService() const override;
    OilChange();
};

void OilChange::performService() const
{
    PRINT_MENU("Performing oil change service.",
               "Draining old oil...",
               "Replacing oil filter...",
               "Filling new oil...",
               "Oil change completed.");
}

CLASS_CONSTRUCTOR(OilChange, "Oil Change")

class BrakeInspection : public Service
{
public:
    void performService() const override;
    BrakeInspection();
};

void BrakeInspection::performService() const
{
    PRINT_MENU("Performing brake inspection service.",
               "Checking brake pads...",
               "Inspecting brake discs...",
               "Testing brake fluid...",
               "Brake inspection completed.");
}

CLASS_CONSTRUCTOR(BrakeInspection, "Brake Inspection")

class BatteryCheck : public Service
{
public:
    void performService() const override;
    BatteryCheck();
};

void BatteryCheck::performService() const
{
    PRINT_MENU("Performing battery check service.",
               "Testing battery voltage...",
               "Checking battery terminals...",
               "Inspecting battery condition...",
               "Battery check completed.");
}

CLASS_CONSTRUCTOR(BatteryCheck, "Battery Check")

class ACRepair : public Service
{
public:
    void performService() const override;
    ACRepair();
};

void ACRepair::performService() const
{
    PRINT_MENU("Performing AC service.",
               "Checking refrigerant levels...",
               "Inspecting AC components...",
               "Cleaning AC system...",
               "AC service completed.");
}

CLASS_CONSTRUCTOR(ACRepair, "AC Repair")

class TransmissionRepair : public Service
{
public:
    void performService() const override;
    TransmissionRepair();
};

void TransmissionRepair::performService() const
{
    PRINT_MENU("Performing transmission service.",
               "Checking transmission fluid level...",
               "Inspecting transmission components...",
               "Changing transmission fluid...",
               "Transmission service completed.");
}

CLASS_CONSTRUCTOR(TransmissionRepair, "Transmission Repair")

class HeadlightAdjustment : public Service
{
public:
    void performService() const override;
    HeadlightAdjustment();
};

void HeadlightAdjustment::performService() const
{
    PRINT_MENU("Performing headlight adjustment service.",
               "Inspecting headlight alignment...",
               "Adjusting headlight angles...",
               "Ensuring proper illumination...",
               "Headlight adjustment completed.");
}

CLASS_CONSTRUCTOR(HeadlightAdjustment, "Headlight Adjustment")

class Vehicle
{
protected:
    string type;
    string model;
    int year;
    vector<Service *> services;

public:
    virtual void displayInfo() const = 0;
    virtual void inputInfo() = 0;
    virtual string getType();
    void addService(Service *service);
    void performServices() const;
};

string Vehicle::getType()
{
    return this->type;
}

void Vehicle::addService(Service *service)
{
    services.push_back(service);
}

void Vehicle::performServices() const
{
    for (Service *item : this->services)
    {
        item->performService();
    }
}

class Car : public Vehicle
{
protected:
    string interiorMaterial;
    int seatCount;

public:
    void displayInfo() const override;
    void inputInfo() override;
    Car();
};

class Truck : public Vehicle
{
protected:
    int cargoCapacity;
    int payload;

public:
    void displayInfo() const override;
    void inputInfo() override;
    Truck();
};

class Motorcycle : public Vehicle
{
protected:
    string handlebarType;
    float weight;

public:
    void displayInfo() const override;
    void inputInfo() override;
    Motorcycle();
};

CLASS_CONSTRUCTOR(Car, "Car")

void Car::displayInfo() const
{
    DISPLAY_INFO("Vehicle type: ", this->type);
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Interior Material: ", this->interiorMaterial);
    DISPLAY_INFO("The amount of seats: ", this->seatCount);
    DISPLAY_SERVICE()
}

void Car::inputInfo()
{
    INPUT_STRING_INFO("Enter the car model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    INPUT_STRING_INFO("Enter the interior material in the car: ", this->interiorMaterial);
    INPUT_INFO("Enter the amount of seats in the car: ", this->seatCount);
    INPUT_SERVICE_INFO()
}

CLASS_CONSTRUCTOR(Truck, "Truck")

void Truck::displayInfo() const
{
    DISPLAY_INFO("Vehicle type: ", this->type);
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Cargo capacity: ", this->cargoCapacity);
    DISPLAY_INFO("Payload: ", this->payload);
    DISPLAY_SERVICE()
}

void Truck::inputInfo()
{
    INPUT_STRING_INFO("Enter the truck model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the truck: ", this->year);
    INPUT_INFO("Enter the payload of the truck: ", this->payload);
    INPUT_INFO("Enter the cargo capacity of the truck: ", this->cargoCapacity);
    INPUT_SERVICE_INFO()
}

CLASS_CONSTRUCTOR(Motorcycle, "Motorcycle")

void Motorcycle::displayInfo() const
{
    DISPLAY_INFO("Vehicle type: ", this->type);
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    DISPLAY_INFO("Handlebar type: ", this->handlebarType);
    DISPLAY_INFO("Weight: ", this->weight);
    DISPLAY_SERVICE()
}

void Motorcycle::inputInfo()
{
    INPUT_STRING_INFO("Enter the motorcycle model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the motorcycle: ", this->year);
    INPUT_INFO("Enter the handlebar type of the motorcycle: ", this->handlebarType);
    INPUT_INFO("Enter the weight of the motorcycle: ", this->weight);
    INPUT_SERVICE_INFO()
}

int main()
{
    vector<Vehicle *> vehicleDatabase;

    int count;
    string vehicleType;
    INPUT_INFO("Enter the number of vehicles you want to add: ", count);
    for (count; count > 0; count--)
    {
        string choseVehicle;
        bool validVehicle = false;
        cout << "-------------------" << endl;
        INPUT_INFO("Enter a vehicle type: ", choseVehicle);
        CREATE_VEHICLE(Car, Car, vehicleDatabase)
        CREATE_VEHICLE(Truck, Truck, vehicleDatabase)
        CREATE_VEHICLE(Motorcycle, Motorcycle, vehicleDatabase)
        if (!validVehicle)
            cout << "Invalid service" << endl;
    }
    cout << "---------------" << endl;
    for (Vehicle *item : vehicleDatabase)
    {
        cout << "..............." << endl;
        item->displayInfo();
        item->performServices();
    }
    for (Vehicle *item : vehicleDatabase)
    {
        delete item;
    }
}