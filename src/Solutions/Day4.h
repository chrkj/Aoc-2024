#ifndef DAY4_H
#define DAY4_H

#include <string>
#include <vector>
#include <fstream>
#include <string_view>

class Day4
{
public:
    Day4() = default;

    void Part1()
    {
        std::string line;
        std::ifstream ifs(input_data.data());
        std::vector<std::string> puzzle;
        while (getline(ifs, line))
            puzzle.push_back(line);

        int occurrences = 0;
        for (int i = 0; i < puzzle.size(); i++)
            for (int j = 0; j < puzzle[0].size(); j++)
                FindXmas(i, j, puzzle, occurrences);

        printf("Occurrences: %d", occurrences);
    }

    bool CheckDir(const int i, const int j, const int dir[], const std::vector<std::string>& puzzle) const
    {
        std::string target = "XMAS";
        const int MAX_I = puzzle.size();
        const int MAX_J = puzzle[0].size();

        for (int k = 0; k < target.size(); ++k)
        {
            int newRow = i + k * dir[0];
            int newCol = j + k * dir[1];

            if (newRow < 0 || newRow >= MAX_I || newCol < 0 || newCol >= MAX_J)
                return false;

            if (puzzle[newRow][newCol] != target[k])
                return false;
        }
        return true;
    }

    void FindXmas(const int i, const int j, const std::vector<std::string>& puzzle, int& occurrences) const
    {
        const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0,-1}, {1, -1}, {1, 0}, {1, 1}};
        for (int k = 0; k < 8; k++)
            if (CheckDir(i, j, dir[k], puzzle))
                occurrences++;
    }

    void Part2() const
    {
        std::string line;
        std::ifstream ifs(input_data.data());
        std::vector<std::string> puzzle;
        while (getline(ifs, line))
            puzzle.push_back(line);

        int occurrences = 0;
        for (int i = 0; i < puzzle.size(); i++)
            for (int j = 0; j < puzzle[0].size(); j++)
                Find_X_mas(i, j, puzzle, occurrences);

        printf("Occurrences: %d", occurrences);
    }

    bool CheckCross(const int i, const int j, const std::vector<std::string>& puzzle, int occurrences) const
    {
        const int MAX_I = puzzle.size();
        const int MAX_J = puzzle[0].size();
        constexpr int dir[4][2] = {{-1, -1}, {-1, 1},{1, -1}, {1, 1}};
        for (int k = 0; k < 4; ++k)
        {
            const int newRow = i + dir[k][0];
            const int newCol = j + dir[k][1];
            if (newRow < 0 || newRow >= MAX_I || newCol < 0 || newCol >= MAX_J)
                return false;
        }
        if ((puzzle[i-1][j-1] == 'M' && puzzle[i+1][j-1] == 'M' && puzzle[i+1][j+1] == 'S' && puzzle[i-1][j+1] == 'S') ||
            (puzzle[i-1][j-1] == 'M' && puzzle[i-1][j+1] == 'M' && puzzle[i+1][j-1] == 'S' && puzzle[i+1][j+1] == 'S') ||
            (puzzle[i+1][j+1] == 'M' && puzzle[i-1][j+1] == 'M' && puzzle[i-1][j-1] == 'S' && puzzle[i+1][j-1] == 'S') ||
            (puzzle[i+1][j+1] == 'M' && puzzle[i+1][j-1] == 'M' && puzzle[i-1][j-1] == 'S' && puzzle[i-1][j+1] == 'S'))
                return true;
        return false;
    }

    void Find_X_mas(const int i, const int j, const std::vector<std::string>& puzzle, int& occurrences) const
    {
        if (puzzle[i][j] != 'A')
            return;
        if (CheckCross(i, j, puzzle, occurrences))
            occurrences++;
    }

private:
    std::string_view input_test{ R"(..\src\Input\day4_test.txt)"};
    std::string_view input_data{ R"(..\src\Input\day4.txt)"};
};

#endif //DAY4_H
