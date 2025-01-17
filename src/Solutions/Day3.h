#ifndef DAY3_H
#define DAY3_H

#include <fstream>
#include <regex>
#include <string_view>
#include <vector>

class Day3
{
public:
    Day3() = default;

    static std::vector<std::string> ExtractMulOccurrences(const std::string& input)
    {
        std::vector<std::string> matches;
        std::regex pattern(R"(mul\((\d+),(\d+)\))");
        std::smatch match;

        auto it = input.cbegin();
        while (std::regex_search(it, input.cend(), match, pattern))
        {
            matches.push_back(match[1]);
            matches.push_back(match[2]);
            it = match.suffix().first;
        }
        return matches;
    }

    static std::vector<std::string> ExtractMulOccurrences2(const std::string& input)
    {
        std::vector<std::string> matches;
        std::regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
        std::smatch match;

        bool enabled = true;
        auto it = input.cbegin();
        while (std::regex_search(it, input.cend(), match, pattern))
        {
            std::string substr = match[0];
            if (match[0] == "do()")
            {
                enabled = true;
                it = match.suffix().first;
                continue;
            }
            if (match[0] == "don't()")
            {
                enabled = false;
                it = match.suffix().first;
                continue;
            }

            if (enabled)
            {
                matches.push_back(match[1]);
                matches.push_back(match[2]);
            }
            it = match.suffix().first;
        }
        return matches;
    }

    void Part1() const
    {
        std::string line;
        std::ifstream stream(input_data.data());
        getline(stream, line);
        auto occurrences = ExtractMulOccurrences(line);
        int sum = 0;
        for (int i = 0; i < occurrences.size(); i+=2)
            sum += std::stoi(occurrences[i]) * std::stoi(occurrences[i+1]);
        printf("Sum is %d\n", sum);
    }

    void Part2() const
    {
        std::string line;
        std::ifstream stream(input_data.data());
        getline(stream, line);
        auto occurrences = ExtractMulOccurrences2(line);
        int sum = 0;
        for (int i = 0; i < occurrences.size(); i+=2)
            sum += std::stoi(occurrences[i]) * std::stoi(occurrences[i+1]);
        printf("Sum is %d\n", sum);
    }

private:
    std::string_view input_test{ R"(..\src\Input\day3_test.txt)"};
    std::string_view input_data{ R"(..\src\Input\day3.txt)"};
};

#endif //DAY3_H
