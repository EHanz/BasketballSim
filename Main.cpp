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

    s_team = new Team ();

    s_team -> setTeamStringMatrix (csv_file);

    p_vector = s_team -> getPlayer ("James Harden");

    for (int i = 0; i < p_vector.size (); i++)
    {
        std::cout << p_vector[i] << " ";
    }

    std::cout << std::endl;
}