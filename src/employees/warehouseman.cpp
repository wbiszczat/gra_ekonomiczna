#include "warehouseman.hpp"
#include <iostream>


Warehouseman::Warehouseman(std::string name)
    :Employee(name)
{
  payment = 4000;
  udt = (rand() % 2 == 0);
}

void Warehouseman::print() 
{
  Employee::print();
  std::cout << "Jestem magazynierem." << std::endl;
  std::cout << "Czy mam pozwolenie na wózek widłowy? " << (udt ? "Tak" : "Nie") << std::endl;

}

