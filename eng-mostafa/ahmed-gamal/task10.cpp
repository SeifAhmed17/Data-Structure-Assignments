#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;

    while (cur) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, NULL}}};
    head = reverseList(head);
    print(head);
    return 0;
}