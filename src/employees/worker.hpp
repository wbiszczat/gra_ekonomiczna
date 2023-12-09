#pragma once
#include "employee.hpp"
#include <iostream>

class Worker : public Employee 
{
public:
    Worker(std::string name, float shoe_size);

    void print() override;

    static constexpr int CR = 100;

private:
    float shoeSize;
};

