/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {

        Map<Node, Node> vmap  = new HashMap<>();
        Node dummy = new Node(1, null, null);
        Node dp = dummy;
        Node cp = head;

        while (cp != null) {
            Node local = new Node(cp.val, null, null);
            dummy.next = local;
            dummy = local;
            vmap.put(cp, local);
            cp = cp.next;

        }

        cp = head;
        while (cp != null) {
            vmap.get(cp).random = (cp.random == null) ? null : vmap.get(cp.random);
            cp = cp.next;
        }

        return dp.next;
    }
}
