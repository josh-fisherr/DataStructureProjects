/// @file <DataInterface.h>
/// @brief <The header for DataInterface.h>
/// @author <Joshua Fisher>
#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <iostream>
#include <fstream>
#include "Student.h"
#include "Faculty.h"
#include "LazyBST.h"

class DatabaseInterface {
private:
    LazyBST<Student> students;
    LazyBST<Faculty> faculty;

public:
    DatabaseInterface();
    void run(); // Main loop for the menu
    void printAllStudents();
    void printAllFaculty();
    void findStudentByID();
    void findFacultyByID();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeStudentAdvisor();
    void removeAdviseeFromFaculty();
    void exit();

    
};

#endif
