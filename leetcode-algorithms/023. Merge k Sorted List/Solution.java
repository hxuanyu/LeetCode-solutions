/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
    	PriorityQueue<ListNode> que = new PriorityQueue<>((l1, l2) -> l1.val - l2.val);

    	for (ListNode list : lists) {
    		if (list != null) que.add(list);
    	}

    	ListNode dummy = new ListNode(1);
    	ListNode cp = dummy;

    	while (!que.isEmpty()) {
    		ListNode top = que.poll();

    		dummy.next = top;
    		dummy = top;
    		if (top.next != null) que.add(top.next);
    	}

        return cp.next;
    }
}
