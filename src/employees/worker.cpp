#include "worker.hpp"
#include <iostream>

Worker::Worker(std::string name, float shoe_size)
    :Employee(name), shoeSize{shoe_size}
{
  payment = 4500;
}

void Worker::print() {
  Employee::print();
  std::cout << "Jestem robotnikiem. Mój rozmiar buta to " << shoeSize << std::endl;
}