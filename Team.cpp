/*
* Filename: Team.cpp
* Author: Evan Hanzelman
* Description: The Team Class
*/

#include "Team.hpp"

Team :: Team ()
{
    
}

std::vector <std::vector <std::string>>
getTeamStats ()
{
    
}

void
setTeamStats (const std::string& filename)
{
    std::ifstream data (filename);
    std::string line;

    std::cout << "Loading League Matrix..." << std::endl;

    while (std::getline (data,line))
    {
        std::stringstream lineStream (line);
        std::string cell;
        std::vector <std::string> parsedRow;
        while (std::getline (lineStream,cell,','))
        {
            parsedRow.push_back (cell);
        }
    }
    
}