#ifndef __STUDENT_MANAGER_HPP__
#define __STUDENT_MANAGER_HPP__

#include "utils.hpp"
#include "student.hpp"

class StudentManager
{
private:
    list<Student> studentDatabase;

public:
    void addStudent();
    void addStudentInit();
    void updateStudentById(const int id);
    void updatedStudentInit();
    void deleteStudentById(const int id);
    void deleteStudentInit();
    Student *findStudentById(const int id);
    void findStudentInit();
    bool compareByName(const Student &a, const Student &b);
    bool compareByGrade(const Student &a, const Student &b, string field);
    void sortByName();
    void sortByGrade();
    void displayAllStudent() const;
};

#endif