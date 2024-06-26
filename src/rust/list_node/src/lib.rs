#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    #[must_use]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    #[must_use]
    pub fn to_vec(&self) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();
        result.push(self.val);
        let mut temp = &self.next;
        while let Some(d) = temp {
            result.push(d.val);
            temp = &d.next;
        }

        result
    }

    #[must_use]
    pub fn from_vec(input: &[i32]) -> Option<Box<ListNode>> {
        let mut result = None;
        for i in 0..input.len() {
            result = Some(match result {
                None => Box::new(ListNode::new(input[input.len() - 1 - i])),
                Some(next) => Box::new(ListNode {
                    val: input[input.len() - 1 - i],
                    next: Some(next),
                }),
            });
        }

        result
    }

    #[must_use]
    pub fn len(&self) -> usize {
        let mut result: usize = 1;
        let mut temp = &self.next;
        while let Some(d) = temp {
            result += 1;
            temp = &d.next;
        }

        result
    }

    #[must_use]
    pub fn is_empty(&self) -> bool {
        false
    }
}
