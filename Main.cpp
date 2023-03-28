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

    s_team = new Team ();

    s_team -> setTeamMatrix (csv_file);
}