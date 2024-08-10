#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <string>
#include <list>
#include <variant>

using namespace std;

#define INPUT_STRING_INFO(message, property) \
	cin.ignore();                            \
	cout << message;                         \
	getline(cin, property)

#define INPUT_INFO(message, property) \
	cout << message;                  \
	cin >> property

#define INPUT_GRADE(gradeType)                                               \
	INPUT_INFO("Enter " #gradeType " grade: ", this->gradeType);             \
	while (!(this->isGradeValid(this->gradeType)))                           \
	{                                                                        \
		INPUT_INFO("Enter a valid " #gradeType " grade: ", this->gradeType); \
	}

#define CHECK_PROPERTY(infoType, propertyName, function) \
	if (infoType == #propertyName)                       \
	{                                                    \
		function                                         \
	}

#define GET_PROPERTY(propertyName) return this->propertyName;
#define SET_PROPERTY(propertyName)                         \
	checkFlag = true;                                      \
	string value;                                          \
	INPUT_STRING_INFO("Enter " #propertyName ": ", value); \
	this->propertyName = value;

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