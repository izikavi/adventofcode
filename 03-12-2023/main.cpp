//
// Created by izik on 3/12/23.
//
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

unsigned int first_digit(const std::string str)
{
    size_t inx = str.find_first_of("0123456789");
    int digi = (str.at(inx) - '0');;
    return (str.at(inx) - '0');
}

unsigned int last_digit(const std::string srt)
{
    unsigned int digit = 0;
    return digit;
}

unsigned int combain_digits(const std::string str)
{
    return first_digit(str) + last_digit(str);
}

int main()
{
    std::string line;
    std::ifstream inputf("input");
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