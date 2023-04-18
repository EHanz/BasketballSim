/*
* Filename: League.hpp
* Author: Evan Hanzelman
* Description: Header file for the League Class
*/

#ifndef LEAGUE_HPP
#define LEAGUE_HPP

/***************************************************************/
// Libraries and Headers

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/***************************************************************/
// League Class

class League
{
    public:
        League ();
        ~League ();

        std::vector <std::vector <std::string>>
        getLeagueMatrix ();

        std::vector <std::string>
        getPlayerFromLeague (std::string playerName);

        std::vector <std::string>
        getPlayerFromLeague (int index);

        int
        listPlayersInLeague ();

        void
        setLeagueMatrix (const std::string& filename);

        void
        sortPlayersByName ();

    private:
        // Might want to switch to a different data type
        std::vector <std::vector <std::string>> league_matrix;
};

#endif