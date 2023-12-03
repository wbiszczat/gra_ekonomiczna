#pragma once

#include "employees/employee.hpp"
#include <memory>

constexpr int MAX_EMPLOYEES = 20;

class Company
{
public:

    Company();
    ~Company();

    /// @brief Funkcja wypisująca pracowników
    void list_employee();

    void hire(std::unique_ptr<Employee>&& e);

    /// @brief Wez kredyt
    /// @param debt_size wysokośc kredytu
    /// @param return_time_in_months czas spłaty w miesiacach 
    void take_credit(double debt_size, int return_time_in_months);

    /// @brief Funkcja kończąca miesiąc i przeliczająca go
    void calc();




private:
    int number_of_employees;
    std::unique_ptr<Employee*[]> employees;

    double money;
};