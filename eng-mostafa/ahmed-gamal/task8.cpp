#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* get_nth(Node* head, int n) {
    int count = 0;
    Node* cur = head;

    while (cur != NULL) {
        if (count == n)
            return cur;
        cur = cur->next;
        count++;
    }
    return NULL;
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, new Node{40, NULL}}}};
    Node* res = get_nth(head, 2);

    if (res)
        cout << res->data;
    else
        cout << "NULL";

    return 0;
}