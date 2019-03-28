class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        ListNode dummy = new ListNode(1);
        dummy.next = head;
        ListNode cp = dummy;
        ListNode p;
        while (head != null) {
            p = head;
            while ((p != null) && (p.val == head.val)) {
                p = p.next;
            }

            dummy.next = head;
            if (p == null) {
                head.next = null;
                break;
            }
            dummy = head;
            head = p;
        }

        return cp.next;
    }
}
