// Reverse a singly linked list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* reverseList1(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        ListNode* reversed = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reversed;
    }
};
