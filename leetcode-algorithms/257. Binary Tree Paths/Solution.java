// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Input:
// 
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> rslt = new ArrayList<String>();
        if (root == null) return rslt;

        List<TreeNode> temp = new ArrayList<TreeNode>();
        visit(root, temp, rslt);
        return rslt;
    }

    public void visit(TreeNode root, List<TreeNode> temp, List<String> rslt) {
        if (root == null) return;
        else if ((root.left == null) && (root.right == null)) {
            StringBuilder sb = new StringBuilder();
            for (TreeNode node : temp) {
                sb.append(String.valueOf(node.val));
                sb.append("->");
            }
            sb.append(String.valueOf(root.val));
            rslt.add(sb.toString());
            return;
        }

        temp.add(root);
        if (root.left != null) visit(root.left, temp, rslt);
        if (root.right != null) visit(root.right, temp, rslt);
        temp.remove(temp.size() - 1);
    }
}
