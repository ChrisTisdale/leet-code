pub struct Solution {}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = Vec::with_capacity(s.len());
        for c in s.chars() {
            let result = match c {
                '{' | '(' | '[' => {
                    stack.push(c);
                    true
                }
                ')' => Solution::check_stack(&mut stack, '('),
                '}' => Solution::check_stack(&mut stack, '{'),
                ']' => Solution::check_stack(&mut stack, '['),
                _ => false,
            };
            if !result {
                return false;
            }
        }

        stack.is_empty()
    }

    fn check_stack(stack: &mut Vec<char>, expect: char) -> bool {
        match stack.pop() {
            Some(p) => p == expect,
            None => false,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::is_valid(String::from("()"));
        assert!(result);
    }

    #[test]
    fn example_2_test() {
        let result = Solution::is_valid(String::from("()[]{}"));
        assert!(result);
    }

    #[test]
    fn example_3_test() {
        let result = Solution::is_valid(String::from("(]"));
        assert!(!result);
    }
}
