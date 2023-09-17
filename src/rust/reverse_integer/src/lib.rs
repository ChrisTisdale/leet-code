pub struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut temp: i32 = x;
        let mut reverse: i32 = 0;
        while temp != 0 {
            let output = reverse
                .checked_mul(10)
                .and_then(|r| r.checked_add(temp % 10));
            if output.is_none() {
                return 0;
            }

            reverse = output.unwrap();
            temp /= 10;
        }

        reverse
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::reverse(123);
        assert_eq!(result, 321);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::reverse(-123);
        assert_eq!(result, -321);
    }

    #[test]
    fn example_3_test() {
        let result = Solution::reverse(120);
        assert_eq!(result, 21);
    }

    #[test]
    fn zero_test() {
        let result = Solution::reverse(0);
        assert_eq!(result, 0);
    }

    #[test]
    fn large_number_test() {
        let result = Solution::reverse(1_234_567_890);
        assert_eq!(result, 987654321);
    }

    #[test]
    fn multiple_zeros_tests() {
        let result = Solution::reverse(1_230_000_000);
        assert_eq!(result, 321);
    }

    #[test]
    fn overflow_test() {
        let result = Solution::reverse(1_534_236_469);
        assert_eq!(result, 0);
    }
}
