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
        newnode->next = top;
        top = newnode;
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
};

class queue {
private:
    node* front;
    node* rear;

public:
    queue() {
        front = NULL;
        rear = NULL;
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
        return value;
    }
};

bool isPalindrome(queue q, stack s) {
    while (!q.isempty()) {
        if (q.dequeue() != s.pop()) {
            return false;
        }
    }

    return true;
}

int main() {
    queue q;
    stack s;

    int n, item;

    cout << "enter size of queue" << endl;
    cin >> n;

    cout << "enter queue elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> item;
        q.enqueue(item);
        s.push(item);
    }

    if (isPalindrome(q, s)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}