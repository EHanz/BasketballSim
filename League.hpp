#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class League
{
    public:
        League ();
        ~League ();

        std::vector <std::vector <std::string>>
        getLeagueMatrix ();

        std::vector <std::string>
        getPlayerFromLeague (std::string playerName);

        void
        setLeagueMatrix (const std::string& filename);

    private:
        // Might want to switch to a different data type
        std::vector <std::vector <std::string>> league_matrix;
};

#endif