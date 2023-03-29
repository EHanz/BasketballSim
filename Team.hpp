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

        std::vector <std::vector <int>>
        getTeamIntMatrix ();

        std::vector <std::vector <std::string>>
        getTeamStringMatrix ();

        void
        setTeamIntMatrix ();

        void
        setTeamStringMatrix (const std::string& filename);

    private:
        std::vector< std::vector <std::string>> t_str_matrix;
        std::vector <std::vector <int>> t_int_matrix;
};

#endif