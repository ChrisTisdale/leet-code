import unittest

from generate_parentheses.generateParentheses import Solution


class TestSolution(unittest.TestCase):
    def test_example_1(self):
        result = Solution().generateParenthesis(1)
        expected = ["()"]
        self.assertEqual(len(result), len(expected))
        for item in expected:
            self.assertIn(item, result)

    def test_example_2(self):
        result = Solution().generateParenthesis(2)
        expected = ["()()", "(())"]
        self.assertEqual(len(result), len(expected))
        for item in expected:
            self.assertIn(item, result)

    def test_example_3(self):
        result = Solution().generateParenthesis(3)
        expected = ["()()()", "(())()", "(()())", "((()))", "()(())"]
        self.assertEqual(len(result), len(expected))
        for item in expected:
            self.assertIn(item, result)

    def test_example_4(self):
        result = Solution().generateParenthesis(4)
        expected = ["()()()()", "()(())()", "()(()())", "()((()))", "()()(())", "(()()())", "((())())", "((()()))",
                    "(((())))", "(()(()))", "(())(())", "(())()()", "((()))()", "(()())()"]
        self.assertEqual(len(result), len(expected))
        for item in expected:
            self.assertIn(item, result)

    def test_example_5(self):
        result = Solution().generateParenthesis(5)
        expected = ["()()()()()", "()()(())()", "()()(()())", "()()((()))", "()()()(())", "()(()()())", "()((())())",
                    "()((()()))", "()(((())))", "()(()(()))", "()(())(())", "()(())()()", "()((()))()", "()(()())()",
                    "(()()()())", "(()(())())", "(()(()()))", "(()((())))", "(()()(()))", "((()()()))", "(((())()))",
                    "(((()())))", "((((()))))", "((()(())))", "((())(()))", "((())()())", "(((()))())", "((()())())",
                    "(()()())()", "((())())()", "((()()))()", "(((())))()", "(()(()))()", "(()())()()", "((()))()()",
                    "(()())(())", "((()))(())", "(())()()()", "(())(())()", "(())(()())", "(())((()))", "(())()(())"]
        self.assertEqual(len(result), len(expected))
        for item in expected:
            self.assertIn(item, result)


if __name__ == '__main__':
    unittest.main()
