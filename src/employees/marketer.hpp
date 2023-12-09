#pragma once
#include "employee.hpp"
#include <ctime> 

class Marketer : public Employee 
{
public:
    Marketer(std::string name);

    void print() override;

    static constexpr float CMkt = 100.0f;

private:
    static int generateFollowersNumber() 
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % 10001;
    }

    int followers;
};
