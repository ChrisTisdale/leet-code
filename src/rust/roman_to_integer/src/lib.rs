pub struct Solution {}

#[inline]
const fn roman_lookup(c: u8) -> i32 {
    match c {
        b'M' => 1000,
        b'D' => 500,
        b'C' => 100,
        b'L' => 50,
        b'X' => 10,
        b'V' => 5,
        _ => 1,
    }
}

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut result = 0;
        let mut last = 0;
        for c in s.bytes().rev() {
            let current = roman_lookup(c);
            result = if current < last {
                result - current
            } else {
                result + current
            };

            last = current;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::roman_to_int(String::from("III"));
        assert_eq!(result, 3);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::roman_to_int(String::from("LVIII"));
        assert_eq!(result, 58);
    }

    #[test]
    fn example_3_test() {
        let result = Solution::roman_to_int(String::from("MCMXCIV"));
        assert_eq!(result, 1994);
    }

    #[test]
    fn example_4_test() {
        let result = Solution::roman_to_int(String::from("XX"));
        assert_eq!(result, 20);
    }
}
