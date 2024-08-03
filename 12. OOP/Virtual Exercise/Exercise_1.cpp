#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    cout << "Model: " << this->model << endl;
    cout << "Year of manufacture: " << this->year << endl;
    cout << "Interior Material: " << this->interiorMaterial << endl;
    cout << "Have sunroof?: ";
    if (this->sunroof)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

void Sedan::inputInfo()
{
    cin.ignore();
    cout << "Enter the Sedan model: ";
    getline(cin, this->model);
    cout << "Enter the year of manufacture of the car: ";
    cin >> this->year;
    cin.ignore();
    cout << "Enter the Sedan interior material: ";
    getline(cin, this->interiorMaterial);
    cout << "Do the Sedan have sunroof? [1/0]: ";
    cin >> this->sunroof;
}

void SUV::displayInfo() const
{
    cout << "Model: " << this->model << endl;
    cout << "Year of manufacture: " << this->year << endl;
    cout << "Have AWD?: ";
    if (this->allWheelDrive)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    cout << "Cargo capacity: " << this->cargoCapacity << endl;
}

void SUV::inputInfo()
{
    cin.ignore();
    cout << "Enter the SUV model: ";
    getline(cin, this->model);
    cout << "Enter the year of manufacture of the car: ";
    cin >> this->year;
    cin.ignore();
    cout << "Do the Sedan have AWD? [1/0]: ";
    cin >> this->allWheelDrive;
    cout << "Enter the cargo capacity of the car: ";
    cin >> this->cargoCapacity;
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