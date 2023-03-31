#include "League.hpp"

// Standard Constructor
League :: League ()
{

}

// Returns the matrix of all players in the league
std::vector <std::vector <std::string>>
League :: getLeagueMatrix ()
{
    return league_matrix;
}

// Takes a player name string and locates a player with that name
std::vector <std::string>
League :: getPlayerFromLeague (std::string playerName)
{
    std::cout << "Finding " << playerName << "... " << std::endl;

    int p_iterator = 0;
    std::vector <std::string> p_vector;

    std::cout << "Player Name is: " << playerName << std::endl;

    for (int i = 0; i < league_matrix.size (); i++)
    {
        if (league_matrix[i][1] == playerName)
        {
            p_iterator = i;
            break;
        }
    }

    for (int j = 0; j < league_matrix[p_iterator].size (); j++)
    {
        p_vector.push_back (league_matrix[p_iterator][j]);
    }

    return p_vector;
}

// Loads the matrix of all players in the NBA
// Data is extracted from the League.csv
void
League :: setLeagueMatrix (const std::string& filename)
{
    std::ifstream data (filename);
    std::string line;

    std::cout << "Loading League Matrix..." << std::endl;

    while (std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector <std::string> parsedRow;
        while(std::getline (lineStream,cell,','))
        {
            parsedRow.push_back (cell);
        }

        league_matrix.push_back (parsedRow);
    }
}