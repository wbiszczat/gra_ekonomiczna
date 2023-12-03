#include "game.hpp"

#include <iostream>

Game::Game()
    : round{1}, is_running{true}
{}

void Game::run() {
  while (is_running) {
    announce_new_round();
    
    while (parse_user_input())
    {
        ;
    }
    round++;
  }
}

void Game::announce_new_round() 
{
    system("clear");
    std::cout << "\u001b[31m" << "Round " << round << "\u001b[0m" << std::endl;
    std::cout << "Dostępne polecenia:\n";
    std::cout << "      ~~brak~~\n\n";   
}

bool Game::parse_user_input() {

    std::string command;
    std::cin >> command;
    
    std::cout << "Nie zrozumiałem!\n\n";

    return false;
}
