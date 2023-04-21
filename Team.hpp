/*
* Filename: Team.hpp
* Author: Evan Hanzelman
* Description: Header file for the Team Class
*/

#ifndef TEAM_HPP
#define TEAM_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Team
{
    public:
        // Class Constructor and Deconstructor

        Team ();
        ~Team ();

        // Class Functions

        std::vector<std::vector<std::string>>
        getTeamMatrix ();

        void
        setMatrixToVectors ();

        void
        setTeamMatrix (const std::string& filename);

        std::string
        testMatrix ();
    
    private:
        // Class Variables

        std::vector<std::vector<std::string>> team_matrix;
};

#endif