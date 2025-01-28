#ifndef DAY7_H
#define DAY7_H

#include <cstdint>
#include <string_view>

#include "../Utils/Utils.h"

class Day7
{
public:
    Day7() = default;

    bool IsPossible(const std::vector<uint64_t>& equation, const uint64_t runningSum, const uint16_t i)
    {
        if(runningSum == equation[0] && i == equation.size()) return true;
        if(i >= equation.size() || runningSum > equation[0])  return false;

        if(IsPossible(equation, runningSum + equation[i], i+1))
            return true;
        if(IsPossible(equation, runningSum * equation[i], i+1))
            return true;

        return false;
    }

    void Part1()
    {
        uint64_t sum = 0;
        const auto equations = Utils::ParseToVectorVector<uint64_t>(input_data, ' ');
        for (auto equation : equations)
            if (IsPossible(equation, equation[1], 2))
                sum += equation[0];
        printf("Sum: %llu\n", sum);
    }

    void Part2()
    {
    }

private:
    std::string_view input_test{R"(..\src\Input\day7_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day7.txt)"};
};

#endif //DAY7_H
