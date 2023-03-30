#include "Player.hpp"

Player :: Player ()
{
    
}

std::vector <float>
Player :: getPlayerStats ()
{
    return p_stats;
}

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
    estFgPct = p_stats[12];
    freeThrowsMade = p_stats[13];
    freeThrowAttempts = p_stats[14];
    freeThrowPct = p_stats[15];
    offReb = p_stats[16];
    defReb = p_stats[17];
    totalReb = p_stats[18];
    assists = p_stats[19];
    steals = p_stats[20];
    blocks = p_stats[21];
    turnovers = p_stats[22];
    personalFouls = p_stats[23];
    ppg = p_stats[24];
}

void
Player :: setPlayerStats (Team* t_ptr, std::string playerName)
{
    p_stats = t_ptr -> getPlayerStats (playerName);
}