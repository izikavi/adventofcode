//
// Created by izik on 12/4/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string NOT_SYMBOL = "0123456789.";

vector<string> read_lines(const string &file_name)
{
    vector<string> input;
    ifstream input_file(file_name);
    string line;
    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            input.push_back(line);
        }
    }
    else
    {
        cout << "failed to open " << file_name << endl;
    }
    return input;
}

int get_num()
{
    int num = 0;
    return num;
}

vector<vector<bool> > set_matrix(const vector<string> &data)
{
    int height = data.size();
    int width = data.at(0).length();
    vector<vector<bool> > matirx;
    for (int row=0; row < height; ++row)
    {
        for (int col=0; col < width; ++col)
        {
            matirx[row][col] = false;
        }
    }
    for (int row=0; row < height; ++row)
    {
        for (int col=0; col < width; ++col)
        {
            if (string::npos == NOT_SYMBOL.find_first_not_of(data.at(row).at(col)))
            {
                if (row && col)
                    matirx.at(row - 1).at(col - 1) = true;
                if ((row < (height-1)) && col)
                    matirx.at(row + 1).at(col - 1) = true;
                if (row && (col < (width-1)))
                    matirx.at(row - 1).at(col + 1) = true;
                if ((row < (height-1)) && (col < (width -1)))
                    matirx.at(row + 1).at(col + 1) = true;
            }
        }
    }
    return matirx;
}

int get(const vector<vector<bool> > &matrix, const vector<string> &data)
{
    int sum = 0;
    int height = data.size();
    int width = data.at(0).length();
    for (int row=0; row < height; ++row)
    {
        for (int col=0; col < width; ++col)
        {
            if (matrix.at(row).at(col))
            {
                sum += get_num()
            }
        }
    }
}

int main()
{
    vector<string> data = read_lines("../input");
    return 0;
}