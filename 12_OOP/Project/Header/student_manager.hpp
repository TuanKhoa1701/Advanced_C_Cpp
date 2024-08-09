// #ifndef __STUDENT_MANAGER_HPP__
// #define __STUDENT_MANAGER_HPP__

// #include "utils.hpp"
// #include "student.hpp"

// typedef bool (*CompareFunc)(const Student &, const Student &);

// class StudentManager
// {
// private:
// 	list<Student> studentDatabase;

// public:
// 	void addStudent();
// 	void addStudentInit();
// 	void updateStudentById(const int id);
// 	void updatedStudentInit();
// 	void deleteStudentById(const int id);
// 	void deleteStudentInit();
// 	Student *findStudentById(const int id);
// 	void findStudentInit();
// 	DECLARATION_COMPARE_STUDENT(name);
// 	DECLARATION_COMPARE_STUDENT(math);
// 	DECLARATION_COMPARE_STUDENT(physics);
// 	DECLARATION_COMPARE_STUDENT(chemistry);
// 	DECLARATION_COMPARE_STUDENT(average);
// 	void sortStudent(CompareFunc compareFunc);
// 	void displayAllStudent() const;
// };

// #endif