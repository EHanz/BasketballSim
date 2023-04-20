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
        Player ();

        Player (int g, int gS, float mP, float fGM, float fGA, float fGP,
                float tPM, float tPA, float tPP, float twoPM, float twoPA, float twoPP,
                float eFGP, float fTM, float fTA, float fTP, float oR, 
                float dR, float tR, float a, float s, float b, float t, float pF, float pPG);

        ~Player ();

        std::vector <float>
        getPlayerStats ();

        void
        printIndividualStats ();

        void
        setIndividualStats ();

        void
        setStatsFromLeagueMatrix (std::vector <std::string> playerVector);

        // TODO: ADD PLAYER NAMES
        std::string playerName;
        int games, gameStarts;
        float minutesPlayed, fieldGoalsMade, fieldGoalAttempts, fieldGoalPct,
        threePtMade, threePtAttempts, threePtPct, twoPtMade, twoPtAttempts, twoPtPct,
        estFgPct, freeThrowsMade, freeThrowAttempts, freeThrowPct, offReb,
        defReb, totalReb, assists, steals, blocks, turnovers, personalFouls, ppg;

    private:
        // TODO: find a better way to store all these stats
        // Too many vars for one class
        std::vector <float> p_stats;

};

#endif