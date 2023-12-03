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
    
    bool announce_new_round();
    bool parse_user_input();
};
