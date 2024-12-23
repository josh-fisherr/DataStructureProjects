#ifndef WINDOW_H
#define WINDOW_H

class Customer;  // Assuming Customer is declared somewhere else

class Window {
public:
    Window();
    ~Window();
    
    bool isOpen() const;
    void setIdle(bool idle);
    int getIdleTime() const;
    void incrementIdleTime();
    void resetIdleTime();

    int getServiceTime() const;
    void setServiceTime(int time);

    void setCurrentCustomer(Customer* customer);
    Customer* getCurrentCustomer() const;

    void setIsIdle(bool idle);  // Setter for isIdle
    void updateServiceTime(int time);  // Setter for serviceTime

private:
    bool isIdle;
    int idleTime;
    int serviceTime;
    Customer* currentCustomer;
};

#endif 
