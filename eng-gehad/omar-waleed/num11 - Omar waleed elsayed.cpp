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

class stack {
private:
    node* top;

public:
    stack() {
        top = NULL;
    }

    bool isempty() {
        if (top == NULL)
            return true;
        else
            return false;
    }

    void push(int item) {
        node* newnode = new node();
        newnode->data = item;

        if (isempty()) {
            top = newnode;
        }
        else {
            newnode->next = top;
            top = newnode;
        }
    }

    int pop() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }

        int value = top->data;
        node* delptr = top;
        top = top->next;
        delete delptr;

        return value;
    }

    int peek() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }

        return top->data;
    }
};

class queue {
private:
    stack s1;
    stack s2;

public:
    bool isempty() {
        if (s1.isempty() && s2.isempty())
            return true;
        else
            return false;
    }

    void enqueue(int item) {
        s1.push(item);   // O(1)
    }

    int dequeue() {
        if (s2.isempty()) {
            while (!s1.isempty()) {
                s2.push(s1.pop());
            }
        }

        if (s2.isempty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        return s2.pop();
    }

    int front() {
        if (s2.isempty()) {
            while (!s1.isempty()) {
                s2.push(s1.pop());
            }
        }

        if (s2.isempty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        return s2.peek();
    }
};

int main() {
    queue q;
    int n, item;

    cout << "enter number of items" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "enter item to enqueue" << endl;
        cin >> item;
        q.enqueue(item);
    }

    cout << "front item = " << q.front() << endl;

    cout << q.dequeue() << " deleted" << endl;

    if (!q.isempty()) {
        cout << "front item = " << q.front() << endl;
    }
    else {
        cout << "queue is empty" << endl;
    }

    return 0;
}