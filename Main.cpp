#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "League.hpp"
#include "Player.hpp"
#include "Team.hpp"

League* s_league;
Player* s_player;
Team* s_team;

void
init ();

void
testLeagueClass ();

void
testPlayerClass ();

void
testTeamClass ();

int main ()
{
    init ();

    // TODO: Create function to get a file name from the user
    // and load a csv from a directory

    // TODO: Find where the csv files are for individual teams
    // and the player stats per game

    // TODO: implement league player csv file and find a good way to
    // navigate something that large besides vec matrix

    testTeamClass ();

    testPlayerClass ();

    testLeagueClass ();
}

// Init those lousy pointers
void
init ()
{
    s_league = new League ();
    s_player = new Player ();
    s_team = new Team ();
}

// Tests the functions of the League Class
void
testLeagueClass ()
{
    std::cout << "Testing League Class..." << std::endl;

    std::vector <std::string> embiid_test;
    std::vector <float> embiid_stats;

    // Boots up the matrix of all players in the league
    s_league -> setLeagueMatrix("League.csv");

    embiid_test = s_league -> getPlayerFromLeague ("Joel Embiid");

    // Sends a vector of a player extracted from the league matrix
    // Assigns variables in player class from the vector sent over
    s_player -> setStatsFromLeagueMatrix(embiid_test);

    // Ensures the stats were sent over correctly by retrieving
    // The vector of stats for the player
    embiid_stats = s_player -> getPlayerStats ();

    s_player -> testIndividualStats ();
}

// Tests the functions of the Player Class
void
testPlayerClass ()
{
    std::cout << "Testing Player Class..." << std::endl;

    std::vector <float> player_test;
    std::string playerName = "Tobias Harris";
    
    // Locates the player and finds the stats belonging to them
    // Prints out the results
    s_player -> setPlayerStats (s_team, playerName);

    player_test = s_player -> getPlayerStats ();

    // for (int i = 0; i < player_test.size (); i++)
    // {
    //     std::cout << player_test[i] << " ";
    // }

    std::cout << std::endl;

    s_player -> setIndividualStats ();

    s_player -> testIndividualStats ();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
}

// Tests the functions of the Team Class
void
testTeamClass ()
{
    std::cout << "Testing Team Class..." << std::endl;

    std::string csv_file = "Test.csv";
    std::vector <std::string> p_vector;

    // Tests team info was retrieved
    s_team -> setTeamStringMatrix (csv_file);
    
    // Checks player stats are converted correctly
    std::vector <float> harden_stats;

    harden_stats = s_team -> getPlayerFromTeamStats ("James Harden");
    for (int j = 0; j < harden_stats.size (); j++)
    {
        std::cout << harden_stats[j] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}