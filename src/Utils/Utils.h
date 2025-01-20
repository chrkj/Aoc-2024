#ifndef UTILS_H
#define UTILS_H

#include <fstream>
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
}

#endif //UTILS_H
