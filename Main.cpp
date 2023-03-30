#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "Player.hpp"
#include "Team.hpp"

Player* s_player;
Team* s_team;

void
testPlayerClass ();

void
testTeamClass ();

int main ()
{
    // TODO: Create function to get a file name from the user
    // and load a csv from a directory

    testTeamClass ();

    testPlayerClass ();
}

// Tests the functions of the Player Class
void
testPlayerClass ()
{
    s_player = new Player ();
    std::vector <float> player_test;
    std::string playerName = "Joel Embiid";
    
    s_player -> setPlayerStats (s_team, playerName);

    player_test = s_player -> getPlayerStats ();

    for (int i = 0; i < player_test.size (); i++)
    {
        std::cout << player_test[i] << " ";
    }

    std::cout << std::endl;

    s_player -> setIndividualStats ();

    s_player -> testIndividualStats ();
    
}

// Tests the functions of the Team Class
void
testTeamClass ()
{
    s_team = new Team ();
    std::string csv_file = "Test.csv";
    std::vector <std::string> p_vector;

    // Tests team info was retrieved
    s_team -> setTeamStringMatrix (csv_file);

    // Checks player info was gathered correctly
    p_vector = s_team -> getPlayer ("James Harden");
    for (int i = 0; i < p_vector.size (); i++)
    {
        std::cout << p_vector[i] << " ";
    }

    std::cout << std::endl;

    // Checks player stats are converted correctly
    std::vector <float> harden_stats;

    harden_stats = s_team -> getPlayerStats ("James Harden");
    for (int j = 0; j < harden_stats.size (); j++)
    {
        std::cout << harden_stats[j] << " ";
    }

    std::cout << std::endl;
}