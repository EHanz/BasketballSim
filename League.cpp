/*
* Filename: League.cpp
* Author: Evan Hanzelman
* Description: The League Class
*/

/***************************************************************/
// Libraries and Headers

#include "League.hpp"

/***************************************************************/
// Class Functions

// Standard Constructor
League :: League ()
{
    // Might move setLeagueMatrix function call here
}

// Returns the matrix of all players in the league
std::vector <std::vector <std::string>>
League :: getLeagueMatrix () { return league_matrix; }

// Takes a player name string and locates a player with that name
std::vector <std::string>
League :: getPlayerFromLeague (std::string playerName)
{
    std::cout << "Finding " << playerName << "... " << std::endl;

    int p_index = 0;
    std::vector <std::string> p_vector;

    std::cout << "Player Name is: " << playerName << std::endl;

    for (int i = 0; i < league_matrix.size (); i++)
    {
        if (league_matrix[i][1] == playerName)
        {
            p_index = i;
            break;
        }
    }

    for (int j = 0; j < league_matrix[p_index].size (); j++)
    {
        p_vector.push_back (league_matrix[p_index][j]);
    }
    
    std::cout << "********************************" << "\n";

    return p_vector;
}

// Returns a player from the league matrix
std::vector <std::string>
League :: getPlayerFromLeague (int index)
{
    std::vector <std::string> p_vector;
    
    for (int j = 0; j < league_matrix[index].size (); j++)
    {
        p_vector.push_back (league_matrix[index][j]);
    }

    std::cout << p_vector[1] << "\n";

    return p_vector;
}

// Returns the vector of Player objects
std::vector <Player>
League :: getPlayersFromLeague ()
{
    return players;
}

// TODO: List all the players in the league
// in an ORGANIZED fashion
int
League :: listPlayersInLeague ()
{
    int index = 0;

    for (int i = 1; i < league_matrix.size (); i++)
    {
        std::cout << i << ". " << league_matrix[i][1] << "\n";
    }

    std::cin >> index;

    return index;
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

// TODO: Read in the matrix and set each row as a Player Object
// That way all players are initialized at start
// Find out if there is a quick way to initialize that many
// Player Objects
void
League :: setPlayersFromMatrix (const std::string& filename)
{
    // Still a work in progress
    // Figure out how to take vec and assign to class object

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

// TODO: Sort the Players by their name, alphabetically
void
League :: sortPlayersByName ()
{
    
}