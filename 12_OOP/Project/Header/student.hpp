#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "utils.hpp"

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
    Grade grade;

public:
    Student();
    bool isGradeValid(float grade);
    void inputInfo();
    void displayInfo() const;
    void calculateAverage();
    Grade determineGrade();
    int getID() const;
    string getName() const;
    float getGrade(string grade) const;
};

#endif
