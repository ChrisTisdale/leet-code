use list_node::*;

pub struct Solution {}

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        Solution::add_two_numbers_internal(l1, l2, 0)
    }

    fn add_two_numbers_internal(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
        carry: i32,
    ) -> Option<Box<ListNode>> {
        if l1.is_none() && l2.is_none() && carry == 0 {
            return None;
        }

        if l1.is_none() && l2.is_none() {
            return Some(Box::new(ListNode::new(carry)));
        }

        if l1.is_none() {
            if carry == 0 {
                return l2;
            }

            if let Some(v2) = l2 {
                let result = v2.val + carry;
                return Some(Box::new(ListNode {
                    val: result % 10,
                    next: Solution::add_two_numbers_internal(l1, v2.next, result / 10),
                }));
            }

            return l2;
        }

        if l2.is_none() {
            if carry == 0 {
                return l1;
            }

            if let Some(v1) = l1 {
                let result = v1.val + carry;
                return Some(Box::new(ListNode {
                    val: result % 10,
                    next: Solution::add_two_numbers_internal(v1.next, l2, result / 10),
                }));
            }

            return None;
        }

        let temp1 = l1.unwrap();
        let temp2 = l2.unwrap();
        let result = temp2.val + temp1.val + carry;
        Some(Box::new(ListNode {
            val: result % 10,
            next: Solution::add_two_numbers_internal(temp1.next, temp2.next, result / 10),
        }))
    }
}

trait IntConversion {
    fn from_integer(input: i32) -> Box<ListNode>;
}

impl IntConversion for ListNode {
    fn from_integer(input: i32) -> Box<ListNode> {
        let mut result = Box::new(ListNode::new(input % 10));

        let local = input / 10;
        if local != 0 {
            result.next = Some(ListNode::from_integer(local));
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let l1 = ListNode::from_integer(342);
        let l2 = ListNode::from_integer(465);

        let result = Solution::add_two_numbers(Some(l1), Some(l2));
        assert!(result.is_some());
        let check = result.unwrap().to_vec();
        let expected = vec![7, 0, 8];
        assert_eq!(check.len(), expected.len());
        for i in 0..(expected.len()) {
            assert_eq!(check[i], expected[i]);
        }
    }

    #[test]
    fn example_2_test() {
        let l1 = ListNode::from_integer(0);
        let l2 = ListNode::from_integer(0);

        let result = Solution::add_two_numbers(Some(l1), Some(l2));
        assert!(result.is_some());
        let check = result.unwrap().to_vec();
        let expected = vec![0];
        assert_eq!(check.len(), expected.len());
        for i in 0..(expected.len()) {
            assert_eq!(check[i], expected[i]);
        }
    }

    #[test]
    fn example_3_test() {
        let l1 = ListNode::from_integer(9_999_999);
        let l2 = ListNode::from_integer(9999);

        let result = Solution::add_two_numbers(Some(l1), Some(l2));
        assert!(result.is_some());
        let check = result.unwrap().to_vec();
        let expected = vec![8, 9, 9, 9, 0, 0, 0, 1];
        assert_eq!(check.len(), expected.len());
        for i in 0..(expected.len()) {
            assert_eq!(check[i], expected[i]);
        }
    }

    #[test]
    fn example_4_test() {
        let l2 = ListNode::from_integer(9_999_999);
        let l1 = ListNode::from_integer(9999);

        let result = Solution::add_two_numbers(Some(l1), Some(l2));
        assert!(result.is_some());
        let check = result.unwrap().to_vec();
        let expected = vec![8, 9, 9, 9, 0, 0, 0, 1];
        assert_eq!(check.len(), expected.len());
        for i in 0..(expected.len()) {
            assert_eq!(check[i], expected[i]);
        }
    }

    #[test]
    fn example_5_test() {
        let l2 = ListNode::from_integer(9_999_999);
        let l1 = ListNode::from_integer(1);

        let result = Solution::add_two_numbers(Some(l1), Some(l2));
        assert!(result.is_some());
        let check = result.unwrap().to_vec();
        let expected = vec![0, 0, 0, 0, 0, 0, 0, 1];
        assert_eq!(check.len(), expected.len());
        for i in 0..(expected.len()) {
            assert_eq!(check[i], expected[i]);
        }
    }
}
