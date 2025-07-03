from typing import List, Dict


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(history: Dict[int, List[str]], number: int) -> List[str]:
            if number == 0:
                return []
            if number == 1:
                return ["()"]
            if number in history:
                return history[number]

            result = []
            for i in range(number):
                current = []
                previous = backtrack(history, number - 1 if i == 0 else number - i)
                for p in previous:
                    if i == 0:
                        current.append("()" + p)
                    else:
                        current.append("(" + p + ")")

                previous = backtrack(history, number - (number - i) - 1)
                for c in current:
                    if not previous:
                        result.append(c)
                    else:
                        for p in previous:
                            result.append(c + p)

            history[number] = result
            return result

        return backtrack({}, n)
