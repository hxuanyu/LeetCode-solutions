/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
    	List<List<Integer>> rslt = new ArrayList<>();
    	if (root == null) return rslt;

        Queue<Node> que = new LinkedList<>();
        que.add(root);

        while (!que.isEmpty()) {
        	int size = que.size();
        	List<Integer> level = new ArrayList<>();
        	for (int i = 0; i < size; i++) {
        		Node top = que.poll();
        		level.add(top.val);

        		for (Node child : top.children) {
        			if (child != null) que.add(child);
        		}
        	}
        	rslt.add(level);
        }

        return rslt;
    }
}
