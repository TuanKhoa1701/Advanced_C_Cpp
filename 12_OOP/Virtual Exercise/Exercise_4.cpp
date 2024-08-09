#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SERVICE_CONSTRUCTOR(className, typeName) \
    className::className()                       \
    {                                            \
        this->type = typeName;                   \
    }

#define SERVICE_GET_TYPE(className) \
    string className::getType()     \
    {                               \
        return this->type;          \
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

#define INPUT_STRING_INFO(message, property) \
    cin.ignore();                            \
    cout << message;                         \
    getline(cin, property)

#define INPUT_INFO(message, property) \
    cout << message;                  \
    cin >> property

#define CREATE_SERVICE(name, serviceType) \
    if (choseService == name)             \
    {                                     \
        service = new serviceType();      \
        validService = true;              \
    }

#define INPUT_SERVICE_INFO(message)                     \
    Service *service;                                   \
    string choseService;                                \
    bool validService = false;                          \
    INPUT_INFO(message, choseService);                  \
    CREATE_SERVICE("Oil", OilChange)                    \
    CREATE_SERVICE("Brake", BrakeInspection)            \
    CREATE_SERVICE("Battery", BatteryCheck)             \
    CREATE_SERVICE("AC", ACService)                     \
    CREATE_SERVICE("Transmission", TransmissionService) \
    CREATE_SERVICE("Headlight", HeadlightAdjustment)    \
    if (!validService)                                  \
        cout << "Invalid service" << endl;

class Service
{
protected:
    string type;

public:
    virtual void performService() const = 0;
    virtual string getType() = 0;
};

string Service::getType()
{
    return this->type;
}

class OilChange : public Service
{
public:
    void performService() const override;
    string getType() override;
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

SERVICE_CONSTRUCTOR(OilChange, "Oil Change")
SERVICE_GET_TYPE(OilChange)

class BrakeInspection : public Service
{
public:
    void performService() const override;
    string getType() override;
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

SERVICE_CONSTRUCTOR(BrakeInspection, "Brake Inspection")
SERVICE_GET_TYPE(BrakeInspection)

class BatteryCheck : public Service
{
public:
    void performService() const override;
    string getType() override;
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

SERVICE_CONSTRUCTOR(BatteryCheck, "Battery Check")
SERVICE_GET_TYPE(BatteryCheck)

class ACService : public Service
{
public:
    void performService() const override;
    string getType() override;
    ACService();
};

void ACService::performService() const
{
    PRINT_MENU("Performing AC service.",
               "Checking refrigerant levels...",
               "Inspecting AC components...",
               "Cleaning AC system...",
               "AC service completed.");
}

SERVICE_CONSTRUCTOR(ACService, "AC Service")
SERVICE_GET_TYPE(ACService)

class TransmissionService : public Service
{
public:
    void performService() const override;
    string getType() override;
    TransmissionService();
};

void TransmissionService::performService() const
{
    PRINT_MENU("Performing transmission service.",
               "Checking transmission fluid level...",
               "Inspecting transmission components...",
               "Changing transmission fluid...",
               "Transmission service completed.");
}

SERVICE_CONSTRUCTOR(TransmissionService, "Transmission Service")
SERVICE_GET_TYPE(TransmissionService)

class HeadlightAdjustment : public Service
{
public:
    void performService() const override;
    string getType() override;
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

SERVICE_CONSTRUCTOR(HeadlightAdjustment, "Headlight Adjustment")
SERVICE_GET_TYPE(HeadlightAdjustment)

class Car
{
protected:
    string model;
    int year;
    vector<Service *> services;

public:
    void displayInfo() const;
    void inputInfo();
    void addService(Service *service);
    void performServices() const;
};

void Car::displayInfo() const
{
    DISPLAY_INFO("Model: ", this->model);
    DISPLAY_INFO("Year of manufacture: ", this->year);
    cout << "--------------" << endl;
    cout << "Services list:" << endl;
    for (Service *item : services)
    {
        DISPLAY_INFO("- ", item->getType());
    }
    cout << "--------------" << endl;
}

void Car::inputInfo()
{
    INPUT_STRING_INFO("Enter the car model: ", this->model);
    INPUT_INFO("Enter the year of manufacture of the car: ", this->year);
    int serviceCount = 0;
    INPUT_INFO("Enter the amount of car services you want: ", serviceCount);
    for (serviceCount; serviceCount > 0; serviceCount--)
    {
        INPUT_SERVICE_INFO("Enter a car service: ")
        this->addService(service);
    }
}

void Car::addService(Service *service)
{
    services.push_back(service);
}

void Car::performServices() const
{
    for (Service *item : this->services)
    {
        item->performService();
    }
}

int main()
{
    vector<Car *> carDatabase;

    int count;
    string carType;
    INPUT_INFO("Enter the number of cars you want to add: ", count);
    for (count; count > 0; count--)
    {
        Car *car = new Car();
        car->inputInfo();
        carDatabase.push_back(car);
    }
    cout << "---------------" << endl;
    for (Car *item : carDatabase)
    {
        cout << "..............." << endl;
        item->displayInfo();
        item->performServices();
    }
    for (Car *item : carDatabase)
    {
        delete item;
    }
}