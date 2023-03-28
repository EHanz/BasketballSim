#ifndef TEAM_HPP
#define TEAM_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Team
{
    public:
        Team ();
        ~Team ();

        std::vector <std::string>
        getPlayer (std::string playerName);

        std::vector< std::vector <std::string>>
        getTeamMatrix ();

        void
        setTeamMatrix (const std::string& filename);

    private:
        std::vector< std::vector <std::string>> t_matrix;
};

#endif