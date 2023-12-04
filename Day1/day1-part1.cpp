//
// Created by izik on 3/12/23
// This code writen to solve AoC2023 day 1 - part 1
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> read_lines(const std::string &file_name)
{
    std::vector<std::string> input;
    std::ifstream inputf(file_name);
    std::string line;
    if (!inputf.is_open())
        std::cout << "failed to open " << file_name << std::endl;
    else
    {
        while (std::getline(inputf, line))
        {
            input.push_back(line);
        }
    }
    return input;
}

int get_number(const std::string &str)
{
    size_t first_inx = str.find_first_of("0123456789");
    int first_digi = str.at(first_inx) - '0';
    size_t last_inx = str.find_last_of("0123456789");
    int last_digi = str.at(last_inx) - '0';
    return ((first_digi*10) + last_digi);
}

int sum_of_data(const std::vector<std::string> &data)
{
    int sum = 0;
    for (auto &i: data)
    {
        sum += get_number(i);
    }
    return sum;
}

int main()
{
    std::vector<std::string> data(read_lines("../input"));
    std::cout << sum_of_data(data) << std::endl;
    return 0;
}