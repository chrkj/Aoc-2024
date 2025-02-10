#ifndef DAY9_H
#define DAY9_H

#include <string_view>

#include "../Utils/Utils.h"

class Day9
{
public:
    Day9() = default;

    void Part1()
    {
        Utils::Timer timer;
        const auto diskmap = Utils::ParseToVector<char>(input_data);

        // Expand
        int id = 0;
        bool isFreeSpace = false;
        std::vector<int> expandedMap;
        for (auto value: diskmap)
        {
            for (int i = 0; i < value - '0'; ++i)
            {
                if (isFreeSpace)
                    expandedMap.push_back(-1);
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
            if (expandedMap[l] != -1)
            {
                l++;
                continue;
            }
            if (expandedMap[r] == -1)
            {
                r--;
                continue;
            }
            iter_swap(expandedMap.begin() + l, expandedMap.begin() + r);
        }

        // Checksum
        long long checksum = 0;
        for (int i = 0; i < expandedMap.size(); ++i)
        {
            if (expandedMap[i] == -1)
                break;
            checksum += static_cast<long long>(expandedMap[i]) * i;;
        }
        printf("Checksum: ""%lld\n", checksum);
    }

    void Part2()
    {

    }

private:
    std::string_view input_test{R"(..\src\Input\day9_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day9.txt)"};
};

#endif //DAY9_H
