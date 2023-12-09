#pragma once
#include "employee.hpp"
#include <cstdlib>

class Warehouseman : public Employee 
{
public:
    Warehouseman(std::string name);

    void print() override;

    static constexpr float CMag = 100.0f;

private:
    bool udt;
};

