import unittest
from typing import List

from n_queens.nQueens import Solution


class TestSolution(unittest.TestCase):
    def validate(self, result: List[List[str]], expected: List[List[str]]) -> None:
        self.assertEqual(len(expected), len(result))
        for e in expected:
            self.assertTrue(e in result)

    def test_example_1(self):
        result = Solution().solveNQueens(1)
        expected = [["Q"]]
        self.validate(result, expected)

    def test_example_2(self):
        result = Solution().solveNQueens(2)
        self.validate(result, [])

    def test_example_3(self):
        result = Solution().solveNQueens(3)
        self.validate(result, [])

    def test_example_4(self):
        result = Solution().solveNQueens(4)
        self.validate(result, [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]])

    def test_example_5(self):
        result = Solution().solveNQueens(5)
        self.validate(result,
                      [['Q....', '..Q..', '....Q', '.Q...', '...Q.'], ['Q....', '...Q.', '.Q...', '....Q', '..Q..'],
                       ['.Q...', '...Q.', 'Q....', '..Q..', '....Q'], ['.Q...', '....Q', '..Q..', 'Q....', '...Q.'],
                       ['..Q..', 'Q....', '...Q.', '.Q...', '....Q'], ['..Q..', '....Q', '.Q...', '...Q.', 'Q....'],
                       ['...Q.', 'Q....', '..Q..', '....Q', '.Q...'], ['...Q.', '.Q...', '....Q', '..Q..', 'Q....'],
                       ['....Q', '.Q...', '...Q.', 'Q....', '..Q..'], ['....Q', '..Q..', 'Q....', '...Q.', '.Q...']])


if __name__ == '__main__':
    unittest.main()
