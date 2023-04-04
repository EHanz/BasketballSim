/*
* Filename: ComparePlayer.hpp
* Author: Evan Hanzelman
* Description: Header file for the Compare Player Class
*/

// Be able to take two player classes
// Get the stats of each player
// Assign the stats to individual vars for each player
// Compare the stats of each player head to head

#ifndef COMPARE_PLAYER_HPP
#define COMPARE_PLAYER_HPP

#include <iostream>
#include <vector>

#include "Player.hpp"

class ComparePlayer
{
    public:
        ComparePlayer ();
        ~ComparePlayer ();

        // Make sure to set name in functions
        // for stat results and comparisons
        int
        comparePlayerBlocks ();

        int
        comparePlayerPPG ();

        int
        comparePlayerRebounds ();

        int
        comparePlayerSteals ();

        void
        setPlayerOneStats (Player* p1);

        void
        setPlayerTwoStats (Player* p2);

        void
        setPlayerStats (Player* p1, Player* p2);

    private:
        // TODO: Find a better way to store stats than a ton of floats
        
        std::vector <float> player_one_stats;
        std::vector <float> player_two_stats;

        std::string playerOneName;
        std::string playerTwoName;

        // Maybe use private vars eventually in this class
        // Using globals from Player Class right now
};

#endif