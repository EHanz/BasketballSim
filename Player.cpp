/*
* Filename: Player.cpp
* Author: Evan Hanzelman
* Description: The Player Class
*/

/***************************************************************/
// Libraries and Headers

#include "Player.hpp"

/***************************************************************/
// Class Functions

// Standard constructor
Player :: Player ()
{
    
}

// Constructor where you can hard code all the values
Player :: Player (int g, int gS, float mP, float fGM, float fGA, float fGP,
                 float tPM, float tPA, float tPP, float twoPM, float twoPA, float twoPP,
                 float eFGP, float fTM, float fTA, float fTP, float oR, 
                 float dR, float tR, float a, float s, float b, float t, float pF, float pPG)
{

}

// Returns the array of player stats
std::vector <float>
Player :: getPlayerStats () { return p_stats; }

// Sets the individual stats of each variable provided from a team csv
// TODO: Find a better way to do this
// NOTE: There are player game logs for each season
// NOTE: There are also logs for a player's career
void
Player :: setIndividualStats ()
{
    games = p_stats[0];
    gameStarts = p_stats[1];
    minutesPlayed = p_stats[2];
    fieldGoalsMade = p_stats[3];
    fieldGoalAttempts = p_stats[4];
    fieldGoalPct = p_stats[5];
    threePtMade = p_stats[6];
    threePtAttempts = p_stats[7];
    threePtPct = p_stats[8];
    twoPtMade = p_stats[9];
    twoPtAttempts = p_stats[10];
    twoPtPct = p_stats[11];
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

// Provides a player vector from the league matrix
// Sets player class stats based off the provided vector
void
Player :: setStatsFromLeagueMatrix (std::vector<std::string> playerVector)
{
    // Empty the player vector
    p_stats.clear ();

    playerName = playerVector[1];

    //std::cout << "Making sure player name is set: " << playerName << "\n";

    // Assigns the incoming values to the local p_stats
    for (int i = 5; i < playerVector.size () - 1; i++)
    {
        float temp = std::stof (playerVector[i]);
        p_stats.push_back (temp);
    }

    // Assign the values from p_stats to the 
    // individual player values
    setIndividualStats ();
}

// Tests for player stats
void
Player :: printIndividualStats ()
{
    std::cout << "********************************" << "\n";
    // Output the player's stat line
    std :: cout << "Preparing Player Statistics..." << "\n";
    std :: cout << "\n";
    std :: cout << "Please note these statistics are PER GAME (excluding Games and Minutes): " << "\n";
    std :: cout << "\n" << "\n";
    std :: cout << "Player's Games Played: " << games << "\n";
    std :: cout << "Player's Games Started: " << gameStarts << "\n";
    std :: cout << "Player's Minutes Played: " << minutesPlayed << "\n";
    std :: cout << "Player's Field Goals Made: " << fieldGoalsMade << "\n";
    std :: cout << "Player's Field Goal Attempts: " << fieldGoalAttempts << "\n";
    std :: cout << "Player's Field Goal Percentage: " << fieldGoalPct << "\n";
    std :: cout << "Player's Three Pointers Made: " << threePtMade << "\n";
    std :: cout << "Player's Three Pointers Attempted: " << threePtAttempts << "\n";
    std :: cout << "Player's Three Point Percentage: " << threePtPct << "\n";
    std :: cout << "Player's Two Pointers Made: " << twoPtMade << "\n";
    std :: cout << "Player's Two Pointers Attempted: " << twoPtAttempts << "\n";
    std :: cout << "Player's Two Point Percentage: " << twoPtPct << "\n";
    std :: cout << "Player's Estimated Field Goal Percentage: " << estFgPct << "\n";
    std :: cout << "Player's Free Throws Made: " << freeThrowsMade << "\n";
    std :: cout << "Player's Free Throws Attempted: " << freeThrowAttempts << "\n";
    std :: cout << "Player's Free Throw Percentage: " << freeThrowPct << "\n";
    std :: cout << "Player's Offensive Rebounds: " << offReb << "\n";
    std :: cout << "Player's Defensive Rebounds: " << defReb << "\n";
    std :: cout << "Player's Total Rebounds: " << totalReb << "\n";
    std :: cout << "Player's Assists: " << assists << "\n";
    std :: cout << "Player's Steals: " << steals << "\n";
    std :: cout << "Player's Blocks: " << blocks << "\n";
    std :: cout << "Player's Turnovers: " << turnovers << "\n";
    std :: cout << "Player's Personal Fouls: " << personalFouls << "\n";
    std :: cout << "Player's Points Per Game: " << ppg << "\n";
    std :: cout << "\n";
    std :: cout << "\n";
    std :: cout << "\n";

    std::cout << "********************************" << "\n";
}