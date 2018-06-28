// Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
// For example, the following two linked lists:
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// begin to intersect at node c1.
//
//
// Notes:
//
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// Credits:
// Special thanks to @stellari for adding this problem and creating all test cases.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0;
        ListNode* ca = headA;
        while (headA) {
            lena++;
            headA = headA->next;
        }

        int lenb = 0;
        ListNode* cb = headB;
        while (headB) {
            lenb++;
            headB = headB->next;
        }

        headA = ca;
        headB = cb;
        int diff = abs(lena - lenb);
        if (lena > lenb) {
            while (diff) {
                headA = headA->next;
                diff--;
            }
        } else {
            while (diff) {
                headB = headB->next;
                diff--;
            }
        }

        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};
