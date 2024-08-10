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

void StudentManager::updatedStudentInit()
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
            {
                item.setInfo("name");
            }
            break;
            // case 2:
            //     sv.updatedStudentInit();
            //     break;
            // case 3:
            //     sv.deleteStudentInit();
            //     break;
            // case 4:
            //     sv.findStudentInit();
            //     break;
            // case 5:
            // 	sv.sortStudentsByName();
            // 	sv.displayAllStudent();
            // 	break;
            // case 6:
            // 	sv.sortStudentsByAverage();
            // 	sv.displayAllStudent();
            // 	break;
            // case 7:
            // 	sv.sortStudentsById();
            // 	sv.displayAllStudent();
            // 	break;
            // case 6:
            //     sv.displayAllStudent();
            //     break;
            default:
                cout << "Invalid option" << endl;
                break;
            }
            break;
        }
    }
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
    return a.getString("name") < b.getString("name");
}

bool StudentManager::compareByGrade(const Student &a, const Student &b)
{
    return a.getGrade(currentGradeType) < b.getGrade(currentGradeType);
}

void StudentManager::sortByName()
{
    studentDatabase.sort(compareByName);
}

void StudentManager::sortByGrade(const string &gradeType)
{
    currentGradeType = gradeType;
    studentDatabase.sort(compareByGrade);
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