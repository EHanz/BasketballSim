#include "Player.hpp"

Player :: Player ()
{
    
}

// Returns the array of player stats
std::vector <float>
Player :: getPlayerStats ()
{
    return p_stats;
}

// Sets the individual stats of each variable provided from a team csv
// TODO: Find a better way to do this
// NOTE: There are player game logs for each season
// NOTE: There are also logs for a player's career
void
Player :: setIndividualStats ()
{
    age = p_stats[0];
    games = p_stats[1];
    gameStarts = p_stats[2];
    minutesPlayed = p_stats[3];
    fieldGoalsMade = p_stats[4];
    fieldGoalAttempts = p_stats[5];
    fieldGoalPct = p_stats[6];
    threePtMade = p_stats[7];
    threePtAttempts = p_stats[8];
    threePtPct = p_stats[9];
    twoPtMade = p_stats[10];
    twoPtAttempts = p_stats[11];
    twoPtPct = p_stats[12];
    estFgPct = p_stats[13];
    freeThrowsMade = p_stats[14];
    freeThrowAttempts = p_stats[15];
    freeThrowPct = p_stats[16];
    offReb = p_stats[17];
    defReb = p_stats[18];
    totalReb = p_stats[19];
    assists = p_stats[20];
    steals = p_stats[21];
    blocks = p_stats[22];
    turnovers = p_stats[23];
    personalFouls = p_stats[24];
    ppg = p_stats[25];
}

// Assigns player stats via a pointer to the team's stat matrix
void
Player :: setPlayerStats (Team* t_ptr, std::string playerName)
{
    p_stats = t_ptr -> getPlayerStats (playerName);
}

// Tests for player stats
void
Player :: testIndividualStats ()
{
    std::cout << "Embiid's Age: " << age << std::endl;
    std::cout << "Embiid's PPG: " << ppg << std::endl;
    std::cout << "Embiid's Block Count: " << blocks << std::endl;
}