//
// Created by izik on 12/4/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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


int main()
{
    vector<string> data = read_lines("../input");
    return 0;
}