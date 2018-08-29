// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example, given a 3-ary tree:
// We should return its level order traversal:
//
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
//
//
// Note:
//
// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> rslt;
        if (root == nullptr) return rslt;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();
                level.push_back(top->val);

                for (auto c : top->children) {
                    if (c != nullptr) que.push(c);
                }
            }
            rslt.push_back(level);
        }

        return rslt;
    }
};
