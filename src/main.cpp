#include <iostream>
#include <memory>

#include "game.hpp"
#include "company.hpp"
#include "employees/employees.hpp"


int main()
{
    std::cout << "Gra ekonomiczna!" << std::endl;
    
    Game game;
    game.run();


    return 0;
}
