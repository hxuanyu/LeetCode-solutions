class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int carrage = 0;
        ListNode p = new ListNode(0);
        ListNode a = p;
        while ((l1 != null) || (l2 != null)) {
            sum = carrage;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            p.next = new ListNode(sum % 10);
            p = p.next;
            carrage = sum / 10;
        }

        if (carrage == 1) {
            p.next = new ListNode(1);
        }

        return a.next;
    }
}
