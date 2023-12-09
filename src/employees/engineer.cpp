#include "engineer.hpp"
#include <iostream>
#include "../RandomNameGenerator.hpp"

Engineer::Engineer(std::string name)
    :Employee(name), alma_mater{get_alma_mater()}
{
  payment = 6000;
}

void Engineer::print() {
  Employee::print();
  std::cout << "Jestem inżynierem. Ukończył_m " << alma_mater << ". " << std::endl;
}