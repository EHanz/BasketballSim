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

// Might use this to assign the vector values to individual floats
// To be determined...
void
ComparePlayer :: assignVecToFloats ()
{
    
}

// Trying ternary operator here...
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
    if (player_one_stats[21] > player_two_stats[21]) { return 1; }
    else if (player_two_stats[21] > player_one_stats[21]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerPPG ()
{
    if (player_one_stats[24] > player_two_stats[24]) { return 1; }
    else if (player_two_stats[24] > player_one_stats[24]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: comparePlayerRebounds ()
{
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
    if (player_one_stats[20] > player_two_stats[20]) { return 1; }
    else if (player_two_stats[20] > player_one_stats[20]) { return 2; }
    else { return 0; }
}

int
ComparePlayer :: playerHeadToHead ()
{
    int pOneTotal = 0;
    int pTwoTotal = 0;
    if (comparePlayerBlocks () == 1) { pOneTotal++; } else if (comparePlayerBlocks () == 2) { pTwoTotal++; }
    if (comparePlayerPPG () == 1) { pOneTotal++; } else if (comparePlayerPPG () == 2) { pTwoTotal++; }
    if (comparePlayerRebounds () == 1) { pOneTotal++; } else if (comparePlayerRebounds () == 2) { pTwoTotal++; }
    if (comparePlayerSteals () == 1) { pOneTotal++; } else if (comparePlayerSteals () == 2) { pTwoTotal++; }
    if (pOneTotal > pTwoTotal) { return 1; } else if (pTwoTotal > pOneTotal) { return 2;}  else { return 0; }
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

void
ComparePlayer :: testPlayerPointer (Player *p1, Player *p2)
{
    p_one = p1;
    p_two = p2;

    std::cout << p_one -> playerName << "Assists: " << p_one -> assists << "\n";
    std::cout << p_two -> playerName << "Player Two Assists: " << p_two -> assists << "\n";
}