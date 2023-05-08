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
        // Class Constructor and Deconstructor

        ComparePlayer ();
        ~ComparePlayer ();

        // Class Functions

        void
        assignVecToFloats ();

        // Maybe find a way to compare stats using less functions

        int
        comparePlayerAssists ();

        int
        comparePlayerBlocks ();

        int
        comparePlayerEstFGPct ();

        int
        comparePlayerFieldGoalPct ();

        int
        comparePlayerFreeThrowAttempts ();

        int
        comparePlayerFreeThrowsMade ();

        int
        comparePlayerFreeThrowPercentage ();

        int
        comparePlayerGames ();

        int
        comparePlayerGameStarts ();

        int
        comparePlayerMinutesPlayed ();

        int
        comparePlayerPPG ();

        int
        comparePlayerPersonalFouls ();

        int
        comparePlayerOffensiveRebounds ();

        int
        comparePlayerDefensiveRebounds ();

        int
        comparePlayerTotalRebounds ();

        int
        comparePlayerStat (int index);

        int
        comparePlayerSteals ();

        int
        comparePlayerThreePointAttempts ();

        int
        comparePlayerThreePointMade ();

        int
        comparePlayerThreePointPct ();

        int
        comparePlayerTurnovers ();

        int
        comparePlayerTwoPointAttempts ();

        int
        comparePlayerTwoPointMade ();

        int
        comparePlayerTwoPointPct ();

        int
        playerHeadToHead ();

        int
        comparePlayerTally ();

        void
        setPlayerOneStats (Player* p1, std::string playerOneName);

        void
        setPlayerTwoStats (Player* p2, std::string playerTwoName);

        void
        setPlayerStats (Player* p1, Player* p2, std::string playerOneName, std::string playerTwoName);

        void
        testPlayerPointer (Player* p1, Player* p2);

    private:
        // Class Variables

        // TODO: Find a better way to store stats than a ton of floats
        
        std::vector <float> player_one_stats;
        std::vector <float> player_two_stats;

        std::string player_one_name;
        std::string player_two_name;

        // Maybe use private vars eventually in this class
        // Using globals from Player Class right now
        Player* p_one;
        Player* p_two;
};

#endif