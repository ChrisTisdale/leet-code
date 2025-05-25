from typing import List


class Solution:
    OFFSET_UPDATES = [
        (0, 0),
        (0, 3),
        (0, 6),
        (3, 0),
        (3, 3),
        (3, 6),
        (6, 0),
        (6, 3),
        (6, 6)
    ]

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            row = set()
            col = set()
            grid = set()

            for j in range(0, 9):
                r = board[j][i]
                c = board[i][j]

                if r != '.' and (r in row):
                    return False
                if c != '.' and (c in col):
                    return False
                row.add(r)
                col.add(c)

                offset = self.OFFSET_UPDATES[i]

                def get_offset():
                    if j in (0, 1, 2):
                        return offset[0]
                    if j in (3, 4, 5):
                        return offset[0] + 1
                    return offset[0] + 2

                grid_row = get_offset()
                grid_col = j % 3 + offset[1]

                g = board[grid_row][grid_col]
                if g != '.' and g in grid:
                    return False
                grid.add(g)
        return True
