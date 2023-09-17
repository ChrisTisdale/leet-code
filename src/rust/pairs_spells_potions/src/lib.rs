pub struct Solution {}

impl Solution {
    fn search(potions: &[i32], spell: i32, target: i64) -> i32 {
        if potions.is_empty() {
            return 0;
        }

        let size = potions.len() as i32;
        let mut min_index: i32 = 0;
        let mut max_index: i32 = size - 1;
        let mut found: i32 = size;
        while min_index <= max_index {
            let mid: i32 = min_index + (max_index - min_index) / 2;
            let res: i64 = spell as i64 * potions[mid as usize] as i64;
            if res >= target {
                max_index = mid - 1;
                found = mid;
            } else {
                min_index = mid + 1;
            }
        }

        size - found
    }

    #[allow(clippy::needless_range_loop)]
    pub fn successful_pairs(mut spells: Vec<i32>, mut potions: Vec<i32>, success: i64) -> Vec<i32> {
        potions.sort();
        for i in 0..spells.len() {
            spells[i] = Solution::search(&potions, spells[i], success);
        }

        spells
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::successful_pairs(vec![5, 1, 3], vec![1, 2, 3, 4, 5], 7);
        assert_eq!(result.len(), 3);
        assert_eq!(result[0], 4);
        assert_eq!(result[1], 0);
        assert_eq!(result[2], 3);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::successful_pairs(vec![3, 1, 2], vec![8, 5, 8], 16);
        assert_eq!(result.len(), 3);
        assert_eq!(result[0], 2);
        assert_eq!(result[1], 0);
        assert_eq!(result[2], 2);
    }

    #[test]
    fn i32_overflow_test() {
        let result = Solution::successful_pairs(
            vec![85_899_345, 42_949_672, 21_474_836],
            vec![52, 104, 205],
            4_294_967_296,
        );
        assert_eq!(result.len(), 3);
        assert_eq!(result[0], 3);
        assert_eq!(result[1], 2);
        assert_eq!(result[2], 1);
    }
}
