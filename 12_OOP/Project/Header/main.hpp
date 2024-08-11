#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <string>
#include <list>

using namespace std;

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

#define INPUT_STRING_INFO(message, property) \
	cin.ignore();                            \
	cout << message;                         \
	getline(cin, property)

#define INPUT_INFO(message, property) \
	cout << message;                  \
	cin >> property

#define INPUT_GRADE(gradeType)                     \
	this->setGrade(#gradeType);                    \
	while (!(this->isGradeValid(this->gradeType))) \
	{                                              \
		this->setGrade(#gradeType);                \
	}

#define CHECK_PROPERTY(infoType, propertyName, function) \
	if (infoType == #propertyName)                       \
	{                                                    \
		function                                         \
	}

#define GET_PROPERTY(propertyName) return this->propertyName;
#define SET_STRING(stringName)                           \
	checkFlag = true;                                    \
	string value;                                        \
	INPUT_STRING_INFO("Enter " #stringName ": ", value); \
	this->stringName = value;

#define SET_GRADE(gradeName)                     \
	checkFlag = true;                            \
	float value;                                 \
	INPUT_INFO("Enter " #gradeName ": ", value); \
	this->gradeName = value;

#define COMPARE_GRADE(field)                                                \
	bool StudentManager::compareByGrade(const Student &a, const Student &b) \
	{                                                                       \
		return a.getGrade(field) < b.getGrade(field);                       \
	}

void continueOption(string message);

typedef enum Rank
{
	GIOI,
	KHA,
	TRUNG_BINH,
	YEU,
	UNKNOWN
} Rank;

#endif