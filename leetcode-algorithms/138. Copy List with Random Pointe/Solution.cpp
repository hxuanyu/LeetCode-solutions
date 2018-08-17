// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (head == nullptr) return head;

        map<RandomListNode*, RandomListNode*> nodemap;

        RandomListNode* p = head;
        while (p) {
            RandomListNode* node = new RandomListNode(p->label);
            nodemap[p] = node;
            p = p->next;
        }

        p = head;
        while (p) {
            nodemap[p]->next = nodemap[p->next];
            nodemap[p]->random = (p->random == nullptr) ? nullptr : nodemap[p->random];
            p = p->next;
        }

        return nodemap[head];
    }
};
