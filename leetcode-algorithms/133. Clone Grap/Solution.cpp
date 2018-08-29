// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
// OJ's undirected graph serialization:
// Nodes are labeled uniquely.
//
// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
// Visually, the graph looks like the following:
//
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/
class Solution {
public:
    UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;

        queue<UndirectedGraphNode*> que;
        que.push(node);
        map<UndirectedGraphNode*, UndirectedGraphNode*> vmap;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();

                if (vmap.count(top) == 0) {
                    UndirectedGraphNode* no = new UndirectedGraphNode(top->label);
                    vmap[top] = no;
                }

                for (auto c : top->neighbors) {
                    if (vmap.count(c) == 0) {
                        UndirectedGraphNode* no = new UndirectedGraphNode(c->label);
                        vmap[c] = no;
                        que.push(c);
                    }
                    vmap[top]->neighbors.push_back(vmap[c]);
                }
            }
        }
        return vmap[node];
    }
};
