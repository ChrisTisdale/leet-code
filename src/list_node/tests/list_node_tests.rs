#[cfg(test)]
mod tests {
    use list_node::*;

    #[test]
    fn from_array_test() {
        let list = vec![1, 2, 3, 4, 5];
        let result = ListNode::from_vec(&list);
        assert!(result.is_some());
        let mut count = 0;
        let mut temp = &result;
        while let Some(d) = temp {
            assert!(count < list.len());
            assert_eq!(d.val, list[count]);
            count += 1;
            temp = &d.next;
        }

        assert_eq!(count, list.len());
    }

    #[test]
    fn length_test() {
        let list = ListNode {
            val: 1,
            next: Some(Box::new(ListNode {
                val: 2,
                next: Some(Box::new(ListNode {
                    val: 3,
                    next: Some(Box::new(ListNode::new(4))),
                })),
            })),
        };

        assert_eq!(list.len(), 4);
    }

    #[test]
    fn to_vec_test() {
        let list = ListNode {
            val: 4,
            next: Some(Box::new(ListNode {
                val: 3,
                next: Some(Box::new(ListNode {
                    val: 2,
                    next: Some(Box::new(ListNode::new(1))),
                })),
            })),
        };

        let expected = vec![4, 3, 2, 1];
        let result = list.to_vec();
        assert_eq!(result.len(), expected.len());
        for i in 0..expected.len() {
            assert_eq!(result[i], expected[i]);
        }
    }
}
