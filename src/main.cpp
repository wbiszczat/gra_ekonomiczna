#include <iostream>
#include <memory>

#include "game.hpp"

int main()
{
    std::cout << "Gra ekonomiczna!" << std::endl;
    
    Game game;
    game.run();

    return 0;
}
