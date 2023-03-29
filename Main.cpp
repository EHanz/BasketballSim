#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "Player.hpp"
#include "Team.hpp"

Team* s_team;

int main ()
{
    std::string csv_file = "Test.csv";
    std::vector <std::string> p_vector;

    // Tests team info was retrieved
    s_team = new Team ();

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