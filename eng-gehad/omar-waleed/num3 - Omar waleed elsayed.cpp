#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linkedlist {
public:
    node* head;

    linkedlist() {
        head = NULL;
    }

    bool isempty() {
        if (head == NULL)
            return true;
        else
            return false;
    }

    void insertlast(int newitem) {
        node* newnode = new node;
        newnode->data = newitem;
        newnode->next = NULL;

        if (isempty()) {
            head = newnode;
        }
        else {
            node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    void display() {
        node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reverseList() {
        node* prev = NULL;
        node* current = head;
        node* nextnode = NULL;

        while (current != NULL) {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }

        head = prev;
    }
};

int main() {
    linkedlist lst;
    int n, item;

    cout << "enter size of list" << endl;
    cin >> n;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> item;
        lst.insertlast(item);
    }

    cout << "original list: ";
    lst.display();

    lst.reverseList();

    cout << "reversed list: ";
    lst.display();

    return 0;
}