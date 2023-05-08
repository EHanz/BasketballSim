/*
* Filename: ComparePlayer.cpp
* Author: Evan Hanzelman
* Description: The Compare Player Class
*/

/***************************************************************/
// Libraries and Headers

#include "ComparePlayer.hpp"
#include "Player.hpp"

/***************************************************************/
// Class Functions

// Standard Constructor
ComparePlayer :: ComparePlayer ()
{
  
}

// Destructor for Compare Player Class
ComparePlayer :: ~ComparePlayer ()
{

}

// Might use this to assign the vector values to individual floats
// Might not need this...
void
ComparePlayer :: assignVecToFloats ()
{
    
}

// Below are the series of stat comparison functions
// Might try and find a way to do all of this within one function
int
ComparePlayer :: comparePlayerAssists ()
{
    std::cout << player_one_name << " has: " << p_one -> assists << "\n";
    std::cout << player_two_name << " has: " << p_two -> assists << "\n";

    if (p_one -> assists > p_two -> assists) { return 1; }
    else if (p_two -> assists > p_one -> assists) { return 2; }
    else { return 0; }
}

// TODO: All below functions, find a better way to compare Players
// Maybe individual vars for each stat or keep index better rather than
// hard code the index value into the vector
int
ComparePlayer :: comparePlayerBlocks ()
{
    std::cout << player_one_name << " has: " << p_one -> blocks << "\n";
    std::cout << player_two_name << " has: " << p_two -> blocks << "\n";

    if (player_one_stats[21] > player_two_stats[21]) { return 1; }
    else if (player_two_stats[21] > player_one_stats[21]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerFreeThrowAttempts ()
{
    std::cout << player_one_name << " has: " << p_one -> freeThrowAttempts << "\n";
    std::cout << player_two_name << " has: " << p_two -> freeThrowAttempts << "\n";

    if (p_one -> freeThrowAttempts > p_two -> freeThrowAttempts) { return 1; }
    else if (p_two -> freeThrowAttempts > p_one -> freeThrowAttempts) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerFreeThrowsMade ()
{
    std::cout << player_one_name << " has: " << p_one -> freeThrowsMade << "\n";
    std::cout << player_two_name << " has: " << p_two -> freeThrowsMade << "\n";

    if (p_one -> freeThrowsMade > p_two -> freeThrowsMade) { return 1; }
    else if (p_two -> freeThrowsMade > p_one -> freeThrowsMade) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerFreeThrowPercentage ()
{
    std::cout << player_one_name << " has: " << p_one -> freeThrowPct << "\n";
    std::cout << player_two_name << " has: " << p_two -> freeThrowPct << "\n";

    if (p_one -> freeThrowPct > p_two -> freeThrowPct) { return 1; }
    else if (p_two -> freeThrowPct > p_one -> freeThrowPct) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerGames ()
{
    std::cout << player_one_name << " has: " << p_one -> games << "\n";
    std::cout << player_two_name << " has: " << p_two -> games << "\n";

    if (p_one -> games > p_two -> games) { return 1; }
    else if (p_two -> games > p_one -> games) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerGameStarts ()
{
    std::cout << player_one_name << " has: " << p_one -> gameStarts << "\n";
    std::cout << player_two_name << " has: " << p_two -> gameStarts << "\n";

    if (p_one -> gameStarts > p_two -> gameStarts) { return 1; }
    else if (p_two -> gameStarts > p_one -> gameStarts) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerPPG ()
{
    std::cout << player_one_name << " has: " << p_one -> ppg << "\n";
    std::cout << player_two_name << " has: " << p_two -> ppg << "\n";

    if (player_one_stats[24] > player_two_stats[24]) { return 1; }
    else if (player_two_stats[24] > player_one_stats[24]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerOffensiveRebounds ()
{
    std::cout << player_one_name << " has: " << p_one -> offReb << "\n";
    std::cout << player_two_name << " has: " << p_two -> offReb << "\n";

    if (player_one_stats[16] > player_two_stats[16]) { return 1; }
    else if (player_two_stats[16] > player_one_stats[16]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerDefensiveRebounds ()
{
    std::cout << player_one_name << " has: " << p_one -> ppg << "\n";
    std::cout << player_two_name << " has: " << p_two -> ppg << "\n";

    if (player_one_stats[17] > player_two_stats[17]) { return 1; }
    else if (player_two_stats[17] > player_one_stats[17]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerTotalRebounds ()
{
    std::cout << player_one_name << " has: " << p_one -> totalReb << "\n";
    std::cout << player_two_name << " has: " << p_two -> totalReb << "\n";

    if (player_one_stats[18] > player_two_stats[18]) { return 1; }
    else if (player_two_stats[18] > player_one_stats[18]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerStat (int index)
{
    if (player_one_stats[index] > player_two_stats[index]) { return 1; }
    else if (player_two_stats[index] > player_two_stats[index]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerSteals ()
{
    std::cout << player_one_name << " has: " << p_one -> steals << "\n";
    std::cout << player_two_name << " has: " << p_two -> steals << "\n";

    if (player_one_stats[20] > player_two_stats[20]) { return 1; }
    else if (player_two_stats[20] > player_one_stats[20]) { return 2; }
    else { return 0; }
}

// Runs through the functions and keeps track who has better stats
// in each of the categories
int
ComparePlayer :: playerHeadToHead ()
{
    int pOneTotal = 0;
    int pTwoTotal = 0;
    if (comparePlayerAssists() == 1) { pOneTotal++; } else if (comparePlayerAssists() == 2) { pTwoTotal++; }
    if (comparePlayerBlocks () == 1) { pOneTotal++; } else if (comparePlayerBlocks () == 2) { pTwoTotal++; }
    if (comparePlayerPPG () == 1) { pOneTotal++; } else if (comparePlayerPPG () == 2) { pTwoTotal++; }
    if (comparePlayerTotalRebounds () == 1) { pOneTotal++; } else if (comparePlayerTotalRebounds () == 2) { pTwoTotal++; }
    if (comparePlayerSteals () == 1) { pOneTotal++; } else if (comparePlayerSteals () == 2) { pTwoTotal++; }
    if (pOneTotal > pTwoTotal) { return 1; } else if (pTwoTotal > pOneTotal) { return 2;}  else { return 0; }
}

// Take the stats and tally them to determine the winner
int
ComparePlayer :: comparePlayerTally ()
{
    
}

// Sets the stats of Player One only
void
ComparePlayer :: setPlayerOneStats (Player* p1, std::string playerOneName)
{
    player_one_name = playerOneName;
    player_one_stats = p1 -> getPlayerStats ();
}

// Sets the stats of Player Two only
void
ComparePlayer :: setPlayerTwoStats (Player* p2, std::string playerTwoName)
{
    player_two_name = playerTwoName;
    player_two_stats = p2 -> getPlayerStats ();
}

// Sets the stats of both players at the same time
// TODO: Look into if I should use globals still or switch to locals
// TODO: Look into whether to use pointers or references for p1 & p2
// TODO: Get player's names assigned in Player Class
void
ComparePlayer :: setPlayerStats (Player* p1, Player* p2, std::string playerOneName, std::string playerTwoName)
{
    // Setting player name's for testing
    player_one_name = p1 -> playerName;
    player_two_name = p2 -> playerName;

    // Using pointers now, but will switch later
    p_one = p1;
    p_two = p2;

    // Even though pointers are set. I am setting
    // to vectors as well just to be safe
    player_one_stats = p1 -> getPlayerStats ();
    player_two_stats = p2 -> getPlayerStats (); 

}

// Test the Player's Pointers and ensures the values were
// assigned properly
void
ComparePlayer :: testPlayerPointer (Player *p1, Player *p2)
{
    p_one = p1;
    p_two = p2;

    std::cout << "********************************" << "\n";

    std::cout << p_one -> playerName << "Assists: " << p_one -> assists << "\n";
    std::cout << p_two -> playerName << "Player Two Assists: " << p_two -> assists << "\n";
}