#pragma once

#include <memory>
#include "company.hpp"

class Game
{
public:
    Game();

    void run();

private:
    int round;
    bool is_running;

    std::unique_ptr<Company> company;
    
    void one_round();
    bool interact_with_user();
};
