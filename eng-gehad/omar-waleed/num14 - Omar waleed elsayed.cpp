#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node() {
        data = 0;
        next = NULL;
    }
};

class queue {
private:
    node* front;
    node* rear;
    int counter;

public:
    queue() {
        front = NULL;
        rear = NULL;
        counter = 0;
    }

    bool isempty() {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int item) {
        node* newnode = new node();
        newnode->data = item;
        newnode->next = NULL;

        if (isempty()) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }

        counter++;
    }

    int dequeue() {
        if (isempty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        int value = front->data;
        node* delptr = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete delptr;
        counter--;

        return value;
    }

    void rotate(int k) {
        if (isempty()) {
            cout << "queue is empty" << endl;
            return;
        }

        k = k % counter;

        for (int i = 0; i < k; i++) {
            int value = dequeue();
            enqueue(value);
        }
    }

    void display() {
        node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    queue q;

    int n, item, k;

    cout << "enter size" << endl;
    cin >> n;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> item;
        q.enqueue(item);
    }

    cout << "enter k" << endl;
    cin >> k;

    cout << "before rotate: ";
    q.display();

    q.rotate(k);

    cout << "after rotate: ";
    q.display();

    return 0;
}