#include "game.hpp"

#include <iostream>
#include <string>
#include "RandomNameGenerator.hpp"

Game::Game()
    : round{1}, is_running{true}, company{new Company()}
{}

void Game::run() {
  while (is_running) {
    one_round(); 
    round++;
  }
}

void Game::one_round() 
{
    //Zastosowanie ASCII Escape Codes aby pokolorować napis Round
    std::cout << "\u001b[31m" << "Round " << round << "\u001b[0m" << std::endl;
    std::cout << "Dostępne polecenia:\n"
    << "lp   ~ Lista pracowników.\n"
    << "zinz ~ Zatrudnij inżyniera.\n"
    << "zmkt ~ Zatrudnij marketera.\n"
    << "zmag ~ Zatrudnij magazyniera.\n"
    << "zrob ~ Zatrudnij robotnika.\n"
    << "kred ~ Weź kredyt.\n"
    << "lk   ~ Lista kredytów.\n"
    << "kt   ~ Koniec tury\n";
    

    while(interact_with_user())
    {
      ;
    }
}

bool Game::interact_with_user()
{
  std::string command;
  std::cout << "--> ";
  std::cin >> command;

  if(command.compare("kt") == 0)
  {
    is_running = !company->calc();
    return false;
  }
  else if(command.compare("lp") == 0)
  {
    company->list_employee();
  }
  else if(command.compare("zinz") == 0)
  {
    std::unique_ptr<Employee> inz = std::unique_ptr<Employee>(new Engineer(get_random_name(),get_alma_mater())); 
    company->hire(std::move(inz));
  }
  else if(command.compare("zmkt") == 0)
  {
    std::unique_ptr<Employee> mark = std::unique_ptr<Employee>(new Marketer(get_random_name())); 
    company->hire(std::move(mark));
  }
  else if(command.compare("zmag") == 0)
  {
    std::unique_ptr<Employee> mag = std::unique_ptr<Employee>(new Warehouseman(get_random_name())); 
    company->hire(std::move(mag));
  }
  else if(command.compare("zrob") == 0)
  {
    float shoe_size = 0.0f;
    std::cout << "Podaj rozmiar buta." << std::endl;
    std::cin >> shoe_size;
    std::unique_ptr<Employee> rob = std::unique_ptr<Employee>(new Worker(get_random_name(), shoe_size)); 
    company->hire(std::move(rob));
  }
  else if(command.compare("kred") == 0)
  {
    float debt_size;
    int return_time_in_months;
    std::cout << "Podaj wysokość kredytu?" <<std::endl;
    std::cin >> debt_size;
    std::cout << "Czas spłaty" <<std::endl;
    std::cin >> return_time_in_months;
    company->take_credit(debt_size, return_time_in_months);
  }
  else if(command.compare("lk") == 0)
  {
    company->list_credits();
  }
  else
  {
    std::cout << "Nieznana komenda!" << std::endl;
  }
  return true;
  
}
