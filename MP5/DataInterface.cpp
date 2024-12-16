/// @file <DataInterface.cpp>
/// @brief <Used to create the options and use our functions>
/// @author <Joshua Fisher>
#include "DataInterface.h"
#include <iostream>

DatabaseInterface::DatabaseInterface() {
}

void DatabaseInterface::run() {
    bool running = true;
    while (running) {
        std::cout << "Database Menu:\n"
                  << "1. Print all students and their information\n"
                  << "2. Print all faculty and their information\n"
                  << "3. Find and display student information by ID\n"
                  << "4. Find and display faculty information by ID\n"
                  << "5. Add a new student\n"
                  << "6. Delete a student by ID\n"
                  << "7. Add a new faculty member\n"
                  << "8. Delete a faculty member by ID\n"
                  << "9. Change a student’s advisor\n"
                  << "10. Remove an advisee from a faculty member\n"
                  << "11. Exit\n"
                  << "Enter your choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            // Clear error flags and ignore the rest of the line to fix the bad input, found online since I couldn't stop the infinite loop
            std::cin.clear();
            std::cin.ignore(choice > 11);
            std::cout << "Invalid input. Please enter a number.\n";
            continue; // Restart the loop to show the menu again
        }
        switch (choice) {
            case 1:
                printAllStudents();
                break;
            case 2:
                printAllFaculty();
                break;
            case 3:
                findStudentByID();
                break;
            case 4:
                findFacultyByID();
                break;
            case 5:
                addStudent();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                addFaculty();
                break;
            case 8:
                deleteFaculty();
                break;
            case 9:
                changeStudentAdvisor();
                break;
            case 10:
                removeAdviseeFromFaculty();
                break;
            case 11:
                exit();
                running = false;
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void DatabaseInterface::printAllStudents() {
   students.printTree(); //using the LazyBST function to print the tree
}

void DatabaseInterface::printAllFaculty() {
    faculty.printTree(); //using the LazyBST function to print the tree
}

void DatabaseInterface::findStudentByID() {
    int id;
    std::cout << "Enter student ID: ";
    std::cin >> id;

    Student searchStudent(id, "", "", "", 0, 0); //needed to only look by the ID
    TreeNode<Student>* foundNode = students.searchTree(searchStudent);
    if (foundNode) {
        Student& foundStudent = foundNode->key;
        std::cout << "Student found: " << foundStudent << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }
}

void DatabaseInterface::findFacultyByID() {
    int id;
    std::cout << "Enter Faculty ID: ";
    std::cin >> id;

    Faculty searchFaculty(id, "", "", "", 0, 0); //needed to only look by the ID
    TreeNode<Faculty>* foundNode = faculty.searchTree(searchFaculty); 
    if (foundNode) {
        Faculty& foundFaculty = foundNode->key;
        std::cout << "Faculty found: " << foundFaculty << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }
}

void DatabaseInterface::addStudent() {
    int id;
    std::string name;
    std::string level;
    std::string major;
    double gpa;
    int advisorId;

    // Prompt for student details
    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear the newline character from the buffer

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student level (e.g., Freshman, Sophomore): ";
    std::getline(std::cin, level);

    std::cout << "Enter student major: ";
    std::getline(std::cin, major);

    std::cout << "Enter student GPA: ";
    std::cin >> gpa;

    std::cout << "Enter advisor ID: ";
    std::cin >> advisorId;
    // Ensure the faculty exists before setting it as an advisor
    Faculty searchFaculty(advisorId, "", "", "", nullptr, 0);
    if (!faculty.contains(searchFaculty)) {
        std::cout << "Advisor with ID " << advisorId << " does not exist. Student not added.\n";
        return;
    }

    // Create a new Student object
    Student newStudent(id, name, level, major, gpa, advisorId);

    // Insert the new student into the LazyBST of students
    students.insert(newStudent);

    std::cout << "Student added successfully." << std::endl;
}

void DatabaseInterface::deleteStudent() {
    int id;
    std::cin >> id;

    // Have to find it first
    Student searchStudent(id, "", "", "", 0, 0);

    // Check if the student exists
    if (students.contains(searchStudent)){
        students.deleteNode(searchStudent);
        std::cout << "Student with ID " << id << " has been successfully deleted." << std::endl;
    } else {
        std::cout << "No student found with ID " << id << "." << std::endl;
    }
}

void DatabaseInterface::addFaculty() {
    int id;
    std::string name;
    std::string level;
    std::string dept;
    const int MAX_ADVISEES = 50;  // Maximum number of advisees we can input
    int tempAdvisees[MAX_ADVISEES];
    int numAdvisees = 0;
    int tempId;

    // Prompt for faculty details
    std::cout << "Enter Faculty ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear the newline character from the buffer

    std::cout << "Enter Faculty name: ";
    std::getline(std::cin, name);

    std::cout << "Enter faculty level (e.g., lecturer, assistant prof, associate prof, etc.): ";
    std::getline(std::cin, level);

    std::cout << "Enter Faculty's Department: ";
    std::getline(std::cin, dept);

    std::cout << "Enter Faculty's advisee IDs (enter -1 when done): ";
    while (true) {
        std::cin >> tempId;
        if (tempId == -1) break;
        // Validate the student ID before adding it to the temporary advisees array
        Student searchStudent(tempId, "", "", "", 0, 0);
        if (students.contains(searchStudent)) {
            if (numAdvisees < MAX_ADVISEES) {
                tempAdvisees[numAdvisees++] = tempId;
            } else {
                std::cout << "Reached maximum number of advisees. Stopping input." << std::endl;
                break;
            }
        } else {
            std::cout << "No student found with ID " << tempId << ", skipping." << std::endl;
        }
    }

    // Allocate a dynamic array with the exact number of valid advisees
    int* adviseesArray = new int[numAdvisees];
    for (int i = 0; i < numAdvisees; i++) {
        adviseesArray[i] = tempAdvisees[i];
    }

    // Create a new Faculty object
    Faculty newFaculty(id, name, level, dept, adviseesArray, numAdvisees);
    delete[] adviseesArray; // Clean up the dynamically allocated array after use

    // Insert the new faculty into the LazyBST of faculty
    faculty.insert(newFaculty);

    std::cout << "Faculty added successfully." << std::endl;
}

void DatabaseInterface::deleteFaculty() {
    int id;
    std::cin >> id;

    Faculty searchFaculty(id, "", "", "", 0, 0);
     if (faculty.contains(searchFaculty)){
        faculty.deleteNode(searchFaculty);
        std::cout << "Faculty with ID " << id << " has been successfully deleted." << std::endl;
    } else {
        std::cout << "No Faculty found with ID " << id << "." << std::endl;
    }

    std::cout << "Faculty " << id << " has been succesfully deleted! ";
}

void DatabaseInterface::changeStudentAdvisor() {
    //Get the studentID and the newAdvisorID
    int studentID;
    int newAdvisorID;
    std::cout << "Enter the student ID: ";
    std::cin >> studentID;
    std::cout << "Enter the new advisor's ID: ";
    std::cin >> newAdvisorID;
    
    // Create a search student object
    Student searchStudent(studentID, "", "", "", 0, 0);
    TreeNode<Student>* studentNode = students.searchTree(searchStudent);

    if (studentNode != nullptr) {
        // Get the student from the node
        Student foundStudent = studentNode->key;

        // Change the advisor ID
        foundStudent.setAdvisorField(newAdvisorID);

        // You may need to reinsert the student to update the tree if required
        students.deleteNode(searchStudent); // Remove the old student record
        students.insert(foundStudent); // Insert the updated student record

        std::cout << "Advisor changed successfully." << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }

}

void DatabaseInterface::removeAdviseeFromFaculty() {
    int facultyID;
    int studentID;
    std::cout << "Enter the faculty ID: ";
    std::cin >> facultyID;
    std::cout << "Enter the student ID to remove: ";
    std::cin >> studentID;

    // Find the faculty member
    Faculty searchFaculty(facultyID, "", "", "", nullptr, 0);
    TreeNode<Faculty>* facultyNode = faculty.searchTree(searchFaculty);
    if (!facultyNode) {
        std::cout << "Faculty not found." << std::endl;
        return;
    }

    Faculty& foundFaculty = facultyNode->key;
    int numAdvisees = foundFaculty.getNumAdvisees();
    int* oldAdvisees = foundFaculty.getAdvisees();
    int* newAdvisees = new int[numAdvisees]; // Allocate a new array to hold updated list of advisees
    int newCount = 0;

    // Copy all advisees except the one to be removed
    for (int i = 0; i < numAdvisees; i++) {
        if (oldAdvisees[i] != studentID) {
            newAdvisees[newCount++] = oldAdvisees[i];
        }
    }

    if (newCount == numAdvisees) { // Check if the student was not found among advisees
        std::cout << "Student ID " << studentID << " not found among the advisees of Faculty ID " << facultyID << "." << std::endl;
        delete[] newAdvisees; // Cleanup if no changes are made
        return;
    }

    // Update the faculty member's advisees list
    foundFaculty.setAdvisees(newAdvisees, newCount);
    delete[] newAdvisees; // Cleanup the temporary array

    // Update the faculty member in the BST
    faculty.deleteNode(searchFaculty); // Remove the old faculty record
    faculty.insert(foundFaculty); // Insert the updated faculty record

    std::cout << "Advisee removed successfully from Faculty ID " << facultyID << "." << std::endl;
}

void DatabaseInterface::exit() {
    std::cout << "Goodbye! " << std::endl;
}

/*void DatabaseInterface::exitAndSave() {
    This was going to be for exit and saving to file but couldn't get it working, was searching online for this to be able to make it work properly
    std::ofstream outFile("runLog.txt");
    if (!outFile) {
        std::cerr << "Failed to open runLog.txt for writing.\n";
        return;
    }

    outFile << "Students:\n";
    saveTreeData(outFile, students.getRoot());
    outFile << "\nFaculty:\n";
    saveTreeData(outFile, faculty.getRoot());

    outFile.close();
    std::cout << "Data saved to runLog.txt. Goodbye!\n";
} */