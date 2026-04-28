#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert_end(int val) {
        Node* newNode = new Node{val, NULL};

        if (!head) {
            head = newNode;
            return;
        }

        Node* cur = head;
        while (cur->next)
            cur = cur->next;

        cur->next = newNode;
    }

// Task 1
    void print() {
        for (Node* cur = head; cur != NULL; cur = cur->next)
            cout << cur->data << " ";
        cout << endl;
    }

// Task 2
    Node* get_nth(int n) {
        Node* cur = head;
        int count = 0;

        while (cur) {
            if (count == n)
                return cur;
            cur = cur->next;
            count++;
        }
        return NULL;
    }

// Task 4
    void reverse() {
        Node* prev = NULL;
        Node* cur = head;

        while (cur) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    Node* getHead() {
        return head;
    }
};

// Task 3
Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

void printList(Node* head) {
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;
}

int main() {
    LinkedList list1, list2;

    list1.insert_end(1);
    list1.insert_end(2);
    list1.insert_end(4);

    list2.insert_end(1);
    list2.insert_end(3);
    list2.insert_end(4);

    cout << "List1: ";
    list1.print();

    cout << "List2: ";
    list2.print();

    Node* merged = mergeLists(list1.getHead(), list2.getHead());

    cout << "Merged: ";
    printList(merged);

    return 0;
}