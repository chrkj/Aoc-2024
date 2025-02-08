#ifndef DAY7_H
#define DAY7_H

#include <iostream>
#include <string_view>
#include <unordered_map>

#include "../Utils/Utils.h"

class Day8
{
public:
    Day8() = default;

    static bool CheckBound(const int col, const int row, const int maxCol, const int maxRow)
    {
        if (col >= maxCol || row >= maxRow || col < 0 || row < 0)
            return false;
        return true;
    }

    void Part1()
    {
        auto antennas = std::unordered_map<char, std::vector<coord>>();
        auto map = Utils::ParseToVectorVector<char>(input_data);
        for (auto row = 0; row < map.size(); row++)
            for (auto col = 0; col < map[row].size(); col++)
                if (map[row][col] != '.')
                    antennas[map[row][col]].push_back(coord(row, col));

        int uniqueLocations = 0;
        for (auto antennaType: antennas)
        {
            for (int i = 0; i < antennaType.second.size()-1; ++i)
            {
                auto coord1 = antennaType.second[i];
                for (int j = i+1; j < antennaType.second.size(); ++j)
                {
                    auto coord2 = antennaType.second[j];
                    int deltaRow = coord1.row - coord2.row;
                    int deltaCol = coord1.col - coord2.col;

                    if (CheckBound(coord1.row + deltaRow, coord1.col + deltaCol, map.size(), map[0].size()))
                    {
                        if (map[coord1.row + deltaRow][coord1.col + deltaCol] != '#')
                            uniqueLocations++;
                        map[coord1.row + deltaRow][coord1.col + deltaCol] = '#';
                    }
                    if (CheckBound(coord2.row - deltaRow, coord2.col - deltaCol, map.size(), map[0].size()))
                    {
                        if (map[coord2.row - deltaRow][coord2.col - deltaCol] != '#')
                            uniqueLocations++;
                        map[coord2.row - deltaRow][coord2.col - deltaCol] = '#';
                    }
                }
            }
        }
        printf("Unique locations: %d\n", uniqueLocations);
    }

    void Part2()
    {
    }

private:
    std::string_view input_test{R"(..\src\Input\day8_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day8.txt)"};

    struct coord
    {
        int row;
        int col;
    };
};

#endif //DAY7_H
