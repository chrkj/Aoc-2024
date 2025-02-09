#ifndef DAY9_H
#define DAY9_H

#include <cstdint>
#include <string_view>

#include "../Utils/Utils.h"

class Day9
{
public:
    Day9() = default;

    void Part1()
    {
        auto diskmap = Utils::ParseToVector<char>(input_data);

        // Expand
        int id = 0;
        bool isFreeSpace = false;
        std::vector<char> expandedMap;
        for (auto value: diskmap)
        {
            for (int i = 0; i < value - '0'; ++i)
            {
                if (isFreeSpace)
                    expandedMap.push_back('.');
                else
                    expandedMap.push_back(id);
            }
            if (!isFreeSpace)
                id++;
            isFreeSpace = !isFreeSpace;
        }

        // Compress
        int l = 0;
        int r = expandedMap.size() - 1;
        while (l < r)
        {
            if (expandedMap[l] != '.')
            {
                l++;
                continue;
            }
            if (expandedMap[r] == '.')
            {
                r--;
                continue;
            }
            iter_swap(expandedMap.begin() + l, expandedMap.begin() + r);
        }

        // Checksum
        uint64_t checksum = 0;
        for (uint64_t i = 0; i < expandedMap.size(); ++i)
        {
            if (expandedMap[i] == '.') break;
            checksum += static_cast<uint64_t>(expandedMap[i]) * i;
        }
        printf("Checksum: %llu\n", checksum);
    }

    void Part2()
    {
    }

private:
    std::string_view input_test{R"(..\src\Input\day9_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day9.txt)"};
};

#endif //DAY9_H
