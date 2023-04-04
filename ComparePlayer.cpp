/*
* Filename: ComparePlayer.cpp
* Author: Evan Hanzelman
* Description: The Compare Player Class
*/

#include "ComparePlayer.hpp"
#include "Player.hpp"

// Standard Constructor
ComparePlayer :: ComparePlayer ()
{

}

int
ComparePlayer :: comparePlayerBlocks ()
{
    if (player_one_stats[21] > player_two_stats[21])
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

int
ComparePlayer :: comparePlayerPPG ()
{
    if (player_one_stats[24] > player_two_stats[24])
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

int
ComparePlayer :: comparePlayerRebounds ()
{
    if (player_one_stats[18] > player_two_stats[18])
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

int
ComparePlayer :: comparePlayerSteals ()
{
    if (player_one_stats[20] > player_two_stats[20])
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

// Sets the stats of Player One only
void
ComparePlayer :: setPlayerOneStats (Player* p1)
{
    player_one_stats = p1 -> getPlayerStats ();
}

// Sets the stats of Player Two only
void
ComparePlayer :: setPlayerTwoStats (Player* p2)
{
    player_two_stats = p2 -> getPlayerStats ();
}

// Sets the stats of both players at the same time
// TODO: Look into if I should use globals still or switch to locals
// TODO: Look into whether to use pointers or references for p1 & p2
// TODO: Get player's names assigned in Player Class
void
ComparePlayer :: setPlayerStats (Player* p1, Player* p2)
{
    player_one_stats = p1 -> getPlayerStats ();
    player_two_stats = p2 -> getPlayerStats (); 

    if (p1->assists > p2->assists)
    {
        std::cout << "Player One Has More Assists Per Game" << "\n";
    }
    else 
    {
        std::cout << "Player Two Has More Assists Per Game" << "\n";
    }
}