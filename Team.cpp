/*
* Filename: Team.cpp
* Author: Evan Hanzelman
* Description: The Team Class
*/

#include "Team.hpp"
#include <string>

// Standard Class Constructor
Team :: Team ()
{
    
}

Team :: ~Team ()
{
    
}

// Returns the Team Matrix
std::vector<std::vector<std::string>>
Team :: getTeamMatrix ()
{
    return team_matrix;
}

// TODO: Assign each of the rows of the matrix to vectors
void
Team :: setMatrixToVectors ()
{
    
}

// Reads in a csv file and assigns the values to a matrix
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

    std::cout << team_matrix[1][1];

    std::cout << "********************************" << "\n";
}

// Returns a value at the given index to make sure the matrix
// was read in correctly
std::string
Team :: testMatrix ()
{
    std::cout << "********************************" << "\n";

    return team_matrix[0][1];
}