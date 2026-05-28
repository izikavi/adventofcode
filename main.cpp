#include <iostream>
#include <string>
#include <map>
#include <functional>

namespace day1_part1 { void solve(const std::string& input_path); }
namespace day1_part2 { void solve(const std::string& input_path); }
namespace day2_part1 { void solve(const std::string& input_path); }
namespace day2_part2 { void solve(const std::string& input_path); }
namespace day3_part1 { void solve(const std::string& input_path); }
namespace day3_part2 { void solve(const std::string& input_path); }

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <day>.<part>  (e.g. 1.2)\n";
        return 1;
    }

    std::string arg = argv[1];
    size_t dot = arg.find('.');
    if (dot == std::string::npos)
    {
        std::cerr << "Invalid format. Use <day>.<part>, e.g. 1.2\n";
        return 1;
    }

    int day  = std::stoi(arg.substr(0, dot));
    int part = std::stoi(arg.substr(dot + 1));

    std::string input_path = "Day" + std::to_string(day) + "/input";

    using SolveFn = std::function<void(const std::string&)>;
    std::map<std::pair<int,int>, SolveFn> solvers = {
        {{1, 1}, day1_part1::solve},
        {{1, 2}, day1_part2::solve},
        {{2, 1}, day2_part1::solve},
        {{2, 2}, day2_part2::solve},
        {{3, 1}, day3_part1::solve},
        {{3, 2}, day3_part2::solve},
    };

    auto it = solvers.find({day, part});
    if (it == solvers.end())
    {
        std::cerr << "No solver for day " << day << " part " << part << "\n";
        return 1;
    }

    it->second(input_path);
    return 0;
}
