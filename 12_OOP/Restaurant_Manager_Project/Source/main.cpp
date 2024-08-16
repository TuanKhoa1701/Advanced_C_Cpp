#include "Header/manager.hpp"
#include "Header/staff.hpp"

int main()
{
    Manager sv;
    cout << "Student Manager" << endl;
    while (1)
    {
        int option = -1;
        cout << "................" << endl;
        cout << "1. Set table" << endl;
        cout << "2. Add food" << endl;
        cout << "3. Edit food" << endl;
        cout << "4. Remove food" << endl;
        cout << "5. Display menu" << endl;
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
                sv.setTable();
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
                sv.addFood();
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
                sv.editFood();
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
                sv.removeFood();
                cout << "1. Find another student" << endl;
                cout << "0. Return" << endl;
                INPUT_INFO("Choose an option: ", continueOption);
            }
            break;
        }
        case 5:
            sv.displayMenu();
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}