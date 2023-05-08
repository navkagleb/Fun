// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut list1_current_node = &l1;
        let mut list2_current_node = &l2;
        
        let mut result_list = None;
        let mut result_current_node = &mut result_list;
        
        let mut carry = 0;

        while list1_current_node.is_some() || list2_current_node.is_some() || carry != 0 {
            let mut sum = carry;

            if let Some(node1) = &list1_current_node {
                sum += node1.val;
                list1_current_node = &node1.next;
            }

            if let Some(node2) = &list2_current_node {
                sum += node2.val;
                list2_current_node = &node2.next;
            }

            carry = sum / 10;
            sum %= 10;

            *result_current_node = Some(Box::new(ListNode::new(sum)));
            result_current_node = &mut result_current_node.as_mut().unwrap().next;
        }

        result_list
    }
}
