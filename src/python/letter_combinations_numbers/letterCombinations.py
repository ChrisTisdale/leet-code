from typing import List


class Solution:
    mapper = {
        "2" : "abc",
        "3" : "def",
        "4" : "ghi",
        "5" : "jkl",
        "6" : "mno",
        "7" : "pqrs",
        "8" : "tuv",
        "9" : "wxyz",
    }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        result = []

        def backtrack(index, path):
            if index == len(digits):
                result.append("".join(path))
                return

            possibleLetters = self.mapper[digits[index]]
            for letter in possibleLetters:
                path.append(letter)
                backtrack(index + 1, path)
                path.pop()

        backtrack(0, [])
        return result
