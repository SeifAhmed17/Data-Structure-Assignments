//Student Name : محمد شاذلي ابوالحسن محمد
//Student ID : 2024220141
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void print1(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;
}

Node* get_nth(Node* head, int n) {
    if (head == nullptr || n <= 0) return nullptr;
    Node* current = head;
    for (int i = 1; i < n && current != nullptr; i++) {
        current = current->next;
    }
    return current;
}

Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;
    
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
    
    if (list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << ",";
        current = current->next;
    }
    cout << endl;
}

Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    cout << "Task 1: Print list using for loop" << endl;
    Node* list1 = createList(new int[]{6, 10, 8, 15}, 4);
    print1(list1);
    
    cout << "\nTask 2: Get nth item" << endl;
    Node* nth = get_nth(list1, 4);
    if (nth != nullptr) {
        cout << "get_nth(4) = " << nth->data << endl;
    }
    
    cout << "\nTask 3: Merge two sorted lists" << endl;
    Node* l1 = createList(new int[]{1, 2, 4}, 3);    Node* l2 = createList(new int[]{1, 3, 4}, 3);
    cout << "list1: ";
    printList(l1);
    cout << "list2: ";
    printList(l2);
    Node* merged = mergeTwoLists(l1, l2);
    cout << "Merged: ";
    printList(merged);
    
    cout << "\nTask 4: Reverse linked list" << endl;
    Node* list4 = createList(new int[]{1, 2, 3, 4, 5}, 5);
    cout << "Original: ";
    printList(list4);
    Node* reversed = reverseList(list4);
    cout << "Reversed: ";
    printList(reversed);
    
    return 0;
}