#ifndef TEAM_HPP
#define TEAM_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

class Team
{
    public:
        Team ();
        ~Team ();

        std::vector <std::string>
        getPlayer (std::string playerName);

        std::vector <float>
        getPlayerFromTeamStats (std::string playerName);

        std::vector <std::vector <std::string>>
        getTeamStringMatrix ();

        void
        setTeamStringMatrix (const std::string& filename);

    private:
        // Might want to switch to a different data type
        std::vector <std::vector <std::string>> t_str_matrix;
};

#endif