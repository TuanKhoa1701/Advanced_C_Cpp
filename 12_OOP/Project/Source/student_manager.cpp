#include "Header/student_manager.hpp"

string StudentManager::currentGradeType = "";

void StudentManager::addStudent()
{
    Student sv;
    sv.inputInfo();
    this->studentDatabase.push_back(sv);
    sv.displayInfo();
    cout << "Added successfully" << endl;
}

void StudentManager::updatedStudent()
{
    int id;
    this->displayAllStudent();
    INPUT_INFO("Enter the ID of the student you want to update: ", id);
    for (Student &item : this->studentDatabase)
    {
        if (item.getID() == id)
        {
            item.displayInfo();
            int updateOption = -1;
            cout << "................" << endl;
            cout << "1. Update name" << endl;
            cout << "2. Update age" << endl;
            cout << "3. Update gender" << endl;
            cout << "4. Update math grade" << endl;
            cout << "5. Update physics grade" << endl;
            cout << "6. Update chemistry grade" << endl;
            cout << "0. Return" << endl;
            INPUT_INFO("Choose an option: ", updateOption);
            switch (updateOption)
            {
            case 0:
                break;
            case 1:
                item.setInfo("name");
                break;
            case 2:
                item.setGrade("age");
                break;
            case 3:
                item.setInfo("gender");
                break;
            case 4:
                item.setGrade("math");
                break;
            case 5:
                item.setGrade("physics");
                break;
            case 6:
                item.setGrade("chemistry");
                break;
            default:
                cout << "Invalid option" << endl;
                break;
            }
            cout << "Updated successfully" << endl;
            return;
        }
    }
    cout << "Can't find a student with a given ID" << endl;
    return;
}

void StudentManager::deleteStudent()
{
    int id;
    this->displayAllStudent();
    INPUT_INFO("Enter the ID of the student you want to delete: ", id);
    for (list<Student>::iterator it = this->studentDatabase.begin(); it != studentDatabase.end(); ++it)
    {
        if ((*it).getID() == id)
        {
            int updateOption = -1;
            (*it).displayInfo();
            cout << "Are you sure you want to delete this student?: " << endl;
            cout << "1. Yes" << endl;
            cout << "0. No" << endl;
            INPUT_INFO("Choose an option: ", updateOption);
            switch (updateOption)
            {
            case 0:
                return;
            case 1:
                this->studentDatabase.erase(it);
                break;
            }
            cout << "Deleted successfully" << endl;
            return;
        }
    }
    cout << "Can't find a student with a given ID" << endl;
    return;
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

list<Student *> StudentManager::findStudentByName(const string &name)
{
    list<Student *> foundStudent;
    for (Student &item : this->studentDatabase)
    {
        if (item.getString("name") == name)
        {
            foundStudent.push_back(&item);
        }
    }
    return foundStudent;
}

void StudentManager::findStudent()
{
    int findOption = -1;
    cout << "1. Search by name" << endl;
    cout << "2. Search by ID" << endl;
    cout << "0. Return" << endl;
    INPUT_INFO("Choose an option: ", findOption);
    switch (findOption)
    {
    case 0:
        break;
    case 1:
    {
        string name;
        INPUT_STRING_INFO("Enter the student's name you want to find: ", name);
        list<Student *> foundStudent = this->findStudentByName(name);
        for (Student *item : foundStudent)
        {
            item->displayInfo();
        }
        break;
    }
    case 2:
    {
        int id;
        INPUT_INFO("Enter the student's ID you want to find: ", id);
        Student *result = this->findStudentById(id);
        result->displayInfo();
        break;
    }
    }
}

bool StudentManager::compareByName(const Student &a, const Student &b)
{
    return a.getString("name") < b.getString("name");
}

bool StudentManager::compareByGrade(const Student &a, const Student &b)
{
    return a.getGrade(currentGradeType) < b.getGrade(currentGradeType);
}

void StudentManager::sortStudent()
{
    int sortOption = -1;
    cout << "1. Sort by name" << endl;
    cout << "2. Sort by math grade" << endl;
    cout << "3. Sort by physics grade" << endl;
    cout << "4. Sort by chemistry grade" << endl;
    cout << "5. Sort by average grade" << endl;
    cout << "0. Return" << endl;
    INPUT_INFO("Choose an option: ", sortOption);
    switch (sortOption)
    {
    case 0:
        break;
    case 1:
    {
        studentDatabase.sort(compareByName);
        cout << "Sorted successfully" << endl;
        this->displayAllStudent();
        break;
    }
    case 2:
    {
        currentGradeType = "math";
        studentDatabase.sort(compareByGrade);
        cout << "Sorted successfully" << endl;
        this->displayAllStudent();
        break;
    }
    case 3:
    {
        currentGradeType = "physics";
        studentDatabase.sort(compareByGrade);
        cout << "Sorted successfully" << endl;
        this->displayAllStudent();
        break;
    }
    case 4:
    {
        currentGradeType = "chemistry";
        studentDatabase.sort(compareByGrade);
        cout << "Sorted successfully" << endl;
        this->displayAllStudent();
        break;
    }
    case 5:
    {
        currentGradeType = "average";
        studentDatabase.sort(compareByGrade);
        cout << "Sorted successfully" << endl;
        this->displayAllStudent();
        break;
    }
    }
}

void StudentManager::saveToCSV(const char *filename)
{
    int number = 1;
    remove(filename);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "No.,ID,Name,Gender,Math,Physics,Chemistry,Average,Rank\n");
    for (Student &item : this->studentDatabase)
    {
        fprintf(fp, "%d,%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%s\n",
                number++,
                item.getID(),
                item.getString("name").c_str(),
                item.getString("gender").c_str(),
                item.getGrade("math"),
                item.getGrade("physics"),
                item.getGrade("chemistry"),
                item.getGrade("average"),
                item.getRank().c_str());
    }
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