//
// Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
//
// Implement these functions in your linked list class:
//
// get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
// addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// addAtTail(val) : Append a node of value val to the last element of the linked list.
// addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
// deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
// Example:
//
// MyLinkedList linkedList = new MyLinkedList();
// linkedList.addAtHead(1);
// linkedList.addAtTail(3);
// linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
// linkedList.get(1);            // returns 2
// linkedList.deleteAtIndex(1);  // now the linked list is 1->3
// linkedList.get(1);            // returns 3
// Note:
//
// All values will be in the range of [1, 1000].
// The number of operations will be in the range of [1, 1000].
// Please do not use the built-in LinkedList library.
struct node {
    node(int val_) {
        val = val_;
        next = nullptr;
    }
    int val;
    node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = head;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int v = 0;
        node* p = getnode(index);
        if (p == nullptr) {
            v = -1;
        } else {
            v = p->val;
        }
        return v;

    }

    node* getnode(int index) {
        if ((index >= size) || (index < 0)) return nullptr; // 0 based

        node* p = head;
        while (index) {
            p = p->next;
            index--;
        };

        return p;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* p = new node(val);
        p->next = head;
        head = p;

        if (tail == nullptr) tail = head;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* p = new node(val);
        if (tail == nullptr) {
            tail = p;
            head = tail;
        } else {
            tail->next = p;
            tail = p;
        }
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if ((index <= size) && (index >= 0)) {
            if (index == size) return addAtTail(val);
            else if (index == 0) return addAtHead(val);
            else {
                node* p = getnode(index - 1);
                node* newnode = new node(val);
                newnode->next = p->next;
                p->next = newnode;
            }
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if ((index < size) && (index >= 0)) {
            if (index == size - 1) {
                node* p = getnode(size - 2);
                p->next = nullptr;
                tail = p;
            } else {
                node* p = getnode(index - 1);
                p->next = p->next->next;
            }
            size--;
        }
    }

    void print_() {
        node* p = head;
        cout << "        ";
        while (p) {
            cout << p->val << "->";
            p = p->next;
        }

        cout << endl << "        size = " << size << endl;
    }
    node* head;
    node* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
