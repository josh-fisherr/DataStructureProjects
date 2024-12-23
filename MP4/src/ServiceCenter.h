/// @file ServiceCenter.h
/// @brief Declaration of the ServiceCenter class.
/// @author Joshua Fisher & Anela Quiroz
#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include <string>

class ServiceCenter {
public:
    ServiceCenter(); // Constructor
    ~ServiceCenter(); // Destructor

    void processFile(const std::string& inputFile, const std::string& outputFile);
    void assignCustomerToOffices(Customer* customer);
    Office* getOffice(int index) const; // Retrieves an Office pointer based on index
    void advanceTime(); // Advances the time in the simulation, processing queues, etc.

private:
    Office **offices; // Array to hold pointers to Office objects
    Office *registrar; // Pointer to the registrar's office
    Office *cashier; // Pointer to the cashier's office
    Office *financial; // Pointer to the financial aid office
};

#endif // SERVICECENTER_H
