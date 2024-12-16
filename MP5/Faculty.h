/// @file <Faculty.h>
/// @brief <The header for Faculty.cpp>
/// @author <Joshua Fisher>
#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>

class Faculty {
public:
    Faculty();  // Default constructor
    Faculty(int id, const std::string& nm, const std::string& lvl, const std::string& dept, int* adviseeIds, int adviseeCount);  // Overloaded constructor
    ~Faculty();  // Destructor

    // Accessors (Getters)
    int getFacultyID() const;
    std::string getName() const;
    std::string getLevel() const;
    std::string getDepartment() const;
    int* getAdvisees() const;  // Returns the list of advisee IDs
    int getNumAdvisees() const;  // Returns the number of advisees

    // Mutators (Setters)
    void setFacultyID(int id);
    void setName(const std::string& nm);
    void setLevel(const std::string& lvl);
    void setDepartment(const std::string& dept);
    void setAdvisees(const int* adviseeIds, int adviseeCount);  // Set the advisee IDs using a dynamic array

    // Overloaded Operators for Comparisons and Printing
    friend std::ostream& operator<<(std::ostream& os, const Faculty& faculty);  // Overloaded output operator for printing faculty information
    bool operator==(const Faculty& other) const;  // Compare faculties based on their ID
    bool operator<(const Faculty& other) const;  // Compare faculties based on their ID for sorting
    bool operator>(const Faculty& other) const;  // Compare faculties based on their ID for sorting

private:
    int fID;  // Faculty ID
    std::string name;  // Faculty name
    std::string level;  // Faculty level (e.g., Lecturer, Assistant Professor)
    std::string dept;  // Faculty department
    int* advisees;  // Dynamic array to hold advisee IDs
    int numAdvisees;  // Number of advisees
};

#endif 
