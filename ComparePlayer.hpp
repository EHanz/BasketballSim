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

class ComparePlayer
{
    public:
        // Make sure to set name in functions
        // for stat results and comparisons
        void
        setPlayerOneStats ();

        void
        setPlayerTwoStats ();

    private:
        // TODO: Find a better way to store stats than a ton of floats
        
        std::vector <float> player_one_stats;
        std::vector <float> player_two_stats;

        std::string playerOneName;
        std::string playerTwoName;

        // Add the variables for the individual stats for each player
        // p1 or p2 followed by stat name
        float p1_minutesPlayed, p2_minutesPlayed;
};

#endif