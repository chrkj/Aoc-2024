#ifndef DAY7_H
#define DAY7_H

#include <cmath>
#include <cstdint>
#include <string_view>

#include "../Utils/Utils.h"

class Day7
{
public:
    Day7() = default;

    uint64_t Concatenation(const uint64_t left, const uint64_t right)
    {
        int digits = 0;
        uint64_t temp = right;
        while (temp > 0)
        {
            temp /= 10;
            ++digits;
        }
        return left * static_cast<long>(std::pow(10, digits)) + right;
    }

    bool IsPossible(const std::vector<uint64_t>& equation, const uint64_t runningSum, const int i, const bool part2)
    {
        if (runningSum == equation[0] && i == equation.size()) return true;
        if (i >= equation.size() || runningSum > equation[0])  return false;

        if (IsPossible(equation, runningSum + equation[i], i+1, part2))
            return true;
        if (IsPossible(equation, runningSum * equation[i], i+1, part2))
            return true;
        if (IsPossible(equation, Concatenation(runningSum, equation[i]), i+1, part2) && part2)
            return true;

        return false;
    }

    void Part1()
    {
        uint64_t sum = 0;
        const auto equations = Utils::ParseToVectorVector<uint64_t>(input_data, ' ');
        for (auto equation : equations)
            if (IsPossible(equation, equation[1], 2, false))
                sum += equation[0];
        printf("Sum: %llu\n", sum);
    }

    void Part2()
    {
        uint64_t sum = 0;
        const auto equations = Utils::ParseToVectorVector<uint64_t>(input_data, ' ');
        for (auto equation : equations)
            if (IsPossible(equation, equation[1], 2, true))
                sum += equation[0];
        printf("Sum: %llu\n", sum);
    }

private:
    std::string_view input_test{R"(..\src\Input\day7_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day7.txt)"};
};

#endif //DAY7_H
