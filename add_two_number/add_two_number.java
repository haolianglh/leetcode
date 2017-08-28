/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode head, node;
        int carry= 0;
        int sum;
        head = node = new ListNode(0);
        
        while(l1!= null ||l2 != null ||carry != 0)
        {
            sum = (l1 != null?l1.val:0)+ (l2 != null ?l2.val:0)+carry;
            carry = sum/10;
            sum %= 10;
            node = node.next = new ListNode(sum);
            l1 = l1 != null?l1.next:null;
            l2 = l2 != null?l2.next:null;
        }
        
        return head.next;
    }
}