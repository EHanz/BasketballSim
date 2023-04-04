/*
* Filename: Player.hpp
* Author: Evan Hanzelman
* Description: Header file for the Player Class
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>

#include "Team.hpp"

class Player
{
    public: 
        Player ();
        ~Player ();

        std::vector <float>
        getPlayerStats ();

        void
        setIndividualStats ();

        void
        setStatsFromLeagueMatrix (std::vector <std::string> playerVector);

        void
        testIndividualStats ();

        // TODO: ADD PLAYER NAMES
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