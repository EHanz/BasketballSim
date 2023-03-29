#include "Team.hpp"
#include <string>

// Constructor for the Team Class
Team :: Team ()
{

}

// Gets a vector of a specific player on the team
std::vector <std::string>
Team :: getPlayer (std::string playerName)
{
    int p_iterator = 0;
    std::vector <std::string> p_vector;

    for (int i = 0; i < t_matrix.size (); i++)
    {
        if (t_matrix[i][1] == playerName)
        {
            p_iterator = i;
            break;
        }
    }

    for (int j = 0; j < t_matrix[p_iterator].size (); j++)
    {
        p_vector.push_back (t_matrix[p_iterator][j]);
    }

    return p_vector;
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

    while (std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector <std::string> parsedRow;
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

    std::cout << t_matrix [2][1] << std::endl;
    std::cout << t_matrix [3][1] << std::endl;
    std::cout << t_matrix [6][1] << std::endl;

}