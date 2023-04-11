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

/***************************************************************/
// Libraries and Headers

#include <iostream>
#include <vector>

#include "Player.hpp"

/***************************************************************/
// Compare Player Class

class ComparePlayer
{
    public:
        ComparePlayer ();
        ~ComparePlayer ();

        // Make sure to set name in functions
        // for stat results and comparisons
        void
        assignVecToFloats ();

        int
        comparePlayerBlocks ();

        int
        comparePlayerPPG ();

        int
        comparePlayerRebounds ();

        int
        comparePlayerStat (int index);

        int
        comparePlayerSteals ();

        int
        playerHeadToHead ();

        void
        setPlayerOneStats (Player* p1, std::string playerOneName);

        void
        setPlayerTwoStats (Player* p2, std::string playerTwoName);

        void
        setPlayerStats (Player* p1, Player* p2, std::string playerOneName, std::string playerTwoName);

    private:
        // TODO: Find a better way to store stats than a ton of floats
        
        std::vector <float> player_one_stats;
        std::vector <float> player_two_stats;

        std::string player_one_name;
        std::string player_two_name;

        // Maybe use private vars eventually in this class
        // Using globals from Player Class right now
};

#endif