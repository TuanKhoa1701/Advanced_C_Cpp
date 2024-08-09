#include "Header/utils.hpp"
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
    cout << "Enter name: ";
    cin >> this->name;

    cout << "Enter age: ";
    cin >> this->age;

    cout << "Enter gender: ";
    cin >> this->gender;

    // Input math grade
    cout << "Enter math grade: ";
    cin >> this->math;
    while (this->isGradeValid(this->math) < 0)
    {
        cout << "Enter a valid math grade: ";
        cin >> this->math;
    }

    // Input physics grade
    cout << "Enter physics grade: ";
    cin >> this->physics;
    while (this->isGradeValid(this->physics) < 0)
    {
        cout << "Enter a valid physics grade: ";
        cin >> this->physics;
    }

    // Input chemistry grade
    cout << "Enter chemistry grade: ";
    cin >> this->chemistry;
    while (this->isGradeValid(this->chemistry) < 0)
    {
        cout << "Enter a valid chemistry grade: ";
        cin >> this->chemistry;
    }
    this->calculateAverage();
    this->grade = this->determineGrade();
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
    cout << "ID:    " << this->id << endl;
    cout << "Name:  " << this->name << endl;
    cout << "Age:   " << this->age << endl;
    cout << "Gender:    " << this->gender << endl;
    cout << "   Math    |   Physics |   Chemistry   " << endl;
    cout << "   " << math << " |  " << physics << "   |   " << chemistry << "  " << endl;
    cout << "Average:   " << this->average << endl;
    switch (this->grade)
    {
    case GIOI:
        cout << "Grade: GIOI" << endl;
        break;
    case KHA:
        cout << "Grade: KHA" << endl;
        break;
    case TRUNG_BINH:
        cout << "Grade: TRUNG BINH" << endl;
        break;
    case YEU:
        cout << "Grade: YEU" << endl;
        break;
    default:
        cout << "Grade: UNKNOWN" << endl;
        break;
    }
}

void Student::calculateAverage()
{
    this->average = (this->math + this->physics + this->chemistry) / 3;
}

Grade Student::determineGrade()
{
    if (this->average >= 9)
        this->grade = GIOI;
    else if (this->average >= 7)
        this->grade = KHA;
    else if (this->average >= 5)
        this->grade = TRUNG_BINH;
    else if (this->average >= 0)
        this->grade = YEU;
    else
        this->grade = UNKNOWN;
    return this->grade;
}

float Student::getGrade(string grade) const
{
    CHECK_GRADE(math)
    CHECK_GRADE(physics)
    CHECK_GRADE(chemistry)
    CHECK_GRADE(average)
    else
    {
        cout << "Invalid grade type" << endl;
        return -1;
    }
}

int Student::getID() const
{
    return this->id;
}

string Student::getName() const
{
    return this->name;
}
