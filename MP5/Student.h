/// @file <Student.h>
/// @brief <Header file for Student.cpp>
/// @author <Joshua Fisher>

/*
Student records will be stored in a Student class. 
Student records contain 
a unique student ID (an integer), 
a string name field, 
a string level field (Freshman, Sophomore, etc.), 
a string major field, 
double GPA field
integer advisor field (which will contain the Faculty ID of their advisor) 
These are the only fields the class contains.
The Student class must overload equality, less than, greater than operators, etc., so that we can
compare them to one another.
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
public:
    Student(); // Default constructor
    Student(int id, std::string nm, std::string lvl, std::string mj, double gpa, int advisorId); // Parameterized constructor
    ~Student(); // Destructor

    // Accessors (Getters)
    int getStudentID() const;
    std::string getName() const;
    std::string getLevel() const;
    std::string getMajor() const;
    double getGPA() const;
    int getAdvisorField() const;

    // Mutators (Setters)
    void setStudentID(int studentID);
    void setName(std::string sName);
    void setLevel(std::string sLevel);
    void setMajor(std::string sMajor);
    void setGPA(double sGPA);
    void setAdvisorField(int sAdvisorField);

    // Overloaded Operators for Comparisons based on the ID of a student, found online to be able to use the operators
    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student); //found online makes the operator's work to access private members
private:
    int sID; // Student ID
    std::string name; // Student name
    std::string level; // Student grade level (e.g., Freshman)
    std::string major; // Student major
    double GPA; // Student GPA
    int advisorField; // Faculty ID of Advisor
};

#endif 
