#include "Header/student_manager.hpp"

void StudentManager::addStudent()
{
    Student sv;
    sv.inputInfo();
    this->studentDatabase.push_back(sv);
    cout << "Added successfully" << endl;
}

void StudentManager::addStudentInit()
{
    int count;
    cout << "Enter the amount students hat you want to add: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        this->addStudent();
    }
    cout << "Completed Addition" << endl;
}

void StudentManager::updateStudentById(const int id)
{
    for (Student &item : this->studentDatabase)
    {
        if (item.getID() == id)
        {
            item.inputInfo();
            break;
        }
    }
}

void StudentManager::updatedStudentInit()
{
    int id;
    cout << "Enter the ID of the student you want to update: ";
    cin >> id;
    this->updateStudentById(id);
    cout << "Updated successfully" << endl;
}

void StudentManager::deleteStudentById(const int id)
{
    for (list<Student>::iterator it = this->studentDatabase.begin(); it != studentDatabase.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            this->studentDatabase.erase(it);
            break;
        }
    }
}

void StudentManager::deleteStudentInit()
{
    int id;
    cout << "Enter the ID of the student you want to delete: ";
    cin >> id;
    this->deleteStudentById(id);
    cout << "Deleted successfully" << endl;
}

Student *StudentManager::findStudentById(const int id)
{
    Student *result = NULL;
    for (Student &item : this->studentDatabase)
    {
        if (item.getID() == id)
        {
            result = &item;
            break;
        }
    }
    return result;
}

void StudentManager::findStudentInit()
{
    int id;
    cout << "Enter the ID of the student you want to find: ";
    cin >> id;
    Student *result = this->findStudentById(id);
    cout << "Student found" << endl;
    result->displayInfo();
}

bool StudentManager::compareByName(const Student &a, const Student &b)
{
    return a.getName() < b.getName();
}

bool StudentManager::compareByGrade(const Student &a, const Student &b,
                                    string grade)
{
}

void StudentManager::sortByName()
{
    studentDatabase.sort(compareByName);
}

void StudentManager::displayAllStudent() const
{
    cout << "Students count: " << this->studentDatabase.size() << endl;
    cout << "****************" << endl;
    for (Student item : this->studentDatabase)
    {
        item.displayInfo();
        cout << "....................." << endl;
    }
}