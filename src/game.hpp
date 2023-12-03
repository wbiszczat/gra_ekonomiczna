#pragma once

class Game
{
public:
    Game();

    void run();

private:
    int round;
    bool is_running;
    
    void announce_new_round();
    bool parse_user_input();
};
