/*
* Filename: Player.hpp
* Author: Evan Hanzelman
* Description: Header file for the Player Class
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

/***************************************************************/
// Libraries and Headers

#include <iostream>
#include <vector>

#include "Team.hpp"

/***************************************************************/
// Player Class

class Player
{
    public: 
        // Class Constructors and Destructor

        Player ();

        Player (int g, int gS, float mP, float fGM, float fGA, float fGP,
                float tPM, float tPA, float tPP, float twoPM, float twoPA, float twoPP,
                float eFGP, float fTM, float fTA, float fTP, float oR, 
                float dR, float tR, float a, float s, float b, float t, float pF, float pPG);

        ~Player ();

        // Class Functions

        std::vector <float>
        getPlayerStats ();

        void
        printIndividualStats ();

        void
        setAdvancedStats ();

        void
        setIndividualStats ();

        void
        setStatsFromLeagueMatrix (std::vector <std::string> playerVector);

        // TODO: find ways to use less globals
        std::string playerName;
        int games, gameStarts;
        float minutesPlayed, fieldGoalsMade, fieldGoalAttempts, fieldGoalPct,
        threePtMade, threePtAttempts, threePtPct, twoPtMade, twoPtAttempts, twoPtPct,
        estFgPct, freeThrowsMade, freeThrowAttempts, freeThrowPct, offReb,
        defReb, totalReb, assists, steals, blocks, turnovers, personalFouls, ppg;

    private:
        // Class Variables

        // TODO: find a better way to store all these stats
        std::vector <float> p_stats;

};

#endif