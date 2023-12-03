#pragma once
#include <string>

class Employee {
public:
    Employee(std::string name);

    virtual ~Employee() {}

    virtual void print();

private:
    std::string _name;
};