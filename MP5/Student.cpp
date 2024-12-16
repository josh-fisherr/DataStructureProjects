/// @file <Student.cpp>
/// @brief <Builds the instance for our Student and with the neccesary inclusions>
/// @author <Joshua Fisher>
#include "Student.h"

// Default constructor
Student::Student(){
    sID = 0;
    name = "";
    level = "";
    major = "";
    GPA = 0.0;
    advisorField = 0;
}

// Overloaded constructor
Student::Student(int id, std::string nm, std::string lvl, std::string mj, double gpa, int advisorId){
    sID = id;
    name = nm;
    level = lvl;
    major = mj;
    GPA = gpa;
    advisorField = advisorId;
}

//Found online to make the operators work
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student ID: " << student.sID << ", "
       << "Name: " << student.name << ", "
       << "Level: " << student.level << ", "
       << "Major: " << student.major << ", "
       << "GPA: " << student.GPA << ", "
       << "Advisor ID: " << student.advisorField;
    return os;
}

// Destructor
Student::~Student() {}

// Accessors 
int Student::getStudentID() const {
    return sID;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getLevel() const {
    return level;
}

std::string Student::getMajor() const {
    return major;
}

double Student::getGPA() const {
    return GPA;
}

int Student::getAdvisorField() const {
    return advisorField;
}

// Mutators 
void Student::setStudentID(int studentID) {
    sID = studentID;
}

void Student::setName(std::string sName) {
    name = sName;
}

void Student::setLevel(std::string sLevel) {
    level = sLevel;
}

void Student::setMajor(std::string sMajor) {
    major = sMajor;
}

void Student::setGPA(double sGPA) {
    GPA = sGPA;
}

void Student::setAdvisorField(int sAdvisorField) {
    advisorField = sAdvisorField;
}

// Overloaded Operators for Comparisons based on the ID of a student, found online how to do
bool Student::operator==(const Student& other) const {
    return sID == other.sID;
}

bool Student::operator<(const Student& other) const {
    return sID < other.sID;
}

bool Student::operator>(const Student& other) const {
    return sID > other.sID;
}
