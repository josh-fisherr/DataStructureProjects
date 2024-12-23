#include "Window.h"
#include "Customer.h"

Window::Window() : isIdle(true), idleTime(0), serviceTime(0), currentCustomer(nullptr) {}

Window::~Window() {}

bool Window::isOpen() const {
    return currentCustomer != nullptr;
}

void Window::setIdle(bool idle) {
    isIdle = idle;
}

int Window::getIdleTime() const {
    return idleTime;
}

void Window::incrementIdleTime() {
    if (isIdle) {
        idleTime++;
    }
}

void Window::resetIdleTime() {
    idleTime = 0;
}

int Window::getServiceTime() const {
    return serviceTime;
}

void Window::setServiceTime(int time) {
    serviceTime = time;
}

void Window::setCurrentCustomer(Customer* customer) {
    currentCustomer = customer;
    isIdle = (customer == nullptr);
}

Customer* Window::getCurrentCustomer() const {
    return currentCustomer;
}

void Window::setIsIdle(bool idle) {
    isIdle = idle;
}

void Window::updateServiceTime(int time) {
    serviceTime = time;
}
