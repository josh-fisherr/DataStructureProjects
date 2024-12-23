/// @file Customer.cpp
/// @brief Implementation of the Customer class.
/// @author Joshua Fisher & Anela Quiroz

#include "Customer.h"
#include "ServiceCenter.h"

Customer::Customer(const string& serviceSpec, ServiceCenter* center){
    // Count the number of services
    currentServiceIndex = 0;
    numServices = 0;
    std::stringstream ss(serviceSpec);
    int tempTime;
    char tempChar;
    while (ss >> tempTime >> tempChar) {
        numServices++;
    }

    // Allocate memory based on count
    serviceTimes = new int[numServices];
    officeOrder = new char[numServices];

    // Reset stream and populate arrays
    ss.clear();
    ss.str(serviceSpec);
    int index = 0;
    while (ss >> serviceTimes[index] >> officeOrder[index]) {
        index++;
    }
}

Customer::~Customer() {
    delete[] serviceTimes;
    delete[] officeOrder;
}

bool Customer::hasMoreServices() const {
    return currentServiceIndex < numServices;
}

int Customer::getNextServiceTime() const {
    if (hasMoreServices()) {
        return serviceTimes[currentServiceIndex];
    }
    return 0; 
}

int Customer::getCurrentServiceTime() const {
    if (currentServiceIndex < numServices) {
        return serviceTimes[currentServiceIndex]; // Return the current service time
    }
    return 0; // Return 0 if no current service time is available (e.g., all services completed)
}


char Customer::getNextOffice() const {
    if (hasMoreServices()) {
        return officeOrder[currentServiceIndex];
    }
    return '\0'; 
}

void Customer::completeService() {
    if (hasMoreServices()) {
        currentServiceIndex++;
    }
}
