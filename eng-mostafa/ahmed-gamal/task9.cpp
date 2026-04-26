#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

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
    if (l2) tail->next = l2;

    return dummy.next;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* l1 = new Node{1, new Node{2, new Node{4, NULL}}};
    Node* l2 = new Node{1, new Node{3, new Node{4, NULL}}};

    Node* res = mergeLists(l1, l2);
    print(res);

    return 0;
}