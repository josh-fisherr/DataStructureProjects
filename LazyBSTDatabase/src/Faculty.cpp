/// @file <Faculty.cpph>
/// @brief <Implements everything for Faculty and actually build's one with properties>
/// @author <Joshua Fisher>

/*
Faculty records are similar to student records and will be stored in a Faculty class. This class
will also require overloaded operators
Faculty records contain an integer Faculty ID, 
a string name, 
a string level (lecturer, assistant, prof, associate prof, etc.), 
a string department, 
and a list of integers corresponding to all of the faculty member’s advisees’ ids. 
These are the only fields the class contains
*/
#include "Faculty.h"
#include <iostream>

// Default constructor
Faculty::Faculty() {
    fID = 0;
    name = "";
    level = "";
    dept = "";
    advisees = nullptr;  // Initialize the advisees pointer
    numAdvisees = 0;  // Initialize the number of advisees
}

// Overloaded constructor
Faculty::Faculty(int id, const std::string& nm, const std::string& lvl, const std::string& department, int* adviseeIds, int adviseeCount) {
    fID = id;
    name = nm;
    level = lvl;
    dept = department;
    if (adviseeCount > 0 && adviseeIds != nullptr) {
        advisees = new int[adviseeCount];
        numAdvisees = adviseeCount;
        for (int i = 0; i < numAdvisees; i++) {
            advisees[i] = adviseeIds[i];
        }
    } else {
        advisees = nullptr;
        numAdvisees = 0;
    }
}

// Destructor
Faculty::~Faculty() {
    delete[] advisees;
}

// Accessors
int Faculty::getFacultyID() const {
    return fID;
}

std::string Faculty::getName() const {
    return name;
}

std::string Faculty::getLevel() const {
    return level;
}

std::string Faculty::getDepartment() const {
    return dept;
}

int Faculty::getNumAdvisees() const {
    return numAdvisees;
}

int* Faculty::getAdvisees() const {
    return advisees;
}

// Mutators
void Faculty::setFacultyID(int id) {
    fID = id;
}

void Faculty::setName(const std::string& nm) {
    name = nm;
}

void Faculty::setLevel(const std::string& lvl) {
    level = lvl;
}

void Faculty::setDepartment(const std::string& dpt) {
    dept = dpt;
}

void Faculty::setAdvisees(const int* adviseeIds, int adviseeCount) {
    delete[] advisees; // Clear the existing advisees
    if (adviseeCount > 0 && adviseeIds != nullptr) {
        advisees = new int[adviseeCount];
        numAdvisees = adviseeCount;
        for (int i = 0; i < numAdvisees; i++) {
            advisees[i] = adviseeIds[i];
        }
    } else {
        advisees = nullptr;
        numAdvisees = 0;
    }
}

//for comparing, found way online
bool Faculty::operator==(const Faculty& other) const {
    return this->fID == other.fID;
}

bool Faculty::operator<(const Faculty& other) const {
    return this->fID < other.fID;
}

bool Faculty::operator>(const Faculty& other) const {
    return this->fID > other.fID;
}

// Overloaded Output Operator for Printing Faculty Information
std::ostream& operator<<(std::ostream& os, const Faculty& faculty) {
    os << "Faculty ID: " << faculty.fID << ", "
       << "Name: " << faculty.name << ", "
       << "Level: " << faculty.level << ", "
       << "Department: " << faculty.dept << ", "
       << "Number of Advisees: " << faculty.numAdvisees;

    if (faculty.numAdvisees > 0 && faculty.advisees != nullptr) {
        os << ", Advisees IDs: ";
        for (int i = 0; i < faculty.numAdvisees; i++) {
            os << faculty.advisees[i];
            if (i < faculty.numAdvisees - 1) {
                os << ", ";
            }
        }
    }

    return os;
}
