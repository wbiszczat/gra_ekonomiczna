#include "employee.hpp"
#include <iostream>

Employee::Employee(std::string name)
    : _name{name}
{}

void Employee::print() 
{
    std::cout << "Nazywam się " << _name << ". Zarabiam " << payment << " PLN. ";
}
