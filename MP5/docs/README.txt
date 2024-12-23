MP5: Lazy Binary Search Tree and Database Management

Overview

This project implements a Lazy Binary Search Tree (LazyBST) and a database management system for organizing and managing student and faculty records. It demonstrates the use of advanced data structures and object-oriented programming principles in C++.

Features

Lazy Binary Search Tree (LazyBST):

Optimized insertion, lazy deletion, and searching.

Efficient for managing dynamic datasets.

Database Functionality:

Add, delete, and update student and faculty records.

Search records by unique identifiers.

Modular Design:

Key components: Student, Faculty, DataInterface, and LazyBST.

Clean and reusable object-oriented structure.

Setup

Prerequisites

Compiler: A C++ compiler (e.g., g++) installed on your system.

Steps

Clone this repository:

git clone <repository-url>
cd <repository-folder>

Compile the program:

g++ *.cpp -o lazybst_program

Run the program:

./lazybst_program

Usage

Commands Overview:

Add, delete, update, and search for records.

Use the command-line interface to input data and retrieve results.

Example Commands

Adding a Student Record

Enter command: ADD_STUDENT
Enter details: John Doe, ID: 12345, Advisor: Dr. Smith
Record added successfully!

Searching for a Record

Enter command: SEARCH
Enter ID: 12345
Result: John Doe, Faculty Advisor: Dr. Smith

Project Structure

|-- src/
|   |-- LazyBST.h        # Header file for Lazy Binary Search Tree
|   |-- LazyBST.cpp      # Implementation of Lazy Binary Search Tree
|   |-- Student.h        # Header file for Student class
|   |-- Student.cpp      # Implementation of Student class
|   |-- Faculty.h        # Header file for Faculty class
|   |-- Faculty.cpp      # Implementation of Faculty class
|   |-- DataInterface.h  # Header file for interface between BST and database
|   |-- DataInterface.cpp# Implementation of the interface
|   |-- main.cpp         # Main driver program
|-- README.md

Technologies Used

Programming Language: C++

Core Concepts:

Lazy Binary Search Tree

Object-Oriented Programming
