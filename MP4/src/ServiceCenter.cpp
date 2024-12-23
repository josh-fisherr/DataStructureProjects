/// @file ServiceCenter.cpp
/// @brief Implementation of the ServiceCenter class.
/// @author Joshua Fisher & Anela Quiroz
#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <iostream>

ServiceCenter::ServiceCenter() {
    offices = new Office*[3];  // Allocating space for three office pointers
    registrar = nullptr;
    cashier = nullptr;
    financial = nullptr;
}

ServiceCenter::~ServiceCenter() {
    delete registrar;
    delete cashier;
    delete financial;
    delete[] offices;  // Deleting the array of office pointers
}

void ServiceCenter::processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Error opening input file: " << inputFile << endl;
        return;
    }

    int rWindowsOpen, cWindowsOpen, fWindowsOpen;
    inFile >> rWindowsOpen >> cWindowsOpen >> fWindowsOpen;

    // Initialize offices based on the number of windows open
    registrar = new Office(rWindowsOpen);
    offices[0] = registrar;
    cashier = new Office(cWindowsOpen);
    offices[1] = cashier;
    financial = new Office(fWindowsOpen);
    offices[2] = financial;

    // Process student arrivals
    int arrivalTime, numStudents;
    while (inFile >> arrivalTime >> numStudents) {  // Read each time block
        for (int i = 0; i < numStudents; ++i) {
            string serviceDetails;
            getline(inFile, serviceDetails);  // Get the complete line for service times and office order
            if (!serviceDetails.empty()) {
                Customer* newCustomer = new Customer(serviceDetails, this);
                assignCustomerToOffices(newCustomer);
            }
        }
    }
}

void ServiceCenter::assignCustomerToOffices(Customer* customer) {
    // Assign customers based on their first required office
    char firstOffice = customer->getNextOffice();
    switch (firstOffice) {
        case 'R':
            registrar->addCustomer(customer);
            break;
        case 'C':
            cashier->addCustomer(customer);
            break;
        case 'F':
            financial->addCustomer(customer);
            break;
        default:
            cerr << "Invalid office code encountered: " << firstOffice << endl;
    }
}
