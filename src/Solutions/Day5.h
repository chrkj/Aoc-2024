#ifndef DAY5_H
#define DAY5_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Day5
{
public:
    Day5() = default;

    bool IsRuleViolated(std::unordered_map<int, std::unordered_set<int>>& rules, const std::vector<int> &update) const
    {
        for (size_t i = 1; i < update.size(); ++i)
        {
            auto ruleNums = rules[update[i]];
            for (int ruleNum : ruleNums)
            {
                for (int j = i - 1; j >= 0; --j)
                    if (update[j] == ruleNum)
                        return true;
            }
        }
        return false;
    }

    void Part1()
    {
        std::unordered_map<int, std::unordered_set<int>> rules;
        std::ifstream is(input_data.data());

        std::string line;
        while (getline(is, line))
        {
            if (line.empty())
                break;

            std::istringstream ss(line);
            std::string part1, part2;

            if (std::getline(ss, part1, '|') && std::getline(ss, part2))
            {
                int num1 = std::stoi(part1);
                int num2 = std::stoi(part2);
                rules[num1].emplace(num2);
            }
        }

        int sum = 0;
        while (std::getline(is, line))
        {
            std::vector<int> update;
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ','))
                update.push_back(std::stoi(token));

            if (!IsRuleViolated(rules, update))
                sum += update[update.size()/2];
        }
        printf("Sum %d", sum);
    }

    void Part2() const
    {
        std::unordered_map<int, std::unordered_set<int>> rules;
        std::ifstream is(input_data.data());

        std::string line;
        while (getline(is, line))
        {
            if (line.empty())
                break;

            std::istringstream ss(line);
            std::string part1, part2;

            if (std::getline(ss, part1, '|') && std::getline(ss, part2))
            {
                int num1 = std::stoi(part1);
                int num2 = std::stoi(part2);
                rules[num1].emplace(num2);
            }
        }

        std::vector<std::vector<int>> badUpdates;
        while (std::getline(is, line))
        {
            std::vector<int> update;
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ','))
                update.push_back(std::stoi(token));

            if (IsRuleViolated(rules, update))
                badUpdates.push_back(update);
        }

        int sum = 0;
        for (auto& badUpdate: badUpdates)
        {
            int l = 0, r = 1;
            while (r < badUpdate.size())
            {
                if (rules[badUpdate[r]].contains(badUpdate[l]))
                    std::swap(badUpdate[l], badUpdate[r]);
                r++;
                if (r == badUpdate.size())
                {
                    l++;
                    r = l + 1;
                }
            }
            sum += badUpdate[badUpdate.size()/2];
        }
        printf("Sum %d", sum);
    }

private:
    std::string_view input_test{R"(..\src\Input\day5_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day5.txt)"};
};

#endif //DAY5_H
