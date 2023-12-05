//
// Created by izik on 12/5/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

enum cube_color
{
    BLUE,
    RED,
    GREEN,
    NUM_OF_COLORS
};

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

void get_min_cube_per_color(const vector<string> &game,
                           int *blue_cubes, int *red_cubes, int *green_cubes)
{
    // reset cubes values
    vector<int> base_line {0,0,0};
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
                    color_id = cube_color::BLUE;
                    break;
                case 'r':
                    color_id = cube_color::RED;
                    break;
                case 'g':
                    color_id = cube_color::GREEN;
                    break;
                default:
                    return;
            }
            if (cubes > base_line[color_id])
            {
                base_line[color_id] = cubes;
            }
        }
    }
    *blue_cubes = base_line[cube_color::BLUE];
    *red_cubes = base_line[cube_color::RED];
    *green_cubes = base_line[cube_color::GREEN];
}

int sum_min_cubes_power(const vector<string> &data)
{
    int sum = 0;
    for (auto &i : data)
    {
        vector<string> game = break_game_by_repetition(i);
        int blue_cubes = 0;
        int red_cubes = 0;
        int green_cubes = 0;
        get_min_cube_per_color(game, &blue_cubes, &red_cubes, &green_cubes);
        sum += (blue_cubes * red_cubes * green_cubes);
    }
    return sum;
}

int main()
{
    vector<string> data =read_lines("../input");
    cout << sum_min_cubes_power(data) << endl;
    return 0;
}