#pragma once
#include <string>

class Employee {
    
public:
    Employee(std::string name);

    virtual ~Employee() {}

    virtual void print();

    int get_payment() const { return payment; }

protected:
    int payment;

private:
    std::string _name;

};