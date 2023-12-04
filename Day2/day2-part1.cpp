//
// Created by izik on 12/4/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum cube_color
{
    BLUE,
    RED,
    GREEN,
    NUM_OF_COLORS
};

const int NUM_OF_BLUE = 14;
const int NUM_OF_RED = 12;
const int NUM_OF_GREEN = 13;

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

vector<string> break_game_by_repetition(const string &line)
{
    vector<string> game;
    int start_pos = 0; line.find_first_of(":")+2;
    int end_pos =  line.find_first_of(":")+1;;//line.find_first_of(";");
    string repetition;// = line.substr(start_pos, end_pos - start_pos);
    while (end_pos != string::npos)
    {
        start_pos = end_pos+1;
        end_pos = line.find_first_of(";", start_pos);
        repetition = line.substr(start_pos, end_pos - start_pos);
        game.push_back(repetition);
    };
    return game;
}

bool is_game_possible(const vector<string> &game)
{
    vector<int> base_line {NUM_OF_BLUE, NUM_OF_RED, NUM_OF_GREEN};
    int start_pos = 0;
    int end_pos = 0;
    for (auto &i : game)
    {
        start_pos = 0;
        while (string::npos != start_pos)
        {
            end_pos=i.find(' ', start_pos+1);
            int cubes=stoi(i.substr(start_pos, end_pos - start_pos));
            char color_char=i.at(end_pos + 1);
            start_pos = i.find(" ", end_pos+1);
            int color_id=-1;
            switch (color_char)
            {
                case 'b':
                    color_id=cube_color::BLUE;
                    break;
                case 'r':
                    color_id=cube_color::RED;
                    break;
                case 'g':
                    color_id=cube_color::GREEN;
                    break;
                default:
                    return false;
            }
            base_line[color_id]-=cubes;
            if (0 > base_line[color_id])
            {
                cout << "False" << endl;
                return false;
            }
        }
    }
    cout << "True" << endl;
    return true;
}

int get_game_id(const string &line)
{
    int end_pos = line.find_first_of(":");
    int start_pos = line.find_first_of(" ");
    return stoi(line.substr(start_pos, end_pos-start_pos));
}

int sum_possible_games(const vector<string> &data)
{
    int sum = 0;
    for (auto &i : data)
    {
        vector<string> game =break_game_by_repetition(i);
        if (is_game_possible(game))
        {
            sum += get_game_id(i);
        }
    }
    return sum;
}

int main()
{
    vector<string> data =read_lines("../input");
    cout << sum_possible_games(data) << endl;
    return 0;
}