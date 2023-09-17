use list_node::ListNode;

pub struct Solution {}

impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if let Some(mut v) = head {
            let next = v.next.take();
            if let Some(mut n) = next {
                let next = n.next.take();
                v.next = Solution::swap_pairs(next);
                n.next = Some(v);
                return Some(n);
            }

            return Some(v);
        }

        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec![2, 1, 4, 3];
        let input = ListNode::from_vec(&vec![1, 2, 3, 4]);
        let mut result = Solution::swap_pairs(input);
        for check in expected {
            assert!(result.is_some());
            let value = result.unwrap();
            assert_eq!(value.val, check);
            result = value.next;
        }
    }

    #[test]
    fn example_2_test() {
        let input = ListNode::from_vec(&vec![]);
        let result = Solution::swap_pairs(input);
        assert!(result.is_none());
    }

    #[test]
    fn example_3_test() {
        let expected = vec![1];
        let input = ListNode::from_vec(&vec![1]);
        let mut result = Solution::swap_pairs(input);
        for check in expected {
            assert!(result.is_some());
            let value = result.unwrap();
            assert_eq!(value.val, check);
            result = value.next;
        }
    }

    #[test]
    fn long_test() {
        let expected = vec![2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 11];
        let input = ListNode::from_vec(&vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]);
        let mut result = Solution::swap_pairs(input);
        for check in expected {
            assert!(result.is_some());
            let value = result.unwrap();
            assert_eq!(value.val, check);
            result = value.next;
        }
    }
}
