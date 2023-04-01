use std::cmp::max;

pub struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut count = 0;
        let mut max_value = 0;
        let mut start = 0;
        let mut chars: Vec<u32> = vec![0, 0, 0, 0, 0, 0, 0, 0];

        for c in s.chars() {
            let cast = c as u32;
            let bin = (cast / 32) as usize;
            let check = cast % 32;
            if chars[bin] & (1 << check) > 0 {
                for l in s.chars().skip(start) {
                    let c2 = l as u32;
                    let bin2 = (c2 / 32) as usize;
                    let c3 = c2 % 32;
                    chars[bin2] = chars[bin2] ^ (1 << c3);
                    start += 1;
                    count -= 1;
                    if l == c {
                        break;
                    }
                }
            }

            chars[bin] = chars[bin] | (1 << check);
            count += 1;
            max_value = max(count, max_value);
        }

        return max_value;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::length_of_longest_substring(String::from("abcabcbb"));
        assert_eq!(result, 3);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::length_of_longest_substring(String::from("bbbbb"));
        assert_eq!(result, 1);
    }

    #[test]
    fn example_3_test() {
        let result = Solution::length_of_longest_substring(String::from("pwwkew"));
        assert_eq!(result, 3);
    }

    #[test]
    fn example_4_test() {
        let result = Solution::length_of_longest_substring(String::from(" -&${}kj3222"));
        assert_eq!(result, 10);
    }

    #[test]
    fn example_5_test() {
        let result = Solution::length_of_longest_substring(String::from("  &${}kj3222"));
        assert_eq!(result, 9);
    }

    #[test]
    fn example_6_test() {
        let result = Solution::length_of_longest_substring(String::from("dvdf"));
        assert_eq!(result, 3);
    }

    #[test]
    fn case_doesnt_matter_test() {
        let result = Solution::length_of_longest_substring(String::from("aAaAaAaAaA"));
        assert_eq!(result, 2);
    }

    #[test]
    fn example_7_test() {
        let result = Solution::length_of_longest_substring(String::from("tmmzuxt"));
        assert_eq!(result, 5);
    }

    #[test]
    fn all_character_and_letters_test() {
        let result = Solution::length_of_longest_substring(String::from(
            "asdfghjkl;'qwertyuiop[]\\zxcvbnm,./1234567890-=!@#$%^&*()_+ASDFGHJKLQWERTYUIOPZXCVBNM",
        ));
        assert_eq!(result, 84);
    }
}
