#include "engineer.hpp"
#include <iostream>

Engineer::Engineer(std::string name)
    :Employee(name)
{}

void Engineer::print() {
  Employee::print();
  std::cout << "Jestem inżynierem." << std::endl;
}