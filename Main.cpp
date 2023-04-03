/*
* Filename: Main.cpp
* Author: Evan Hanzelman
* Description: Driver for the Basketball Simulator Project
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "ComparePlayer.hpp"
#include "League.hpp"
#include "Player.hpp"
#include "Team.hpp"

League* s_league;
Player* s_player_one;
Player* s_player_two;
Team* s_team;

std::string playerOneName;
std::string playerTwoName;
std::vector <std::string> player_one_vec;
std::vector <std::string> player_two_vec;

void
init ();

void
printMenuText ();

void
setPlayerClass (Player*, std::vector <std::string>);

void
testLeagueClass ();

void
testTeamClass ();

void
testUserInput (int);

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

    printMenuText ();
}

// Init those lousy pointers
void
init ()
{
    s_league = new League ();
    s_player_one = new Player ();
    s_player_two = new Player ();
    s_team = new Team ();

    std::cout << "Welcome to the Basketball Simulator!" << "\n";

    // Boots up the matrix of all players in the league
    s_league -> setLeagueMatrix("League.csv");
}

// Prints the output and menu options for the user
void
printMenuText ()
{
    int option = 0;
    std::cout << "Would you like to: " << "\n";
    std::cout << "1. Load Player 1 for Sim" << "\n";
    std::cout << "2. Load Player 2 for Sim" << "\n";
    std::cout << "3. Compare the two players" << "\n";
    std::cout << "4. Quit" << "\n";

    std::cin >> option;
    testUserInput (option);
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

// Tests the functions of the Team Class
// TODO: Rework Team Class
void
testTeamClass ()
{

}

// Ask user for a player name and then extract the stats associated with
// that player and print it out
// TODO: Make searching for players easier
void
testUserInput (int option)
{
    std::vector <float> test_player;

    if (option == 1)
    {
        player_one_vec.clear ();

        std::cout << "What is the name of Player 1?" << "\n";
        std::cin.ignore ();
        std::getline (std::cin, playerOneName);

        player_one_vec = s_league -> getPlayerFromLeague (playerOneName);
        setPlayerClass (s_player_one, player_one_vec);

        std::cout << "\n";
        std::cout << "\n";

        test_player = s_player_one -> getPlayerStats ();
        std::cout << test_player[2] << "\n";

        printMenuText ();
    }
    else if (option == 2)
    {
        player_two_vec.clear ();

        std::cout << "What is the name of Player 2?" << "\n";
        std::cin.ignore ();
        std::getline (std::cin, playerTwoName);

        player_two_vec = s_league -> getPlayerFromLeague (playerTwoName);
        setPlayerClass (s_player_two, player_two_vec);
        printMenuText ();
    }
    else if (option == 3)
    {
        // Compare Player Options

    }
    else if (option == 4)
    {
        exit (0);
    }
    else 
    {
        std::cout << "That is not a valid option. Please choose again." << "\n";
    }
}