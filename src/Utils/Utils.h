#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>


namespace Utils
{
    template <typename T>
    std::vector<std::vector<T>> ParseToVectorVector(std::string_view filePath, char delimiter)
    {
        std::vector<std::vector<T>> result;
        std::ifstream file(filePath.data());

        if (!file.is_open())
            throw std::runtime_error("Could not open file: " + std::string(filePath));

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<T> row;
            std::stringstream lineStream(line);
            std::string cell;

            while (std::getline(lineStream, cell, delimiter))
            {
                std::stringstream cellStream(cell);
                T value;
                cellStream >> value;
                if (!cellStream.fail())
                    row.push_back(value);
            }
            result.push_back(row);
        }
        file.close();
        return result;
    }

    template <typename T>
    std::vector<std::vector<T>> ParseToVectorVector(std::string_view filePath)
    {
        std::vector<std::vector<T>> result;
        std::ifstream file(filePath.data());

        if (!file.is_open())
            throw std::runtime_error("Could not open file: " + std::string(filePath));

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<T> row;
            std::stringstream lineStream(line);

            std::string cell;
            for (int i = 0; i < lineStream.str().size(); i++)
            {
                cell = line[i];
                std::stringstream cellStream(cell);
                T value;
                cellStream >> value;
                if (!cellStream.fail())
                    row.push_back(value);
            }
            result.push_back(row);
        }
        file.close();
        return result;
    }

    template <typename T>
    std::vector<T> ParseToVector(std::string_view filePath)
    {
        std::vector<T> result;
        std::ifstream file(filePath.data());

        if (!file.is_open())
            throw std::runtime_error("Could not open file: " + std::string(filePath));

        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream lineStream(line);
            T value;
            while (lineStream >> value)
            {
                result.push_back(value);
            }
        }
        file.close();
        return result;
    }

    struct Timer
    {
        std::chrono::high_resolution_clock::time_point start, end;
        std::chrono::duration<float> duration;

        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;

            float ms = duration.count();
            std::cout << ms << "ms" << std::endl;
        }

    };
}

#endif //UTILS_H
