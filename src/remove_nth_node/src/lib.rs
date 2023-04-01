use list_node::*;

struct RemoveResult {
    data: Option<Box<ListNode>>,
    back: i32,
}

impl RemoveResult {
    fn new(data: Option<Box<ListNode>>, back: i32) -> RemoveResult {
        return RemoveResult { data, back };
    }
}

pub struct Solution {}

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let result = Solution::remove_nth_from_end_internal(&head, n);
        return result.data;
    }

    fn remove_nth_from_end_internal(head: &Option<Box<ListNode>>, n: i32) -> RemoveResult {
        return match head.clone() {
            None => RemoveResult::new(None, n - 1),
            Some(mut data) => {
                let result = Solution::remove_nth_from_end_internal(&data.next, n);
                if result.back == 0 {
                    return RemoveResult::new(result.data, -1);
                }

                data.next = result.data;
                return RemoveResult::new(Some(data), result.back - 1);
            }
        };
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1() {
        let expected = &vec![1, 2, 3, 5];
        let head = ListNode::from_vec(&vec![1, 2, 3, 4, 5]);
        let result = Solution::remove_nth_from_end(head, 2);
        assert!(result.is_some());
        let list = result.unwrap().to_vec();
        assert_eq!(list.len(), expected.len());
        for i in 0..expected.len() {
            assert_eq!(list[i], expected[i]);
        }
    }

    #[test]
    fn example_2() {
        let head = ListNode::from_vec(&vec![1]);
        let result = Solution::remove_nth_from_end(head, 1);
        assert!(result.is_none());
    }

    #[test]
    fn example_3() {
        let expected = &vec![1];
        let head = ListNode::from_vec(&vec![1, 2]);
        let result = Solution::remove_nth_from_end(head, 1);
        assert!(result.is_some());
        let list = result.unwrap().to_vec();
        assert_eq!(list.len(), expected.len());
        for i in 0..expected.len() {
            assert_eq!(list[i], expected[i]);
        }
    }
}
