from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        grid = [["."] * n for i in range(n)]
        result = []

        def can_place_queen(r: int, c: int) -> bool:
            for i in range(r):
                if grid[i][c] == "Q":
                    return False

                delta = r - i

                if c >= delta and grid[i][c - delta] == "Q":
                    return False

                if n > (c + delta) and grid[i][c + delta] == "Q":
                    return False

            return True

        def backtrack(row: int) -> None:
            if row == n:
                result.append(["".join(r) for r in grid])
                return

            for col in range(n):
                if can_place_queen(row, col):
                    grid[row][col] = "Q"
                    backtrack(row + 1)
                    grid[row][col] = "."

        backtrack(0)
        return result
