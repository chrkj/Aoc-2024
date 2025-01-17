#ifndef DAY1_H
#define DAY1_H

#include <algorithm>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string_view>
#include <sstream>
#include <unordered_map>

class Day1
{
public:
    Day1() = default;

    void Part1() const
    {
        int arr1[1000];
        int arr2[1000];
        int size = 0;
        int totalDistance = 0;

        std::ifstream istrm(input_data.data());
        if (!istrm)
            std::printf("Error opening: %s\n.", strerror(errno));

        std::string line;
        while (getline(istrm, line))
        {
            std::istringstream iss(line);
            int num1, num2;

            if (iss >> num1 >> num2)
            {
                arr1[size] = num1;
                arr2[size] = num2;
            }
            else
                std::printf("Invalid input format in line: %s\n", line.c_str());
            size++;
        }

        std::ranges::sort(arr1);
        std::ranges::sort(arr2);

        for (int i = 0; i < size; ++i)
            totalDistance += std::abs(arr1[i] - arr2[i]);

        std::printf("Total distance: %i", totalDistance);
    }

    void Part2() const
    {
        int size = 0;
        int arr[1000];
        int totalScore = 0;
        std::unordered_map<int, int> occurrences;

        std::ifstream istrm(input_data.data());
        if (!istrm)
            std::printf("Error opening: %s\n.", strerror(errno));

        std::string line;
        while (getline(istrm, line))
        {
            std::istringstream iss(line);
            int num1, num2;

            if (iss >> num1 >> num2)
            {
                arr[size] = num1;
                occurrences[num2]++;
            }
            else
                std::printf("Invalid input format in line: %s\n", line.c_str());
            size++;
        }

        for (int i = 0; i < size; i++)
        {
            if (occurrences.contains(arr[i]))
                totalScore += occurrences[arr[i]] * arr[i];
        }

        std::printf("Total distance: %i", totalScore);
    }

private:
    std::string_view input_test{ R"(..\src\Input\day1_test.txt)"};
    std::string_view input_data{ R"(..\src\Input\day1.txt)"};
};

#endif //DAY1_H
