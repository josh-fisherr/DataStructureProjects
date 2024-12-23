#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "ListQueue.h"  // Ensure ListQueue is included
#include "Window.h"
#include <iostream>

class Office {
public:
    Office(int windows);
    ~Office();

    void assignCustomerToWindow(Customer* customer);
    void addCustomer(Customer* customer);  // Declaration of new method

    Window** getWindows() const;
    int findLongestTime(Window** windowsArray, int numWindows) const;
    double findMeanTime(Window** windowsArray, int numWindows) const;

    int getNumWindows() const { return numWindows; }
    ListQueue<Customer>* getLine() const { return line; }  // Make sure ListQueue is correctly used

private:
    Window** officeWindows;
    ListQueue<Customer> *line;  // Using ListQueue to manage customers
    int numWindows;
    int longestIdleTime;
    int meanTime;
};

#endif // OFFICE_H
