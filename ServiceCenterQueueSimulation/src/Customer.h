/// @file Customer.h
/// @brief Declaration of the Customer class.
/// @author Joshua Fisher & Anela Quiroz

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
using namespace std;

class ServiceCenter;  // Forward declaration to resolve circular dependency

class Customer {
public:
    Customer(const string& serviceSpec, ServiceCenter* center);
    ~Customer();

    bool hasMoreServices() const;
    int getNextServiceTime() const;
    char getNextOffice() const;
    void completeService();
    int getCurrentServiceTime() const;

private:
    int* serviceTimes;
    char* officeOrder;
    int numServices;
    int currentServiceIndex;
};

#endif
