// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
//
// Input: 1->1->2
// Output: 1->2
// Example 2:
//
// Input: 1->1->2->3->3
// Output: 1->2->3
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode(0);
        ListNode* cp = p;
        ListNode* next;

        while (head) {
            p->next = head;
            p = head;
            next = head;
            while ((next != nullptr) && (next->val == head->val)) next = next->next;

            head = next;
        }
        p->next = nullptr;
        return cp->next;
    }
};
