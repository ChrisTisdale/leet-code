fn main() {
    Solution::search(vec![], -1);
}

struct Solution {}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        return match Solution::search_internal(&nums, target) {
            None => -1,
            Some(index) => index,
        };
    }

    fn search_internal(nums: &[i32], target: i32) -> Option<i32> {
        if nums.len() <= 0 {
            return None;
        }

        if nums.len() == 1 {
            return if nums[0] == target { Some(0) } else { None };
        }

        let start = (nums.len() - 1) / 2;
        if nums[start] == target {
            return Some(start as i32);
        }

        return if nums[start] > target {
            return Solution::search_internal(&nums[..start], target);
        } else {
            match Solution::search_internal(&nums[(start + 1)..], target) {
                None => None,
                Some(i) => Some(i + 1 + start as i32),
            }
        };
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 9);
        assert_eq!(result, 4);
    }

    #[test]
    fn example_2() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 2);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_3() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], -1);
        assert_eq!(result, 0);
    }

    #[test]
    fn example_4() {
        let result = Solution::search(vec![-1, 0, 3, 5, 9, 12], 12);
        assert_eq!(result, 5);
    }

    #[test]
    fn example_5() {
        let result = Solution::search(vec![2, 5], 0);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_6() {
        let result = Solution::search(vec![2], 2);
        assert_eq!(result, 0);
    }

    #[test]
    fn example_7() {
        let result = Solution::search(vec![], 0);
        assert_eq!(result, -1);
    }

    #[test]
    fn example_8() {
        let result = Solution::search(vec![5], 0);
        assert_eq!(result, -1);
    }
}
