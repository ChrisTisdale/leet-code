use list_node::*;

pub struct Solution {}

impl Solution {
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(v), None) | (None, Some(v)) => Some(v),
            (Some(mut l), Some(mut r)) => {
                if l.val > r.val {
                    r.next = Solution::merge_two_lists(Some(l), r.next);
                    Some(r)
                } else {
                    l.next = Solution::merge_two_lists(l.next, Some(r));
                    Some(l)
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let expected = vec![1, 1, 2, 3, 4, 4];
        let right = ListNode::from_vec(&vec![1, 3, 4]);
        let left = ListNode::from_vec(&vec![1, 2, 4]);
        let result = Solution::merge_two_lists(left, right);
        assert!(result.is_some());
        let data = result.unwrap().to_vec();
        assert_eq!(data.len(), expected.len());

        for i in 0..expected.len() {
            assert_eq!(data[i], expected[i]);
        }
    }

    #[test]
    fn example_2_test() {
        let right = ListNode::from_vec(&vec![]);
        let left = ListNode::from_vec(&vec![]);
        let result = Solution::merge_two_lists(left, right);
        assert!(result.is_none());
    }

    #[test]
    fn example_3_test() {
        let expected = vec![0];
        let right = ListNode::from_vec(&vec![]);
        let left = ListNode::from_vec(&vec![0]);
        let result = Solution::merge_two_lists(left, right);
        assert!(result.is_some());
        let data = result.unwrap().to_vec();
        assert_eq!(data.len(), expected.len());

        for i in 0..expected.len() {
            assert_eq!(data[i], expected[i]);
        }
    }
}
