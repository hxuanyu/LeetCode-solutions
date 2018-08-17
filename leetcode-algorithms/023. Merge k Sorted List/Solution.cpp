// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;

        for (auto list : lists) {
            if (list != nullptr) que.push(list);
        }

        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            ListNode* newnode = new ListNode(top->val);
            head->next = newnode;
            head = newnode;
            if (top->next != nullptr) que.push(top->next);
        }

        return p->next;
    }
};
