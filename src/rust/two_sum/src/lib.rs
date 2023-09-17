use std::collections::HashMap;

pub struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::with_capacity(nums.len());
        for (i, v) in nums.iter().enumerate() {
            match map.get(&(target - v)) {
                Some(&index) => return vec![i as i32, index],
                None => map.insert(v, i as i32),
            };
        }

        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec![0, 1];
        let result = Solution::two_sum(vec![2, 7, 11, 15], 9);
        assert_eq!(result.len(), expected.len());
        for data in expected {
            assert!(result.contains(&data));
        }
    }

    #[test]
    fn example_2_test() {
        let expected = vec![1, 2];
        let result = Solution::two_sum(vec![3, 2, 4], 6);
        assert_eq!(result.len(), expected.len());
        for data in expected {
            assert!(result.contains(&data));
        }
    }
}
