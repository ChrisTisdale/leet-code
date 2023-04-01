pub struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut temp: i32 = x;
        let mut reverse: i32 = 0;
        while temp != 0 {
            let output = reverse
                .checked_mul(10)
                .map_or(None, |r| r.checked_add(temp % 10));
            if output.is_none() {
                return 0;
            }

            reverse = output.unwrap();
            temp = temp / 10;
        }

        return reverse;
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
        let result = Solution::reverse(1234567890);
        assert_eq!(result, 987654321);
    }

    #[test]
    fn multiple_zeros_tests() {
        let result = Solution::reverse(1230000000);
        assert_eq!(result, 321);
    }

    #[test]
    fn overflow_test() {
        let result = Solution::reverse(1534236469);
        assert_eq!(result, 0);
    }
}
