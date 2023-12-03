//
// Created by izik on 3/12/23
//
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int first_digit(const std::string &str)
{
    size_t inx = str.find_first_of("0123456789");
    return (str.at(inx) - '0');
}

int last_digit(const std::string &str)
{
    size_t inx = str.find_last_of("0123456789");
    return (str.at(inx) - '0');
}

int combain_digits(const std::string &str)
{
    return ((first_digit(str)*10) + last_digit(str));
}

int main()
{
    std::string line;
    std::ifstream inputf("../input");
    int sum = 0;
    if (!inputf.is_open())
        std::cout << "failed to open " << "input" << '\n';
    else
    {
        while (std::getline(inputf, line))
        {
            sum+=combain_digits(line);
        }
        std::cout << sum << std::endl;
    }
    return 0;
}