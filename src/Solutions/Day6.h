#ifndef DAY6_H
#define DAY6_H

#include <vector>
#include <string_view>

#include "../Utils/Utils.h"

class Day6
{
public:
    Day6() = default;

    void GetObsAndStartPos(std::pair<int,int>& startPos, std::vector<int>& obstructions, const std::vector<std::vector<char>>& map)
    {
        for (auto i = 0; i < map.size(); i++)
        {
            for (auto j = 0; j < map[i].size(); j++)
            {
                if (map[i][j] == '.') continue;
                if (map[i][j] == '#') obstructions.push_back(map[i][j]);
                if (map[i][j] == '^')
                {
                    startPos.first = i;
                    startPos.second = j;
                }
            }
        }
    }

    void Part1()
    {
        std::pair<int,int> startPos;
        std::vector<int> obstructions;
        std::vector<std::vector<char>> map = Utils::ParseToVectorVector<char>(input_test);
        GetObsAndStartPos(startPos, obstructions, map);

        int distinctPositions = 0;
    }

    void Part2()
    {
    }

private:
    std::string_view input_test{R"(..\src\Input\day6_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day6.txt)"};
};

#endif //DAY6_H
