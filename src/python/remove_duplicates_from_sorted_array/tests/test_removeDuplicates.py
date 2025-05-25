from unittest import TestCase

from remove_duplicates_from_sorted_array.removeDuplicates import Solution


class TestSolution(TestCase):
    def test_remove_duplicates_one(self):
        nums = [1, 1, 2]
        expected = [1,2]

        count = Solution().removeDuplicates(nums)
        assert count == len(expected)
        for i in range(count):
            assert nums[i] == expected[i]

    def test_remove_duplicates_two(self):
        nums = [0,0,1,1,1,2,2,3,3,4]
        expected = [0,1,2,3,4]

        count = Solution().removeDuplicates(nums)
        assert count == len(expected)
        for i in range(count):
            assert nums[i] == expected[i]
