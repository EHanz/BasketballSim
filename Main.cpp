#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

void loadFromCSV (const std::string&);
std::vector<int> extract_column(const std::vector<std::vector<int> >&, int);

int main ()
{
    std::string csv_file = "Test.csv";

    loadFromCSV (csv_file);
}

// delim only works with commas as of right now
void loadFromCSV (const std::string& filename)
{
    std::ifstream file (filename.c_str ());
    std::vector< std::vector<std::string> > matrix;
    std::vector<std::string> row;
    std::string line;
    std::string cell;

    while (file)
    {
        std::getline (file,line);
        std::stringstream lineStream (line);
        row.clear ();

        while (std::getline (lineStream, cell, ','))
        {
            row.push_back (cell);
        }
            
        if (!row.empty ())
        {
            matrix.push_back (row);
        }
            
    }

    for (int i=0; i<int (matrix.size ()); i++)
    {
        for (int j=0; j<int (matrix[i].size ()); j++)
        {
            std::cout << matrix [i][j] << " ";
        }
            
        std::cout << std::endl;
    }

    std::cout << matrix[1][1] << std::endl;
    
}

std::vector<int> extract_column(const std::vector<std::vector<int> >& matrix, int col_idx) 
{
    std::vector<int> result;
    for(const auto& row : matrix) 
    {
        result.push_back(row[col_idx]);
    }
    return result;
 }