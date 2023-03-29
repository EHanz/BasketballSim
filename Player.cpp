#include "Player.hpp"

Player :: Player ()
{
    
}

std::vector <float>
Player :: getPlayerStats ()
{
    return p_stats;
}

void
Player :: setPlayerStats (Team* t_ptr, std::string playerName)
{
    p_stats = t_ptr -> getPlayerStats (playerName);
}