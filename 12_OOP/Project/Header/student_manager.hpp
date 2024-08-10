#ifndef __STUDENT_MANAGER_HPP__
#define __STUDENT_MANAGER_HPP__

#include "utils.hpp"
#include "student.hpp"

class StudentManager
{
private:
    list<Student> studentDatabase;
    static string currentGradeType;

public:
    void addStudent();
    void updatedStudentInit();
    void deleteStudentById(const int id);
    void deleteStudentInit();
    Student *findStudentById(const int id);
    void findStudentInit();
    static bool compareByName(const Student &a, const Student &b);
    static bool compareByGrade(const Student &a, const Student &b);
    void sortByName();
    void sortByGrade(const string &gradeType);
    void saveToCSV(const char *filename);
    void displayAllStudent() const;
};

#endif