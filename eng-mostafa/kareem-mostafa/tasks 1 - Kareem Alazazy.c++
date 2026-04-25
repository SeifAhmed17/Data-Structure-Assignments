#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void print1(Node* head) {
    for (Node* cur = head; cur != NULL; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;
}

Node* get_nth(Node* head, int n) {
    Node* cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cnt == n)
            return cur;
        cnt++;
        cur = cur->next;
    }
    return NULL;
}

Node* mergeLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;

    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev;
}