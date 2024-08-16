#include "Header/main.hpp"
#include "Header/student.hpp"

Student::Student()
{
    static int id = 1;
    this->id = id;
    id++;

    this->math = -1;
    this->physics = -1;
    this->chemistry = -1;
}

void Student::inputInfo()
{
    // Input basic info
    this->setInfo("name");
    INPUT_INFO("Enter age: ", this->age);
    this->setInfo("gender");

    // Input grade
    INPUT_GRADE(math)
    INPUT_GRADE(physics)
    INPUT_GRADE(chemistry)

    // Calculate average and rank
    this->calculateAverage();
    this->getRank();
    cout << "-------------------------" << endl;
}

bool Student::isGradeValid(float grade)
{
    bool returnValue = false;
    if (grade < (float)0 || grade > (float)10)
        grade = -1;
    else
        returnValue = true;
    return returnValue;
}

void Student::displayInfo() const
{
    cout << "------------------------" << endl;
    cout << "ID:    " << this->id << endl;
    cout << "Name:  " << this->name << endl;
    cout << "Age:   " << this->age << endl;
    cout << "Gender:    " << this->gender << endl;
    cout << "    Math    |    Physics    |    Chemistry    " << endl;
    cout << "" << math << "" << physics << "" << chemistry << "" << endl;
    cout << "Average:   " << this->average << endl;
    cout << "Rank:   " << this->rank << endl;
}

void Student::calculateAverage()
{
    this->average = (this->math + this->physics + this->chemistry) / 3;
}

Rank Student::determineRank()
{
    if (this->average >= 9)
        return GIOI;
    else if (this->average >= 7)
        return KHA;
    else if (this->average >= 5)
        return TRUNG_BINH;
    else if (this->average >= 0)
        return YEU;
    else
        return UNKNOWN;
}

void Student::setInfo(const string &info)
{
    bool checkFlag = false;
    CHECK_PROPERTY(info, name, SET_STRING(name))
    CHECK_PROPERTY(info, gender, SET_STRING(gender))
    if (!checkFlag)
    {
        cout << "Invalid info" << endl;
        return;
    }
}

void Student::setGrade(const string &grade)
{
    bool checkFlag = false;
    CHECK_PROPERTY(grade, age, SET_GRADE(age))
    CHECK_PROPERTY(grade, math, SET_GRADE(math))
    CHECK_PROPERTY(grade, physics, SET_GRADE(physics))
    CHECK_PROPERTY(grade, chemistry, SET_GRADE(chemistry))
    CHECK_PROPERTY(grade, average, SET_GRADE(average))
    if (!checkFlag)
    {
        cout << "Invalid info" << endl;
        return;
    }
}

float Student::getGrade(const string &grade) const
{
    CHECK_PROPERTY(grade, math, GET_PROPERTY(math))
    CHECK_PROPERTY(grade, physics, GET_PROPERTY(physics))
    CHECK_PROPERTY(grade, chemistry, GET_PROPERTY(chemistry))
    CHECK_PROPERTY(grade, average, GET_PROPERTY(average))
    cout << "Invalid grade" << endl;
    return -1;
}

int Student::getID() const
{
    return this->id;
}

string Student::getString(const string &info) const
{
    CHECK_PROPERTY(info, name, GET_PROPERTY(name))
    CHECK_PROPERTY(info, gender, GET_PROPERTY(gender))
    cout << "Invalid info" << endl;
    return "";
}

string Student::getRank()
{
    Rank studentRank = this->determineRank();
    switch (studentRank)
    {
    case GIOI:
        this->rank = "GIOI";
        break;
    case KHA:
        this->rank = "KHA";
        break;
    case TRUNG_BINH:
        this->rank = "TRUNG BINH";
        break;
    case YEU:
        this->rank = "YEU";
        break;
    default:
        this->rank = "UNKNOWN";
        break;
    }
    return this->rank;
}
