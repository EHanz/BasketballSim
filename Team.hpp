/*
* Filename: Team.hpp
* Author: Evan Hanzelman
* Description: Header file for the Team Class
*/

#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>

class Team
{
    public:
        Team ();
        ~Team ();
    
    private:
        std::vector<std::vector<std::string>> team_matrix;
};

#endif