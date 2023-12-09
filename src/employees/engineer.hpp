#pragma once
#include "employee.hpp"

class Engineer : public Employee 
{
public:
    Engineer(std::string name);

    void print() override;

    static constexpr float CI = 200.0f;

private:
    std::string alma_mater;
};

