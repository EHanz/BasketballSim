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
// Class Pointers and other vars for driver components

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

    //testTeamClass ();

    // TODO: implement league player csv file and find a good way to
    // navigate something that large besides vec matrix

    //testLeagueClass ();

    // TODO: Please make a menu file! Very unorganized!
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

    const std::string leagueFilename = "League.csv";
    const std::string teamFilename = "SixersTeam.csv";

    std::cout << "********************************" << "\n";
    std::cout << "Welcome to the Basketball Simulator!" << "\n";

    // Boots up the matrix of all players in the league
    s_league -> setLeagueMatrix (leagueFilename);

    // Boots up the matrix of the Sixers Team
    s_team -> setTeamMatrix (teamFilename);
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

    // s_compare_player -> testPlayerPointer (s_player_one, s_player_two);

    std::cout << "********************************" << "\n";
    std::cout << "\n";
    std::cout << playerOneName << " versus " << playerTwoName << "\n";
    std::cout << "1. Better Stats " << "\n";
    std::cout << "2. More Assists " << "\n";
    std::cout << "3. More Blocks " << "\n";
    std::cout << "4. More Free Throws " << "\n";
    std::cout << "5. More Games Played " << "\n";
    std::cout << "6. More PPG " << "\n";
    std::cout << "7. More Rebounds " << "\n";
    std::cout << "8. More Steals " << "\n";
    std::cout << "9. Main Menu " << "\n";
    std::cout << "10. Exit Simulator " << "\n"; 

    std::cin >> option;

    std::cout << "********************************" << "\n";
    
    runComparePlayerOptions (option);
}

// Executes functions depending on option chosen from the menu
void
runComparePlayerOptions (int option)
{
    int result = 0;

    std::cout << "********************************" << "\n";

    // Testing the switch/case statement
    switch (option)
    {
        case 1:
            std::cout << "Player stat head to head..." << "\n";
            result = s_compare_player -> playerHeadToHead ();
            headToHeadResults (result);
            break;
        case 2:
            std::cout << "Comparing Assists Per Game..." << "\n";
            result = s_compare_player -> comparePlayerAssists ();
            headToHeadResults (result);
            break;
        case 3:
            std::cout << "Comparing Blocks Per Game..." << "\n";
            result = s_compare_player -> comparePlayerBlocks ();
            headToHeadResults (result);
            break;
        case 4:
            std::cout << "Comparing Free Throws Per Game..." << "\n";
            result = s_compare_player -> comparePlayerFreeThrowsMade ();
            headToHeadResults (result);
            break;
        case 5:
            std::cout << "Comparing Games Played..." << "\n";
            result = s_compare_player -> comparePlayerGames ();
            headToHeadResults (result);
            break;
        case 6:
            std::cout << "Comparing Points Per Game..." << "\n";
            result = s_compare_player -> comparePlayerPPG ();
            headToHeadResults (result);
            break;
        case 7:
            std::cout << "Comparing Rebounds Per Game..." << "\n";
            result = s_compare_player -> comparePlayerTotalRebounds ();
            headToHeadResults (result);
            break;
        case 8:
            std::cout << "Comparing Steals Per Game..." << "\n";
            result = s_compare_player -> comparePlayerSteals ();
            headToHeadResults (result);
            break;
        case 9:
            printMenuText ();
            break;
        case 10:
            exit (0);
        default:
            std::cout << "That is not a valid option..." << "\n";
            break;
    }

    std::cout << "********************************" << "\n";

    printComparePlayerMenu ();
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
    std::cout << "3. Add Player 1 from List: " << "\n";
    std::cout << "4. Add Player 2 from List: " << "\n";
    std::cout << "5. Compare the two players" << "\n";
    std::cout << "6. View Player One: " << playerOneName << " Stats" << "\n";
    std::cout << "7. View Player Two: " << playerTwoName << " Stats" << "\n";
    std::cout << "8. Clear Player Slots" << "\n";
    std::cout << "9. Quit" << "\n";

    std::cin >> option;

    std::cout << "********************************" << "\n";

    runMainMenuOptions (option);
}

