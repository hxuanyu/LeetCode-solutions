// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        ListNode* cp = p;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }

        if (l1) p->next = l1;
        else if (l2) p->next = l2;

        return cp->next;
    }
};
