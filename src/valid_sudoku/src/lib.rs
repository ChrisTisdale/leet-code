use std::collections::HashSet;

pub struct Solution {}

struct Offsets {
    row: usize,
    col: usize,
}

const OFFSET_UPDATES: &[Offsets] = &[
    Offsets { row: 0, col: 0 },
    Offsets { row: 0, col: 3 },
    Offsets { row: 0, col: 6 },
    Offsets { row: 3, col: 0 },
    Offsets { row: 3, col: 3 },
    Offsets { row: 3, col: 6 },
    Offsets { row: 6, col: 0 },
    Offsets { row: 6, col: 3 },
    Offsets { row: 6, col: 6 },
];

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row: HashSet<char> = HashSet::with_capacity(9);
        let mut col: HashSet<char> = HashSet::with_capacity(9);
        let mut grid: HashSet<char> = HashSet::with_capacity(9);

        for i in 0..9 {
            for j in 0..9 {
                let r = board[j][i];
                let c = board[i][j];
                let valid_row = r == '.' || row.insert(r);
                let valid_col = c == '.' || col.insert(c);

                let offset = &OFFSET_UPDATES[i];
                let grid_row: usize = match j {
                    z if z < 3 => offset.row,
                    z if z < 6 => 1 + offset.row,
                    _ => 2 + offset.row,
                };

                let grid_col: usize = j % 3 + offset.col;
                let g = board[grid_row][grid_col];
                let valid_grid = g == '.' || grid.insert(g);

                if !valid_row || !valid_col || !valid_grid {
                    return false;
                }
            }

            row.clear();
            col.clear();
            grid.clear();
        }

        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let input = vec![
            vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9'],
        ];

        let result = Solution::is_valid_sudoku(input);
        assert!(result);
    }

    #[test]
    fn example_2_test() {
        let input = vec![
            vec!['8', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9'],
        ];

        let result = Solution::is_valid_sudoku(input);
        assert!(!result);
    }

    #[test]
    fn invalid_row_only_test() {
        let input = vec![
            vec!['5', '3', '.', '4', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9'],
        ];

        let result = Solution::is_valid_sudoku(input);
        assert!(!result);
    }

    #[test]
    fn invalid_col_only_test() {
        let input = vec![
            vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '7', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9'],
        ];

        let result = Solution::is_valid_sudoku(input);
        assert!(!result);
    }

    #[test]
    fn invalid_grid_only_test() {
        let input = vec![
            vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '6', '.', '8', '.', '.', '7', '9'],
        ];

        let result = Solution::is_valid_sudoku(input);
        assert!(!result);
    }
}
