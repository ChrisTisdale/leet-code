from unittest import TestCase

from letter_combinations_numbers.letterCombinations import Solution


class TestSolution(TestCase):
    def test_empty_string_returns_empty_results(self):
        result = Solution().letterCombinations("")
        assert result == []

    def test_digit_2_test(self):
        result = Solution().letterCombinations("2")
        assert result == ["a","b","c"]

    def test_digit_2_3_test(self):
        result = Solution().letterCombinations("23")
        expected = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
        for r in expected:
            assert result.__contains__(r)

    def test_four_number_test(self):
        result = Solution().letterCombinations("2479")
        expected = ["agpw", "bgpw", "cgpw", "ahpw", "bhpw", "chpw", "aipw", "bipw", "cipw", "agqw", "bgqw", "cgqw",
                    "ahqw", "bhqw", "chqw", "aiqw", "biqw", "ciqw", "agrw", "bgrw", "cgrw", "ahrw", "bhrw", "chrw",
                    "airw", "birw", "cirw", "agsw", "bgsw", "cgsw", "ahsw", "bhsw", "chsw", "aisw", "bisw", "cisw",
                    "agpx", "bgpx", "cgpx", "ahpx", "bhpx", "chpx", "aipx", "bipx", "cipx", "agqx", "bgqx", "cgqx",
                    "ahqx", "bhqx", "chqx", "aiqx", "biqx", "ciqx", "agrx", "bgrx", "cgrx", "ahrx", "bhrx", "chrx",
                    "airx", "birx", "cirx", "agsx", "bgsx", "cgsx", "ahsx", "bhsx", "chsx", "aisx", "bisx", "cisx",
                    "agpy", "bgpy", "cgpy", "ahpy", "bhpy", "chpy", "aipy", "bipy", "cipy", "agqy", "bgqy", "cgqy",
                    "ahqy", "bhqy", "chqy", "aiqy", "biqy", "ciqy", "agry", "bgry", "cgry", "ahry", "bhry", "chry",
                    "airy", "biry", "ciry", "agsy", "bgsy", "cgsy", "ahsy", "bhsy", "chsy", "aisy", "bisy", "cisy",
                    "agpz", "bgpz", "cgpz", "ahpz", "bhpz", "chpz", "aipz", "bipz", "cipz", "agqz", "bgqz", "cgqz",
                    "ahqz", "bhqz", "chqz", "aiqz", "biqz", "ciqz", "agrz", "bgrz", "cgrz", "ahrz", "bhrz", "chrz",
                    "airz", "birz", "cirz", "agsz", "bgsz", "cgsz", "ahsz", "bhsz", "chsz", "aisz", "bisz", "cisz"]
        for r in expected:
            assert result.__contains__(r)
