/*
* Filename: Team.cpp
* Author: Evan Hanzelman
* Description: The Team Class
*/

#include "Team.hpp"
#include <string>

Team :: Team ()
{
    
}

std::vector<std::vector<std::string>>
Team :: getTeamMatrix ()
{
    return team_matrix;
}

void
Team :: setMatrixToVectors ()
{
    
}

void
Team :: setTeamMatrix (const std::string &filename)
{
    std::ifstream data (filename);
    std::string line;

    std::cout << "Loading Team Matrix..." << std::endl;

    while (std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector <std::string> parsedRow;
        while(std::getline (lineStream,cell,','))
        {
            parsedRow.push_back (cell);
        }

        team_matrix.push_back (parsedRow);
    }
}

std::string
Team :: testMatrix ()
{
    return team_matrix[0][1];
}