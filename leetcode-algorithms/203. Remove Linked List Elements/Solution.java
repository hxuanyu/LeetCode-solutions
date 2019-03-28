/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) return head;


        ListNode dummy = new ListNode(1);
        ListNode cp = dummy;
        while (head != null) {
            while ((head != null) && (head.val == val))head = head.next;
            dummy.next = head;
            if (head == null) break;
            dummy = head;
            head = head.next;
        }
        return cp.next;
    }
}
