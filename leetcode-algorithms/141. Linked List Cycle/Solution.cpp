// Given a linked list, determine if it has a cycle in it.
//
// Follow up:
// Can you solve it without using extra space?
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ((head == nullptr) || (head->next == nullptr)) return false;
        ListNode* speed1 = head;
        ListNode* speed2 = head;

        do {
            speed1 = speed1->next;
            speed2 = speed2->next->next;
            if (speed1 == speed2) return true;
        } while ((speed2 != nullptr) && (speed2->next != nullptr));

        return false;
    }
};
