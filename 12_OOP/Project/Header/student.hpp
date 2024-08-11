#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "main.hpp"

class Student
{
protected:
    int id;
    string name;
    int age;
    string gender;
    float math;
    float physics;
    float chemistry;
    float average;
    string rank;

public:
    Student();
    bool isGradeValid(float grade);
    void inputInfo();
    void displayInfo() const;
    void calculateAverage();
    Rank determineRank();

    void setInfo(const string &info);
    void setGrade(const string &grade);

    int getID() const;
    string getString(const string &info) const;
    float getGrade(const string &grade) const;
    string getRank();
};

#endif
