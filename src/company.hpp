#pragma once

#include "employees/employees.hpp"
#include "credit.hpp"
#include <memory>
#include <vector>

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

    std::vector<Credit> credits;

    float money = 30000.0f;

    static constexpr int N = 3;
    float company_value_history[N] = {0.0f};
    int company_value_history_iter = 0;

    /// @brief Funkcja obliczajaca srednia wartosc firmy z ostatnich N miesisecy
    /// @param company_value wartosc firmy w aktualnym miesiacy 
    /// @return srednia wartosc firmy
    float get_average_company_value(float company_value);
};