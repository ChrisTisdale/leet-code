use list_node::*;

pub struct Solution {}

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut current = head;
        let mut previous = None;

        while let Some(mut v) = current {
            let next = v.next.take();
            v.next = previous;
            previous = Some(v);
            current = next;
        }

        previous
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec![5, 4, 3, 2, 1];
        let input = ListNode::from_vec(&vec![1, 2, 3, 4, 5]);
        let mut result = Solution::reverse_list(input);
        for check in expected {
            assert!(result.is_some());
            let value = result.unwrap();
            assert_eq!(value.val, check);
            result = value.next;
        }
    }

    #[test]
    fn example_2_test() {
        let expected = vec![2, 1];
        let input = ListNode::from_vec(&vec![1, 2]);
        let mut result = Solution::reverse_list(input);
        for check in expected {
            assert!(result.is_some());
            let value = result.unwrap();
            assert_eq!(value.val, check);
            result = value.next;
        }
    }

    #[test]
    fn example_3_test() {
        let input = ListNode::from_vec(&vec![]);
        let result = Solution::reverse_list(input);
        assert!(result.is_none());
    }
}
