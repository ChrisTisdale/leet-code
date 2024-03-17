pub struct Solution {}

impl Solution {
    #[allow(clippy::ptr_arg)]
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let length = matrix.len();
        let out_loop_len = length / 2;
        for out in 0..out_loop_len {
            for i in out..(length - 1 - out) {
                let first = matrix[out][i];
                let right = matrix[i][length - (out + 1)];
                let bottom = matrix[length - (out + 1)][length - i - 1];
                let left = matrix[length - i - 1][out];
                matrix[i][length - (out + 1)] = first;
                matrix[length - (out + 1)][length - i - 1] = right;
                matrix[length - i - 1][out] = bottom;
                matrix[out][i] = left;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec![vec![7, 4, 1], vec![8, 5, 2], vec![9, 6, 3]];
        let mut input = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
        Solution::rotate(&mut input);
        vectors_equivalent(&input, &expected);
    }

    #[test]
    fn example_2_test() {
        let expected = vec![
            vec![15, 13, 2, 5],
            vec![14, 3, 4, 1],
            vec![12, 6, 8, 9],
            vec![16, 7, 10, 11],
        ];
        let mut input = vec![
            vec![5, 1, 9, 11],
            vec![2, 4, 8, 10],
            vec![13, 3, 6, 7],
            vec![15, 14, 12, 16],
        ];
        Solution::rotate(&mut input);
        vectors_equivalent(&input, &expected);
    }

    #[test]
    fn five_elements() {
        let expected = vec![
            vec![21, 16, 11, 6, 1],
            vec![22, 17, 12, 7, 2],
            vec![23, 18, 13, 8, 3],
            vec![24, 19, 14, 9, 4],
            vec![25, 20, 15, 10, 5],
        ];
        let mut input = vec![
            vec![1, 2, 3, 4, 5],
            vec![6, 7, 8, 9, 10],
            vec![11, 12, 13, 14, 15],
            vec![16, 17, 18, 19, 20],
            vec![21, 22, 23, 24, 25],
        ];
        Solution::rotate(&mut input);
        vectors_equivalent(&input, &expected);
    }

    #[test]
    fn size_elements() {
        let expected = vec![
            vec![31, 25, 19, 13, 7, 1],
            vec![32, 26, 20, 14, 8, 2],
            vec![33, 27, 21, 15, 9, 3],
            vec![34, 28, 22, 16, 10, 4],
            vec![35, 29, 23, 17, 11, 5],
            vec![36, 30, 24, 18, 12, 6],
        ];
        let mut input = vec![
            vec![1, 2, 3, 4, 5, 6],
            vec![7, 8, 9, 10, 11, 12],
            vec![13, 14, 15, 16, 17, 18],
            vec![19, 20, 21, 22, 23, 24],
            vec![25, 26, 27, 28, 29, 30],
            vec![31, 32, 33, 34, 35, 36],
        ];
        Solution::rotate(&mut input);
        vectors_equivalent(&input, &expected);
    }

    fn vectors_equivalent(left: &Vec<Vec<i32>>, right: &Vec<Vec<i32>>) {
        assert_eq!(left.len(), right.len());
        for i in 0..left.len() {
            for j in 0..left[i].len() {
                assert_eq!(left[i].len(), right[i].len());
                assert_eq!(left[i][j], right[i][j]);
            }
        }
    }
}
