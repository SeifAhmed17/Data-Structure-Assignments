#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* deleteAt(Node* head, int x) {
    if (x == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < x - 1; i++)
        cur = cur->next;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;

    return head;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{4, NULL}}};
    head = deleteAt(head, 1);
    print(head);
    return 0;
}