// Ask user for a player name and then extract the stats associated with
// that player and print it out
// TODO: Make searching for players easier
void
runMainMenuOptions (int option)
{
    std::vector <float> test_player;

    int index = 0;

    std::cout << "********************************" << "\n";

    // Testing the switch/case statement
    switch (option)
    {
        case 1:
            player_one_vec.clear ();
            
            std::cout << "Player 1 Name: " << "\n";
            std::cin.ignore ();
            std::getline (std::cin, playerOneName);

            player_one_vec = s_league -> getPlayerFromLeague (playerOneName);
            setPlayerClass (s_player_one, player_one_vec);

            std::cout << "\n";
            std::cout << "\n";

            test_player = s_player_one -> getPlayerStats ();
            std::cout << test_player[2] << "\n";
            break;

        case 2:
            player_two_vec.clear ();
            std::cout << "Player 2 Name: " << "\n";
            std::cin.ignore ();
            std::getline (std::cin, playerTwoName);
            player_two_vec = s_league -> getPlayerFromLeague (playerTwoName);
            setPlayerClass (s_player_two, player_two_vec);
            break;

        case 3:
            player_one_vec.clear ();
            index = s_league -> listPlayersInLeague ();
            player_one_vec = s_league -> getPlayerFromLeague (index);
            setPlayerClass (s_player_one, player_one_vec);
            playerOneName = s_player_one -> playerName;
            break;

        case 4:
            player_two_vec.clear ();
            index = s_league -> listPlayersInLeague ();
            player_two_vec = s_league -> getPlayerFromLeague (index);
            setPlayerClass (s_player_two, player_two_vec);
            playerTwoName = s_player_two -> playerName;
            break;

        case 5:
            std::cout << "Comparing: " << playerOneName << " to " << playerTwoName << "..." << "\n";
            // Compare Player Options
            s_compare_player -> setPlayerStats (s_player_one, s_player_two, playerOneName, playerTwoName);
            // Print the Compare Player Menu Options
            printComparePlayerMenu ();
            break;

        case 6:
            std::cout << "Viewing: " << playerOneName << " Stats " << "\n";
            s_player_one -> printIndividualStats ();
            break;

        case 7:
            std::cout << "Viewing " << playerTwoName << " Stats " << "\n";
            s_player_two -> getPlayerStats ();
            break;

        case 8:
            std::cout << "Erasing: " << playerOneName << " and " << playerTwoName << "\n";
            playerOneName = "";
            playerTwoName = "";
            player_one_vec.clear ();
            player_two_vec.clear ();
            break;

        case 9:
            std::cout << "Exiting the simulator..." << "\n";
            exit (0);
            break;

        default:
            std::cout << "That is not a valid option. Please choose again." << "\n";
            break;

    }

    std::cout << "********************************" << "\n";

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

    player -> printIndividualStats ();
}

// Tests the functions of the League Class
void
testLeagueClass ()
{
    std::cout << "Testing League Class..." << "\n";

    std::vector <std::string> embiid_test;
    std::vector <float> embiid_stats;

    std::vector <std::string> giannis_test;
    std::vector <float> giannis_stats;

    // Embiid Tests
    embiid_test = s_league -> getPlayerFromLeague ("Joel Embiid");

    setPlayerClass (s_player_one, embiid_test);

    // End Embiid Tests


    // Giannis Tests
    giannis_test = s_league -> getPlayerFromLeague ("Giannis Antetokounmpo");

    setPlayerClass (s_player_two, giannis_test);

    // End Giannis Tests

}

// Tests the functions of the Team Class
// TODO: Rework Team Class
void
testTeamClass ()
{
    std::cout << "Testing Team Class" << "\n";

    std::string test = s_team -> testMatrix ();

    std::cout << test << "\n";
}