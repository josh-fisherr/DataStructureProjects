#include "Office.h"
#include "Window.h"
#include "Customer.h"

Office::Office(int windows) : numWindows(windows) {
    officeWindows = new Window*[windows];
    for (int i = 0; i < windows; ++i) {
        officeWindows[i] = new Window();
    }
}

Office::~Office() {
    for (int i = 0; i < numWindows; ++i) {
        delete officeWindows[i];
    }
    delete[] officeWindows;
}

void Office::assignCustomerToWindow(Customer* customer) {
    for (int i = 0; i < numWindows; ++i) {
        if (officeWindows[i]->getCurrentCustomer() == nullptr) {
            officeWindows[i]->setCurrentCustomer(customer);
            officeWindows[i]->setIsIdle(false);
            officeWindows[i]->updateServiceTime(customer->getCurrentServiceTime());
            break;
        }
    }
}
