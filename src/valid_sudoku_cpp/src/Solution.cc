#include "Solution.h"
#include <set>

struct Offsets {
    std::size_t row;
    std::size_t col;
};

static const Offsets OFFSET_UPDATES[] = {
    { 0, 0 },
    { 0, 3 },
    { 0, 6 },
    { 3, 0 },
    { 3, 3 },
    { 3, 6 },
    { 6, 0 },
    { 6, 3 },
    { 6, 6 }
};

bool Solution::isValidSudoku(std::vector<std::vector<char>>& board) {
    std::set<char> row;
    std::set<char> col;
    std::set<char> grid;
    for (std::size_t i = 0; i < 9; ++i) {
        for (std::size_t j = 0; j < 9; ++j) {
            auto r = board[j][i];
            auto c = board[i][j];
            if (r != '.' && !row.insert(r).second) return false;
            if (c != '.' && !col.insert(c).second) return false;
            auto offset = &OFFSET_UPDATES[i];
            std::size_t gridRow;
            switch (j)
            {
            case 0:
            case 1:
            case 2:
                gridRow = offset->row;
                break;
            case 3:
            case 4:
            case 5:
                gridRow = 1 + offset->row;
                break;
            default:
                gridRow = 2 + offset->row;
                break;
            }

            auto gridCol = j % 3 + offset->col;
            auto g = board[gridRow][gridCol];
            if (g != '.' && !grid.insert(g).second) return false;
        }

        row.clear();
        col.clear();
        grid.clear();
    }

    return true;
}
