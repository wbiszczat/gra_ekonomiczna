#include "company.hpp"
#include <iostream>

Company::Company():
    number_of_employees{0}, employees{new Employee*[MAX_EMPLOYEES]}
{
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        employees[i] = nullptr;
    }
    
}

Company::~Company()
{
    for (int i = 0; i < number_of_employees; i++)
    {
        delete employees[i];
    }
}

void Company::list_employee()
{
    std::cout << "Lista pracowników firmy:" << std::endl;
    for (int i = 0; i < number_of_employees; i++)
    {
        std::cout << i+1 << ": ";
        employees[i]->print();
    }
    
}

void Company::hire(std::unique_ptr<Employee>&& e)
{
    employees[number_of_employees++] = e.release();
}

void Company::calc()
{
    
}
