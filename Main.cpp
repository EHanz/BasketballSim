/*
* Filename: Main.cpp
* Author: Evan Hanzelman
* Description: Driver for the Basketball Simulator Project
*/

/***************************************************************/
// Included libraries and classes

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "ComparePlayer.hpp"
#include "League.hpp"
#include "Player.hpp"
#include "Team.hpp"

/***************************************************************/
// Class Pointers and other vars

ComparePlayer* s_compare_player;
League* s_league;
Player* s_player_one;
Player* s_player_two;
Team* s_team;

std::string playerOneName;
std::string playerTwoName;
std::vector <std::string> player_one_vec;
std::vector <std::string> player_two_vec;

/***************************************************************/
// Function Declarations

void
init ();

void
headToHeadResults (int);

void
printComparePlayerMenu ();

void
printMenuText ();

void
runComparePlayerOptions (int);

void
runMainMenuOptions (int);

void
setPlayerClass (Player*, std::vector <std::string>);

void
testLeagueClass ();

void
testTeamClass ();

/***************************************************************/
// Driver for Basketball Simulator

int main ()
{
    // Initialize the classes needed and load the league csv file
    init ();

    // TODO: Create function to get a file name from the user
    // and load a csv from a directory
    // Make a specific directory for the csv files

    // TODO: Find where the csv files are for individual teams
    // and the player stats per game

    // TODO: implement league player csv file and find a good way to
    // navigate something that large besides vec matrix

    testLeagueClass ();

    // TODO: Please make a menu file! Very unorganized!
    // TODO: Also switch from if statement to switch statements!
    printMenuText ();
}

/***************************************************************/
// Driver Functions

// Init those lousy pointers and set the League Matrix
// Maybe switch from pointer to reference??
void
init ()
{
    s_compare_player = new ComparePlayer ();
    s_league = new League ();
    s_player_one = new Player ();
    s_player_two = new Player ();
    s_team = new Team ();

    std::cout << "Welcome to the Basketball Simulator!" << "\n";

    // Boots up the matrix of all players in the league
    s_league -> setLeagueMatrix("League.csv");
}

// Puts both players in a head to head matchup
// Player wins if they win in more categories
void
headToHeadResults (int result)
{
    if (result == 1) 
    {
        std::cout << playerOneName << " won the matchup!" << "\n";
    } 
    else if (result == 2) 
    {
        std::cout << playerTwoName << " won the matchup!" << "\n";
    } 
    else 
    {
        std::cout << "The result was a draw!" << "\n";
    }
}

// Prints Compare Player Menu Options
// TODO: Make the text menus nicer
// Add some dividers, clear the console, etc
void
printComparePlayerMenu ()
{
    int option = 0;

    std::cout << "********************************" << "\n";
    std::cout << "\n";
    std::cout << playerOneName << " versus " << playerTwoName << "\n";
    std::cout << "1. Better Stats " << "\n";
    std::cout << "2. More Blocks " << "\n";
    std::cout << "3. More PPG " << "\n";
    std::cout << "4. More Rebounds " << "\n";
    std::cout << "5. More Steals " << "\n";
    std::cout << "6. Main Menu " << "\n";
    std::cout << "7. Exit Simulator " << "\n"; 

    std::cin >> option;
    runComparePlayerOptions (option);
}

// Prints the output and menu options for the user
// TODO: Make the text menus nicer
// Add some dividers, clear the console, etc
void
printMenuText ()
{
    int option = 0;
    std::cout << "********************************" << "\n";
    std::cout << "Would you like to: " << "\n";
    std::cout << "1. Load Player 1 for Sim" << "\n";
    std::cout << "2. Load Player 2 for Sim" << "\n";
    std::cout << "3. Compare the two players" << "\n";
    std::cout << "4. Clear Player Slots" << "\n";
    std::cout << "5. Quit" << "\n";

    std::cin >> option;
    runMainMenuOptions (option);
}

