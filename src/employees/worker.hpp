#pragma once
#include "employee.hpp"
#include <iostream>

class Worker : public Employee 
{
public:
    Worker(std::string name, float shoe_size);

    void print() override;

    static constexpr float CR = 100.0f;

private:
    int payment = 4000;
    float shoeSize;
};

