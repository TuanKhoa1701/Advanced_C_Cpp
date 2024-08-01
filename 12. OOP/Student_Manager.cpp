#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum
{
	GIOI,
	KHA,
	TRUNG_BINH,
	YEU,
	UNKNOWN
} Grade;

class Student
{
private:
	int id;
	string name;
	float math;
	float physics;
	float chemistry;
	float average;
	Grade grade;

public:
	Student();
	int checkGrade(float grade);
	void inputInfo();
	void displayInfo() const;
	float calculateAverage();
	Grade determineGrade();
	int getID();
	string getName();
};

class StudentManager
{
private:
	vector<Student> studentDatabase;

public:
	void addStudent();
	void addStudentInit();
	void updateStudentById(const int id);
	void updatedStudentInit();
	void deleteStudentById(const int id);
	void deleteStudentInit();
	Student *findStudentById(const int id);
	void findStudentInit();
	void sortStudentsByName();
	void sortStudentsByAverage();
	void sortStudentsById();
	void displayAllStudent() const;
};

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
	cout << "Enter student's name: ";
	cin >> this->name;

	// Input math grade
	cout << "Enter student's math grade: ";
	cin >> this->math;
	while (this->checkGrade(this->math) < 0)
	{
		cout << "Enter a valid student's math grade: ";
		cin >> this->math;
	}

	// Input physics grade
	cout << "Enter student's physics grade: ";
	cin >> this->physics;
	while (this->checkGrade(this->physics) < 0)
	{
		cout << "Enter a valid student's physics grade: ";
		cin >> this->physics;
	}

	// Input chemistry grade
	cout << "Enter student's chemistry grade: ";
	cin >> this->chemistry;
	while (this->checkGrade(this->chemistry) < 0)
	{
		cout << "Enter a valid student's chemistry grade: ";
		cin >> this->chemistry;
	}
	this->average = this->calculateAverage();
	this->grade = this->determineGrade();
	cout << "-------------------------" << endl;
}

int Student::checkGrade(float grade)
{
	int returnValue = -1;
	if (grade < (float)0 || grade > (float)10)
		grade = -1;
	else
		returnValue = 1;
	return returnValue;
}

void Student::displayInfo() const
{
	cout << "ID: " << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "Math: " << this->math << endl;
	cout << "Physics: " << this->physics << endl;
	cout << "Chemistry: " << this->chemistry << endl;
	cout << "Average: " << this->average << endl;
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

float Student::calculateAverage()
{
	this->average = (this->math + this->physics + this->chemistry) / 3;
	return this->average;
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

int Student::getID()
{
	return this->id;
}

string Student::getName()
{
	return this->name;
}

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
	for (int i = 0; i < this->studentDatabase.size(); i++)
	{
		if (studentDatabase[i].getID() == id)
		{
			this->studentDatabase.erase(this->studentDatabase.begin() + i);
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

void StudentManager::sortStudentsByName()
{
	for (int i = 0; i < this->studentDatabase.size() - 1; i++)
	{
		for (int j = 0; j < this->studentDatabase.size() - i - 1; j++)
		{
			if (studentDatabase[j].getName() > studentDatabase[j + 1].getName())
			{
				swap(studentDatabase[j], studentDatabase[j + 1]);
			}
		}
	}
	cout << "Sort by name completed" << endl;
}

void StudentManager::sortStudentsByAverage()
{
	for (int i = 0; i < this->studentDatabase.size() - 1; i++)
	{
		for (int j = 0; j < this->studentDatabase.size() - i - 1; j++)
		{
			if (studentDatabase[j].calculateAverage() < studentDatabase[j + 1].calculateAverage())
			{
				swap(studentDatabase[j], studentDatabase[j + 1]);
			}
		}
	}
	cout << "Sort by average grade completed" << endl;
}

void StudentManager::sortStudentsById()
{
	for (int i = 0; i < this->studentDatabase.size() - 1; i++)
	{
		for (int j = 0; j < this->studentDatabase.size() - i - 1; j++)
		{
			if (studentDatabase[j].getID() > studentDatabase[j + 1].getID())
			{
				swap(studentDatabase[j], studentDatabase[j + 1]);
			}
		}
	}
	cout << "Sort by ID completed" << endl;
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

int main()
{
	StudentManager sv;
	cout << "Student Manager" << endl;
	while (1)
	{
		int option = -1;
		cout << "................" << endl;
		cout << "1. Add a student" << endl;
		cout << "2. Update a student information by ID" << endl;
		cout << "3. Delete a student by ID" << endl;
		cout << "4. Find a student by ID" << endl;
		cout << "5. Sort the list of students by Name and display that list" << endl;
		cout << "6. Sort the list of students by Average grade and display that list" << endl;
		cout << "7. Sort the list of students by ID and display that list" << endl;
		cout << "8. Display all the list of students" << endl;
		cout << "0. Exit" << endl;
		cout << "Choose an option: ";
		cin >> option;

		switch (option)
		{
		case 0:
			cout << "Thank you" << endl;
			exit(1);
		case 1:
			sv.addStudentInit();
			break;
		case 2:
			sv.updatedStudentInit();
			break;
		case 3:
			sv.deleteStudentInit();
			break;
		case 4:
			sv.findStudentInit();
			break;
		case 5:
			sv.sortStudentsByName();
			sv.displayAllStudent();
			break;
		case 6:
			sv.sortStudentsByAverage();
			sv.displayAllStudent();
			break;
		case 7:
			sv.sortStudentsById();
			sv.displayAllStudent();
			break;
		case 8:
			sv.displayAllStudent();
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}