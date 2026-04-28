#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    Node* get_nth(int n) {
        if (n <= 0) {
            return NULL;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL) {
            if (count == n) {
                return temp;
            }

            temp = temp->next;
            count++;
        }

        return NULL;
    }

    void printList() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(6);
    list.insertEnd(10);
    list.insertEnd(8);
    list.insertEnd(15);

    int n;
    cout << "Enter n: ";
    cin >> n;

    Node* result = list.get_nth(n);

    if (result == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << "Node value = " << result->data << endl;
    }

    return 0;
}