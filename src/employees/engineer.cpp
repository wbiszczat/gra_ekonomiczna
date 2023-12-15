#include "engineer.hpp"
#include <iostream>

Engineer::Engineer(std::string name, std::string alma_mater)
    :Employee(name), alma_mater{alma_mater}
{
  payment = 6000;
}

void Engineer::print() {
  Employee::print();
  std::cout << "Jestem inżynierem. Ukończył_m " << alma_mater << ". " << std::endl;
}