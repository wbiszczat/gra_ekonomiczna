#include "game.hpp"

#include <iostream>

Game::Game()
    : round{1}, is_running{true}, company{new Company()}
{}

void Game::run() {
  while (is_running) {

    system("clear");
    
    while (announce_new_round())
    {
        ;
    }
    round++;
  }
}

bool Game::announce_new_round() 
{
    int mainChoice;

    std::cout << "\u001b[31m" << "Round " << round << "\u001b[0m" << std::endl;
    std::cout << "Dostępne polecenia:\n"
    <<"1 ~ Zatrudnij pracownika.\n"
    <<"2 ~ Lista pracowników.\n"
    <<"3 ~ Weź kredyt.\n";
    //<< "Wybrano opcje: ";

    std::cin >> mainChoice ;

    if (mainChoice==1)
    {
      std::cout << "Zatrudnij: \n"
      <<"1 ~ Inżyniera.\n"
      <<"2 ~ Marketingowca.\n"
      <<"3 ~ Magazyniera.\n"
      <<"4 ~ Robotnika.\n"; 
    }
    
    if (mainChoice==2)
    {
      company->list_employee();
    } 

    return true;
}
 
bool Game::parse_user_input() {

    // std::string command;
    // std::cin >> command;
    
    std::cout << "Nie zrozumiałem!\n\n";

    return false;
}
