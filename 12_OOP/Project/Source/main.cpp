#include "Header/student_manager.hpp"

int main()
{
    const char *filename = "student_database.csv";
    StudentManager sv;
    cout << "Student Manager" << endl;
    while (1)
    {
        int option = -1;
        cout << "................" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Update a student information" << endl;
        cout << "3. Delete a student" << endl;
        cout << "4. Find a student" << endl;
        cout << "5. Sort the list of students" << endl;
        cout << "6. Display the list of students" << endl;
        cout << "7. Save to a .csv file" << endl;
        cout << "0. Exit" << endl;
        INPUT_INFO("Choose an option: ", option);

        switch (option)
        {
        case 0:
            cout << "Thank you" << endl;
            return 0;
        case 1:
        {
            int continueOption = 1;
            while (continueOption == 1)
            {
                sv.addStudent();
                cout << "1. Add another student" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 2:
        {
            int continueOption = 1;
            while (continueOption == 1)
            {
                sv.updatedStudent();
                cout << "1. Update another student" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 3:
        {
            int continueOption = 1;
            while (continueOption == 1)
            {
                sv.deleteStudent();
                cout << "1. Delete another student" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 4:
        {
            int continueOption = 1;
            while (continueOption == 1)
            {
                sv.findStudent();
                cout << "1. Find another student" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 5:
        {
            int continueOption = 1;
            while (continueOption == 1)
            {
                sv.sortStudent();
                cout << "1. Sort by other type" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 6:
            sv.displayAllStudent();
            break;
        case 7:
            sv.saveToCSV(filename);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
}