// Executes functions depending on option chosen from the menu
void
runComparePlayerOptions (int option)
{
    int result = 0;
    if (option == 1)
    {
        std::cout << "Player stat head to head..." << "\n";
        result = s_compare_player -> playerHeadToHead ();

        headToHeadResults (result);
    }
    else if (option == 2)
    {
        std::cout << "Comparing Blocks Per Game..." << "\n";
        result = s_compare_player -> comparePlayerBlocks ();

        headToHeadResults (result);
    }
    else if (option == 3)
    {
        std::cout << "Comparing Points Per Game..." << "\n";
        result = s_compare_player -> comparePlayerPPG ();

        headToHeadResults (result);
    }
    else if (option == 4)
    {
        std::cout << "Comparing Rebounds Per Game..." << "\n";
        result = s_compare_player -> comparePlayerRebounds ();

        headToHeadResults (result);
    }
    else if (option == 5)
    {
        std::cout << "Comparing Steals Per Game..." << "\n";
        result = s_compare_player -> comparePlayerSteals ();

        headToHeadResults (result);
    }
    else if (option == 6)
    {
        printMenuText ();
    }
    else if (option == 7)
    {
        std::cout << "Exiting the simulator..." << "\n";
        exit (0);
    }
    else 
    {
        std::cout << "That is not a valid option..." << "\n";
    }
    printComparePlayerMenu ();
}

// Ask user for a player name and then extract the stats associated with
// that player and print it out
// TODO: Make searching for players easier
void
runMainMenuOptions (int option)
{
    std::vector <float> test_player;

    if (option == 1)
    {
        player_one_vec.clear ();
        std::cout << "********************************" << "\n";
        std::cout << "What is the name of Player 1?" << "\n";
        std::cin.ignore ();
        std::getline (std::cin, playerOneName);

        player_one_vec = s_league -> getPlayerFromLeague (playerOneName);
        setPlayerClass (s_player_one, player_one_vec);

        std::cout << "\n";
        std::cout << "\n";

        test_player = s_player_one -> getPlayerStats ();
        std::cout << test_player[2] << "\n";
    }
    else if (option == 2)
    {
        player_two_vec.clear ();

        std::cout << "What is the name of Player 2?" << "\n";
        std::cin.ignore ();
        std::getline (std::cin, playerTwoName);

        player_two_vec = s_league -> getPlayerFromLeague (playerTwoName);
        setPlayerClass (s_player_two, player_two_vec);
    }
    else if (option == 3)
    {
        std::cout << "Comparing: " << playerOneName << " to " << playerTwoName << "..." << "\n";
        // Compare Player Options
        s_compare_player -> setPlayerStats (s_player_one, s_player_two, playerOneName, playerTwoName);

        // Print the Compare Player Menu Options

        printComparePlayerMenu ();
    }
    else if (option == 4)
    {
        std::cout << "Erasing: " << playerOneName << " and " << playerTwoName << "\n";
        playerOneName = "";
        playerTwoName = "";
        player_one_vec.clear ();
        player_two_vec.clear ();
    }
    else if (option == 5)
    {
        std::cout << "Exiting the simulator..." << "\n";
        exit (0);
    }
    else 
    {
        std::cout << "That is not a valid option. Please choose again." << "\n";
    }
    printMenuText ();
}

// Tests the functions of the Player Class
void
setPlayerClass (Player* player, std::vector <std::string> playerVector)
{
    // Sends a vector of a player extracted from the league matrix
    // Assigns variables in player class from the vector sent over
    player -> setStatsFromLeagueMatrix (playerVector);

    // Ensures the stats were sent over correctly by retrieving
    // The vector of stats for the player
    player -> getPlayerStats ();

    player -> testIndividualStats ();
}

// Tests the functions of the League Class
void
testLeagueClass ()
{
    // std::cout << "Testing League Class..." << "\n";

    // std::vector <std::string> embiid_test;
    // std::vector <float> embiid_stats;

    // std::vector <std::string> giannis_test;
    // std::vector <float> giannis_stats;

    // // Embiid Tests
    // embiid_test = s_league -> getPlayerFromLeague ("Joel Embiid");

    // setPlayerClass (s_player_one, embiid_test);

    // // End Embiid Tests


    // // Giannis Tests
    // giannis_test = s_league -> getPlayerFromLeague ("Giannis Antetokounmpo");

    // setPlayerClass (s_player_two, giannis_test);

    // // End Giannis Tests

}

// Tests the functions of the Team Class
// TODO: Rework Team Class
void
testTeamClass ()
{
    std::cout << "Testing Team Class" << "\n";
}