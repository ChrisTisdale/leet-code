import unittest

from find_the_kth_character_in_string_game_i.kthCharacter import Solution


class MyTestCase(unittest.TestCase):
    def test_example_1(self):
        result = Solution().kthCharacter(5)
        self.assertEqual("b", result)

    def test_example_2(self):
        result = Solution().kthCharacter(10)
        self.assertEqual("c", result)

    def test_example_3(self):
        result = Solution().kthCharacter(500)
        self.assertEqual("h", result)

    def test_example_4(self):
        result = Solution().kthCharacter(0)
        self.assertEqual("a", result)


if __name__ == '__main__':
    unittest.main()
