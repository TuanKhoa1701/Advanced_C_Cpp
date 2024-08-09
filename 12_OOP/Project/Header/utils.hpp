#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <string>
#include <list>

using namespace std;

#define DEFINITION_COMPARE_STUDENT(field)                                                            \
	DECLARATION_COMPARE_STUDENT(field)                                                               \
	{                                                                                                \
		if (#field == "Average" || #field == "Math" || #field == "Chemistry" || #field == "Physics") \
		{                                                                                            \
			return (a.getGrade(field) < b.getGrade(field));                                          \
		}                                                                                            \
		else                                                                                         \
			return (a.get##field() < b.get##field());                                                \
	}

#define DECLARATION_COMPARE_STUDENT(field) \
	bool compareBy##field(const Student &a, const Student &b)

#define CHECK_GRADE(name)  \
	if (grade == #name)    \
	{                      \
		return this->name; \
	}

typedef enum Grade
{
	GIOI,
	KHA,
	TRUNG_BINH,
	YEU,
	UNKNOWN
} Grade;

#endif