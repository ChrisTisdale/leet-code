pub struct Solution {}

struct PhoneChars<'a> {
    chars: &'a [char],
}

static DIGIT_CHARACTERS: &[PhoneChars] = &[
    PhoneChars {
        chars: &['a', 'b', 'c'],
    },
    PhoneChars {
        chars: &['d', 'e', 'f'],
    },
    PhoneChars {
        chars: &['g', 'h', 'i'],
    },
    PhoneChars {
        chars: &['j', 'k', 'l'],
    },
    PhoneChars {
        chars: &['m', 'n', 'o'],
    },
    PhoneChars {
        chars: &['p', 'q', 'r', 's'],
    },
    PhoneChars {
        chars: &['t', 'u', 'v'],
    },
    PhoneChars {
        chars: &['w', 'x', 'y', 'z'],
    },
];

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut set: Vec<String> = Vec::new();
        for d in digits.chars() {
            let phone_chars = &DIGIT_CHARACTERS[d as usize - '2' as usize];
            let last = set;
            if last.is_empty() {
                let length = phone_chars.chars.len();
                set = Vec::with_capacity(length);
                for i in 0..length {
                    let mut string = String::with_capacity(1);
                    string.push(phone_chars.chars[i]);
                    set.push(string);
                }
            } else {
                let length = last.len() * phone_chars.chars.len();
                let mut c: usize = 0;
                set = Vec::with_capacity(length);
                for i in 0..length {
                    let mut string = String::with_capacity(last[i % last.len()].len() + 1);
                    string.push_str(&last[i % last.len()]);
                    string.push(phone_chars.chars[c % phone_chars.chars.len()]);
                    set.push(string);
                    if set.len() % last.len() == 0 {
                        c += 1;
                    }
                }
            };
        }

        set
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec!["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"];
        let result = Solution::letter_combinations(String::from("23"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn example_2_test() {
        let expected: Vec<&str> = vec![];
        let result = Solution::letter_combinations(String::new());
        assert_eq!(result.len(), expected.len());
    }

    #[test]
    fn example_3_test() {
        let expected = vec!["a", "b", "c"];
        let result = Solution::letter_combinations(String::from("2"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn four_number_tests() {
        let expected = vec![
            "agpw", "bgpw", "cgpw", "ahpw", "bhpw", "chpw", "aipw", "bipw", "cipw", "agqw", "bgqw",
            "cgqw", "ahqw", "bhqw", "chqw", "aiqw", "biqw", "ciqw", "agrw", "bgrw", "cgrw", "ahrw",
            "bhrw", "chrw", "airw", "birw", "cirw", "agsw", "bgsw", "cgsw", "ahsw", "bhsw", "chsw",
            "aisw", "bisw", "cisw", "agpx", "bgpx", "cgpx", "ahpx", "bhpx", "chpx", "aipx", "bipx",
            "cipx", "agqx", "bgqx", "cgqx", "ahqx", "bhqx", "chqx", "aiqx", "biqx", "ciqx", "agrx",
            "bgrx", "cgrx", "ahrx", "bhrx", "chrx", "airx", "birx", "cirx", "agsx", "bgsx", "cgsx",
            "ahsx", "bhsx", "chsx", "aisx", "bisx", "cisx", "agpy", "bgpy", "cgpy", "ahpy", "bhpy",
            "chpy", "aipy", "bipy", "cipy", "agqy", "bgqy", "cgqy", "ahqy", "bhqy", "chqy", "aiqy",
            "biqy", "ciqy", "agry", "bgry", "cgry", "ahry", "bhry", "chry", "airy", "biry", "ciry",
            "agsy", "bgsy", "cgsy", "ahsy", "bhsy", "chsy", "aisy", "bisy", "cisy", "agpz", "bgpz",
            "cgpz", "ahpz", "bhpz", "chpz", "aipz", "bipz", "cipz", "agqz", "bgqz", "cgqz", "ahqz",
            "bhqz", "chqz", "aiqz", "biqz", "ciqz", "agrz", "bgrz", "cgrz", "ahrz", "bhrz", "chrz",
            "airz", "birz", "cirz", "agsz", "bgsz", "cgsz", "ahsz", "bhsz", "chsz", "aisz", "bisz",
            "cisz",
        ];
        let result = Solution::letter_combinations(String::from("2479"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn same_number_multiple_times() {
        let expected = vec![
            "aaa", "baa", "caa", "aba", "bba", "cba", "aca", "bca", "cca", "aab", "bab", "cab",
            "abb", "bbb", "cbb", "acb", "bcb", "ccb", "aac", "bac", "cac", "abc", "bbc", "cbc",
            "acc", "bcc", "ccc",
        ];
        let result = Solution::letter_combinations(String::from("222"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_3_test() {
        let expected = vec!["d", "e", "f"];
        let result = Solution::letter_combinations(String::from("3"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_4_test() {
        let expected = vec!["g", "h", "i"];
        let result = Solution::letter_combinations(String::from("4"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_5_test() {
        let expected = vec!["j", "k", "l"];
        let result = Solution::letter_combinations(String::from("5"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_6_test() {
        let expected = vec!["m", "n", "o"];
        let result = Solution::letter_combinations(String::from("6"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_7_test() {
        let expected = vec!["p", "q", "r", "s"];
        let result = Solution::letter_combinations(String::from("7"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_8_test() {
        let expected = vec!["t", "u", "v"];
        let result = Solution::letter_combinations(String::from("8"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }

    #[test]
    fn number_9_test() {
        let expected = vec!["w", "x", "y", "z"];
        let result = Solution::letter_combinations(String::from("9"));
        assert_eq!(result.len(), expected.len());
        for value in &expected {
            assert!(
                result.contains(&String::from(*value)),
                "Didn't contain {value}"
            );
        }
    }
}
