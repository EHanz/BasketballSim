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
    std::ifstream file (filename.c_str ());
    std::vector<std::string> row;
    std::string line;
    std::string cell;

    while (file)
    {
        std::getline (file,line);
        std::stringstream lineStream (line);
        row.clear ();

        while (std::getline (lineStream, cell, ','))
        {
            row.push_back (cell);
        }
            
        if (!row.empty ())
        {
            t_matrix.push_back (row);
        }
            
    }

    for (int i=0; i<int (t_matrix.size ()); i++)
    {
        for (int j=0; j<int (t_matrix[i].size ()); j++)
        {
            std::cout << t_matrix [i][j] << " ";
        }
            
        std::cout << std::endl;
    }

    std::cout << t_matrix[1][1] << std::endl;
}