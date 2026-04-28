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

    int count() {
        int counter = 0;
        node* temp = head;

        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    bool isfound(int key) {
        bool found = false;
        node* temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                found = true;
            }

            temp = temp->next;
        }

        return found;
    }

    void mergeTwoSortedLists(linkedlist list1, linkedlist list2) {
        node* p1 = list1.head;
        node* p2 = list2.head;

        head = NULL;
        node* tail = NULL;

        while (p1 != NULL && p2 != NULL) {
            node* selected;

            if (p1->data <= p2->data) {
                selected = p1;
                p1 = p1->next;
            }
            else {
                selected = p2;
                p2 = p2->next;
            }

            selected->next = NULL;

            if (head == NULL) {
                head = selected;
                tail = selected;
            }
            else {
                tail->next = selected;
                tail = selected;
            }
        }

        while (p1 != NULL) {
            node* selected = p1;
            p1 = p1->next;
            selected->next = NULL;

            if (head == NULL) {
                head = selected;
                tail = selected;
            }
            else {
                tail->next = selected;
                tail = selected;
            }
        }

        while (p2 != NULL) {
            node* selected = p2;
            p2 = p2->next;
            selected->next = NULL;

            if (head == NULL) {
                head = selected;
                tail = selected;
            }
            else {
                tail->next = selected;
                tail = selected;
            }
        }
    }
};

int main() {
    linkedlist list1;
    linkedlist list2;
    linkedlist merged;

    int n1, n2, item;

    cout << "enter size of list1" << endl;
    cin >> n1;

    cout << "enter elements of list1" << endl;
    for (int i = 0; i < n1; i++) {
        cin >> item;
        list1.insertlast(item);
    }

    cout << "enter size of list2" << endl;
    cin >> n2;

    cout << "enter elements of list2" << endl;
    for (int i = 0; i < n2; i++) {
        cin >> item;
        list2.insertlast(item);
    }

    cout << "list1: ";
    list1.display();

    cout << "list2: ";
    list2.display();

    merged.mergeTwoSortedLists(list1, list2);

    cout << "merged list: ";
    merged.display();

    return 0;
}