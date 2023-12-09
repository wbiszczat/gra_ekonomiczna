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

    auto weronia3 = std::unique_ptr<Employee>(new Worker("CC",42.0));
    company.hire(std::move(weronia3));

    auto weronia4 = std::unique_ptr<Employee>(new Warehouseman("DD"));
    company.hire(std::move(weronia4));

    company.list_employee();

    company.calc();
    company.calc();
    company.take_credit(15000,3);
    company.take_credit(25000,3);
    company.calc();
    company.calc();
    company.calc();


    return 0;
}
