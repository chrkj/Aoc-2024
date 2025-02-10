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
        Utils::Timer timer;
        const auto diskmap = Utils::ParseToVector<char>(input_test);

        // Expand
        int id = 0;
        bool isFreeSpace = false;
        std::vector<File> fileMap;
        for (const auto size: diskmap)
        {
            File f(id, size - '0', isFreeSpace);
            if (isFreeSpace)
                f.id = -1;
            if (size != '0')
                fileMap.push_back(f);
            if (!isFreeSpace)
                id++;
            isFreeSpace = !isFreeSpace;
        }

        // Compress
        for (int r = fileMap.size()-1; r > 0; --r)
        {
            for (int l = 0; l < r; ++l)
            {
                if (fileMap[l].isFreeSpace && !fileMap[r].isFreeSpace && fileMap[l].size >= fileMap[r].size)
                {
                    if (fileMap.size() == fileMap[r].size)
                        iter_swap(fileMap.begin() + l, fileMap.begin() + r);
                    else
                    {
                        const int newSize = fileMap[l].size - fileMap[r].size;
                        iter_swap(fileMap.begin() + l, fileMap.begin() + r);
                        fileMap[r].size = fileMap[l].size;
                        fileMap.insert(fileMap.begin()+l+1, File(-1,newSize,true));
                    }
                    break;
                }
            }
        }

        // Checksum
        int idd = 0;
        long long checksum = 0;
        for (const auto file: fileMap)
        {
            if (file.size == 0) continue;
            for (int i = idd; i < file.size + idd; ++i)
            {
                printf("%d * %d \n", i, file.id);
                if (file.id != -1)
                    checksum += i * file.id;
            }
            idd += file.size;
        }
        printf("Checksum: ""%lld\n", checksum);
    }

private:
    std::string_view input_test{R"(..\src\Input\day9_test.txt)"};
    std::string_view input_data{R"(..\src\Input\day9.txt)"};

    struct File
    {
        int id;
        int size;
        bool isFreeSpace;
    };
};

#endif //DAY9_H
