#ifndef DAY6_H
#define DAY6_H

#include <iostream>
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

    void PrintMap(std::vector<std::vector<char>> map)
    {
        for (auto line: map)
            for (auto c: line)
                std::cout << c;
            std::cout << std::endl;
    }

    bool CheckBounds(const std::vector<std::vector<char>>& map, int i, int j)
    {
        if (i > map.size() - 1 || i < 0 || j > map[0].size() - 1 || j < 0)
            return false;
        return true;
    }

    void Part1()
    {
        std::vector<int> obstructions;
        std::pair<int,int> currentPos;
        std::vector<std::vector<char>> map = Utils::ParseToVectorVector<char>(input_data);
        GetObsAndStartPos(currentPos, obstructions, map);

        constexpr int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        int distinctPositions = 1;
        int i = currentPos.first, j = currentPos.second, currentDir = 0;
        while (CheckBounds(map, i+dir[currentDir][0], j+dir[currentDir][1]))
        {
            if (map[i+dir[currentDir][0]][j+dir[currentDir][1]] == '#')
                currentDir == 3 ? currentDir = 0 : currentDir++;
            i += dir[currentDir][0], j += dir[currentDir][1];
            if (map[i][j] != '.') continue;
            distinctPositions++;
            map[i][j] = 'x';
        }
        printf("Distinct positions: %d \n", distinctPositions);
    }

    void Part2()
    {
    }

private:
    std::string_view input_test{R"(..\src\Input\day6_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day6.txt)"};
};

#endif //DAY6_H
