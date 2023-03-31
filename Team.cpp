#include "Team.hpp"
#include <sstream>
#include <string>

// Constructor for the Team Class
Team :: Team ()
{

}

// Gets a vector of a specific player on the team
std::vector <std::string>
Team :: getPlayer (std::string playerName)
{
    int p_index = 0;
    std::vector <std::string> p_vector;

    std::cout << "Player Name is: " << playerName << "\n";

    // Col is just the value of one since that is where the names are stored
    for (int row = 0; row < t_str_matrix.size (); row++)
    {
        if (t_str_matrix[row][1] == playerName)
        {
            p_index = row;
            break;
        }
    }

    // Now that we have the row, we just copy over all
    // the values in each column
    for (int col = 0; col < t_str_matrix[p_index].size (); col++)
    {
        p_vector.push_back (t_str_matrix[p_index][col]);
    }

    return p_vector;
}

// Gets the stats of a player based off name provided
// TODO: possibly move the function to player or elsewhere
std::vector <float>
Team :: getPlayerFromTeamStats (std::string playerName)
{
    std::vector <std::string> playerString;
    std::vector <float> playerStats;

    std::cout << "Finding " << playerName << "\n";

    playerString = getPlayer (playerName);

    // Start col at index 2 for now because first two columns are not stats
    for (int col = 3; col < playerString.size (); col++)
    {
        float temp = std::stof (playerString[col]);
        playerStats.push_back (temp);
    }

    return playerStats;
}

// Gets the vector of the team and their stats
std::vector <std::vector <std::string>>
Team :: getTeamStringMatrix ()
{
    return t_str_matrix;
}

// Sets the vector of the team and their stats
void
Team :: setTeamStringMatrix (const std::string& filename)
{
    std::ifstream data (filename);
    std::string line;

    std::cout << "Loading Team Matrix..." << "\n";

    while (std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector <std::string> parsedRow;
        while(std::getline (lineStream,cell,','))
        {
            parsedRow.push_back (cell);
        }

        t_str_matrix.push_back (parsedRow);
    }

}