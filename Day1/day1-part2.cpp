//
// Created by izik on 12/3/23.
// This code writen to solve AoC2023 day 1 - part 2
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

int get_first_digit(const std::string &str)
{
    const std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    size_t first_inx = str.find_first_of("0123456789");
    int first_digit = str.at(first_inx) - '0';
    std::string sub = str.substr(0, first_inx);
    first_inx++;
    for (size_t i=0; i < numbers.size(); ++i)
    {
        size_t inx = sub.find(numbers.at(i));
        if (inx != std::string::npos && inx < first_inx)
        {
            first_inx = inx;
            first_digit = i;
        }
    }
    return first_digit;
}

int get_last_digit(const std::string &str)
{
    const std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int last_inx = str.find_last_of("0123456789");
    int last_digit = str.at(last_inx) - '0';
    std::string sub = str.substr(last_inx+1);
    last_inx = -1;
    int inx = -1;
    for (size_t i=0; i < numbers.size(); ++i)
    {
        int check_inx = sub.find(numbers.at(i));
        while (check_inx != std::string::npos)
        {
            if (check_inx > inx)
            {
                inx = check_inx;
            }
            check_inx = sub.find(numbers.at(i), check_inx+1);
        }
        if (inx > last_inx)
        {
            last_digit = i;
            last_inx = inx;
        }
        inx = -1;
    }
    return last_digit;
}

int get_number(const std::string &str)
{
    int first_digit = get_first_digit(str);
    int last_digit = get_last_digit(str);
    std::cout << ((first_digit * 10) + last_digit) << std::endl;
    return ((first_digit * 10) + last_digit);
}

int sum_of_data(const std::vector<std::string> &data)
{
    int sum = 0;
    int i = 0;
    for (auto &str: data)
    {
        if (i==93)
        {
            int d= 0;
            ++d;
        }
        sum += get_number(str);
        ++i;
    }
    return sum;
}

int main()
{
    std::vector<std::string> data(read_lines("../input"));
    std::cout << sum_of_data(data) << std::endl;
    return 0;
}