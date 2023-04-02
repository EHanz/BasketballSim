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

    private:
        // TODO: find a better way to store all these stats
        // Too many vars for one class
        std::vector <float> p_stats;
        int games, gameStarts;
        float minutesPlayed, fieldGoalsMade, fieldGoalAttempts, fieldGoalPct,
        threePtMade, threePtAttempts, threePtPct, twoPtMade, twoPtAttempts, twoPtPct,
        estFgPct, freeThrowsMade, freeThrowAttempts, freeThrowPct, offReb,
        defReb, totalReb, assists, steals, blocks, turnovers, personalFouls, ppg;

};

#endif