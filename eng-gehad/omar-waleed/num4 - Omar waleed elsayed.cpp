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

    void deleteAtPosition(int x) {
        if (head == NULL) {
            cout << "list is empty" << endl;
            return;
        }

        if (x < 0) {
            cout << "invalid position" << endl;
            return;
        }

        if (x == 0) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* current = head;

        for (int i = 0; i < x - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL || current->next == NULL) {
            cout << "position not found" << endl;
            return;
        }

        node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};

int main() {
    linkedlist lst;
    int n, item, x;

    cout << "enter size of list" << endl;
    cin >> n;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> item;
        lst.insertlast(item);
    }

    cout << "original list: ";
    lst.display();

    cout << "enter position to delete" << endl;
    cin >> x;

    lst.deleteAtPosition(x);

    cout << "updated list: ";
    lst.display();

    return 0;
}