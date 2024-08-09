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
    int checkGrade(float grade);
    void inputInfo();
    void displayInfo() const;
    void calculateAverage();
    Grade determineGrade();
    // auto getID() const;
    // auto getName() const;
    // auto getAverage() const;
    // auto getMath() const;
    // auto getPhysics() const;
    // auto getChemistry() const;
    auto getProperty(string property) const;
};

#endif
