use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        nums.iter()
            .enumerate()
            .scan(
                VecDeque::new(),
                |q: &mut VecDeque<(i32, i32)>, (pos, &num)| {
                    while !q.is_empty() && q.back().unwrap().1 <= num {
                        q.pop_back();
                    }
                    q.push_back((pos as i32, num));
                    if q.front().unwrap().0 + k <= pos as i32 {
                        q.pop_front();
                    }
                    Some(q[0].1)
                },
            )
            .skip(k as usize - 1)
            .collect::<Vec<i32>>()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected_out = vec![3, 3, 5, 5, 6, 7];
        let result = Solution::max_sliding_window(vec![1, 3, -1, -2, 5, 3, 6, 7], 3);
        vectors_equivalent(&result, &expected_out);
    }

    #[test]
    fn example_2_test() {
        let expected_out = vec![1];
        let result = Solution::max_sliding_window(vec![1], 1);
        vectors_equivalent(&result, &expected_out);
    }

    #[test]
    fn array_length_test() {
        let expected_out = vec![7];
        let result = Solution::max_sliding_window(vec![1, 3, -1, -2, 5, 3, 6, 7], 8);
        vectors_equivalent(&result, &expected_out);
    }

    fn vectors_equivalent(left: &Vec<i32>, right: &Vec<i32>) {
        assert_eq!(left.len(), right.len());
        for i in 0..left.len() {
            assert_eq!(left[i], right[i]);
        }
    }
}
