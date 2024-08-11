#ifndef __STUDENT_MANAGER_HPP__
#define __STUDENT_MANAGER_HPP__

#include "main.hpp"
#include "student.hpp"

class StudentManager
{
private:
    list<Student> studentDatabase;
    static string currentGradeType;

public:
    void addStudent();
    void updatedStudent();
    void deleteStudent();
    Student *findStudentById(const int id);
    list<Student *> findStudentByName(const string &name);
    void findStudent();
    static bool compareByName(const Student &a, const Student &b);
    static bool compareByGrade(const Student &a, const Student &b);
    void sortStudent();
    void saveToCSV(const char *filename);
    void displayAllStudent() const;
};

#endif