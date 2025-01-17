#ifndef DAY2_H
#define DAY2_H

#include <string_view>
#include <fstream>
#include <sstream>
#include <vector>

class Day2
{
public:
    Day2() = default;

    static bool IsSafe(const std::vector<int>& report)
    {
        // - The levels are either all increasing or all decreasing.
        // - Any two adjacent levels differ by at least one and at most three.
        bool ascending = true;
        bool descending = true;
        for (int i = 0; i < report.size() - 1; i++)
        {
            if (abs(report[i] - report[i+1]) > 3 || abs(report[i] - report[i+1]) < 1)
                return false;
            if (report[i] > report[i+1])
                ascending = false;
            if (report[i] < report[i+1])
                descending = false;
        }
        return ascending || descending;
    }

    void Part1() const
    {
        int numSafe = 0;
        std::ifstream stream(input_data.data());

        std::string line;
        while (getline(stream, line))
        {
            int curr;
            std::vector<int> numbers;
            std::istringstream iss(line);
            while (iss >> curr)
                numbers.emplace_back(curr);
            if (IsSafe(numbers))
                numSafe++;
        }
        printf("Number of safe reports: %i", numSafe);
    }

    static bool IsSafe2(const std::vector<int>& report)
    {
        if (IsSafe(report)) return true;
        for (int i = 0; i < report.size(); ++i)
        {
            std::vector<int> modified;
            for (int j = 0; j < report.size(); ++j)
                if (j != i) modified.push_back(report[j]);
            if (IsSafe(modified)) return true;
        }
        return false;
    }

    void Part2() const
    {
        int numSafe = 0;
        std::ifstream stream(input_data.data());

        std::string line;
        while (getline(stream, line))
        {
            int curr;
            std::vector<int> numbers;
            std::istringstream iss(line);
            while (iss >> curr)
                numbers.emplace_back(curr);
            if (IsSafe2(numbers))
                numSafe++;
        }
        printf("Number of safe reports: %i", numSafe);
    }

private:
    std::string_view input_test{ R"(..\src\Input\day2_test.txt)"};
    std::string_view input_data{ R"(..\src\Input\day2.txt)"};
};

#endif //DAY2_H
