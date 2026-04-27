#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//TASK 1
void print1(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;
}

//TASK 2
Node* get_nth(Node* head, int n) {
    int count = 1;
    Node* cur = head;

    while (cur != nullptr) {
        if (count == n)
            return cur;
        count++;
        cur = cur->next;
    }
    return nullptr;
}

//TASK 3
Node* mergeTwoLists(Node* list1, Node* list2) {
    Node temp; 
    Node* tail = &temp;
    temp.next = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) 
        tail->next = list1;
    else 
        tail->next = list2;

    return temp.next;
}

//TASK 4
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur  = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next      = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = next;
    }
    return prev;
}

int main() {

    //Task 1
    Node* n1 = new Node(); n1->data = 6;
    Node* n2 = new Node(); n2->data = 10;
    Node* n3 = new Node(); n3->data = 8;
    Node* n4 = new Node(); n4->data = 15;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    cout << "Task 1 - print1 using for loop:" << endl;
    print1(n1);

    //Task 2
    cout << "\nTask 2 - get_nth(4):" << endl;
    Node* found = get_nth(n1, 4);
    if (found != nullptr)
        cout << "Node value = " << found->data << endl;
    else
        cout << "Not found" << endl;

    //Task 3
    Node* a1 = new Node(); a1->data = 1;
    Node* a2 = new Node(); a2->data = 2;
    Node* a3 = new Node(); a3->data = 4;
    a1->next = a2; a2->next = a3; a3->next = nullptr;

    Node* b1 = new Node(); b1->data = 1;
    Node* b2 = new Node(); b2->data = 3;
    Node* b3 = new Node(); b3->data = 4;
    b1->next = b2; b2->next = b3; b3->next = nullptr;

    cout << "\nTask 3 - Merge two sorted lists:" << endl;
    Node* merged = mergeTwoLists(a1, b1);
    print1(merged);

    //Task 4
    Node* r1 = new Node(); r1->data = 1;
    Node* r2 = new Node(); r2->data = 2;
    Node* r3 = new Node(); r3->data = 3;
    Node* r4 = new Node(); r4->data = 4;
    Node* r5 = new Node(); r5->data = 5;
    r1->next = r2; r2->next = r3;
    r3->next = r4; r4->next = r5; r5->next = nullptr;

    cout << "\nTask 4 - Reverse linked list:" << endl;
    Node* rev = reverseList(r1);
    print1(rev);

    return 0;
}