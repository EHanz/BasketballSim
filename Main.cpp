#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "ComparePlayer.hpp"
#include "League.hpp"
#include "Player.hpp"
#include "Team.hpp"

League* s_league;
Player* s_player_one;
Player* s_player_two;
Team* s_team;

void
init ();

void
testLeagueClass ();

void
testPlayerClass (Player*, std::vector <std::string>);

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

    testLeagueClass ();
}

// Init those lousy pointers
void
init ()
{
    s_league = new League ();
    s_player_one = new Player ();
    s_player_two = new Player ();
    s_team = new Team ();
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
    
    // Boots up the matrix of all players in the league
    s_league -> setLeagueMatrix("League.csv");

    // Embiid Tests
    embiid_test = s_league -> getPlayerFromLeague ("Joel Embiid");

    testPlayerClass (s_player_one, embiid_test);

    // End Embiid Tests


    // Giannis Tests
    giannis_test = s_league -> getPlayerFromLeague ("Giannis Antetokounmpo");

    testPlayerClass (s_player_two, giannis_test);

    // End Giannis Tests

}

// Tests the functions of the Player Class
void
testPlayerClass (Player* player, std::vector <std::string> playerVector)
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