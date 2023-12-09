#include "marketer.hpp"
#include <iostream>

Marketer::Marketer(std::string name)
    :Employee(name)
{
  payment = 5000;
  followers = generateFollowersNumber();
}

void Marketer::print() {
  Employee::print();
  std::cout << "Jestem marketingowcem." << " Mam: " << followers << " obserwatorów w mediach społecznościowych" << std::endl;

}