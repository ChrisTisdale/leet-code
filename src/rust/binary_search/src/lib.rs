pub struct Solution {}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        Solution::search_internal(&nums, target).unwrap_or(-1)
    }

    fn search_internal(nums: &[i32], target: i32) -> Option<i32> {
        if nums.is_empty() {
            return None;
        }

        if nums.len() == 1 {
            return if nums[0] == target { Some(0) } else { None };
        }

        let start = (nums.len() - 1) / 2;
        if nums[start] == target {
            return Some(start as i32);
        }

        if nums[start] > target {
            Solution::search_internal(&nums[..start], target)
        } else {
            Solution::search_internal(&nums[(start + 1)..], target).map(|i| i + 1 + start as i32)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 9);
        assert_eq!(result, 4);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 2);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_3_test() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], -1);
        assert_eq!(result, 0);
    }

    #[test]
    fn example_4_test() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 12);
        assert_eq!(result, 5);
    }

    #[test]
    fn example_5_test() {
        let result = Solution::search(vec![2, 5], 0);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_6_test() {
        let result = Solution::search(vec![2], 2);
        assert_eq!(result, 0);
    }

    #[test]
    fn example_7_test() {
        let result = Solution::search(vec![], 0);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_8_test() {
        let result = Solution::search(vec![5], 0);
        assert_eq!(result, -1);
    }
}
