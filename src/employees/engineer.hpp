#pragma once
#include "employee.hpp"

class Engineer : public Employee 
{
public:
    Engineer(std::string name);

    void print() override;

    static constexpr float CI = 100.0f;

private:
    int payment = 6000;
};

