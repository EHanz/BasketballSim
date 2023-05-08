/*
* Filename: League.hpp
* Author: Evan Hanzelman
* Description: Header file for the League Class
*/

#ifndef LEAGUE_HPP
#define LEAGUE_HPP

/***************************************************************/
// Libraries and Headers

#include "Player.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/***************************************************************/
// League Class

class League
{
    public:
        // Class Constructor and Deconstructor

        League ();
        ~League ();

        // Class Functions

        std::vector <std::vector <std::string>>
        getLeagueMatrix ();
        
        std::vector <std::string>
        getPlayerFromLeague (std::string playerName);

        std::vector <std::string>
        getPlayerFromLeague (int index);

        std::vector <Player>
        getPlayersFromLeague ();

        int
        listPlayersInLeague ();

        void
        setLeagueMatrix (const std::string& filename);

        void
        setPlayersFromMatrix (const std::string& filename);

        void
        sortPlayersByName ();

    private:
        // Class Variables

        // Might want to switch to a different data type
        std::vector <std::vector <std::string>> league_matrix;

        // Vector of Players in League
        std::vector <Player> players;
};

#endif