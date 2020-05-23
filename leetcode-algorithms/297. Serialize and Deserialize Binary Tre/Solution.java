class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "!#";
        else return String.valueOf(root.val) + "#" + serialize(root.left) + serialize(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        return deimpl(new StringBuilder(data));
    }

    public TreeNode deimpl(StringBuilder data) {
        if (data.length() < 2) {
            data.setLength(0);
            return null;
        }

        else if (data.substring(0, 2).equals("!#")) {
            data.delete(0, 2);
            return null;
        }

        int idx = data.indexOf("#");
        if (idx == -1) return null;

        int val = Integer.valueOf(data.substring(0, idx));
        data.delete(0, idx + 1);
        TreeNode node = new TreeNode(val);
        node.left = deimpl(data);
        node.right = deimpl(data);

        return node;
    }
}
