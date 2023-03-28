#include "Team.hpp"

// Constructor for the Team Class
Team :: Team ()
{

}

// Gets the vector of the team and their stats
std::vector< std::vector<std::string>>
Team :: getTeamMatrix ()
{
    return t_matrix;
}

// Sets the vector of the team and their stats
void
Team :: setTeamMatrix (const std::string& filename)
{
    std::ifstream data (filename);
    std::string line;

    while(std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline (lineStream,cell,','))
        {
            parsedRow.push_back (cell);
        }

        t_matrix.push_back (parsedRow);
    }

    for (int i = 0; i < int (t_matrix.size ()); i++)
    {
        for (int j = 0; j < int (t_matrix[i].size ()); j++)
        {
            std::cout << t_matrix [i][j] << " ";
        }
            
        std::cout << std::endl;
    }

}