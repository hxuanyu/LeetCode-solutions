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
	public List<Integer> postorder(Node root) {
	     run(root);
	     return rslt;
	}

	private void run(Node root) {
		if (root == null) return;

		for (int i = 0; i < root.children.size(); i++) run(root.children.get(i));
		rslt.add(root.val);
	}

	List<Integer> rslt = new ArrayList<>();
}
