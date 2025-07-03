class Solution:
    def kthCharacter(self, k: int):
        index = k - 1
        increments = 0

        while index > 0:
            p = 1
            while p * 2 <= index:
                p *= 2

            increments += 1
            index -= p

        return chr(ord('a') + (increments % 26))
