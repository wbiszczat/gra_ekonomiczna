#include <iostream>
#include <memory>

#include "game.hpp"
#include "company.hpp"
#include "employees/employees.hpp"


int main()
{
    std::cout << "Gra ekonomiczna!" << std::endl;
    
    //Game game;
    //game.run();

    Company company;

    auto weronia = std::unique_ptr<Employee>(new Engineer("Weronia"));
    company.hire(std::move(weronia));

    auto weronia2 = std::unique_ptr<Employee>(new Marketer("Wcale nie weronia"));
    company.hire(std::move(weronia2));

    company.list_employee();

    company.calc();

    return 0;
}
