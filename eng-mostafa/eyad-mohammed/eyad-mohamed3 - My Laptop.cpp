#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class MyStack {
private:
    Node* head = nullptr;
public:
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }

    ~MyStack() {
        while (!empty()) pop();
    }
};

class StackQueue {
private:
    MyStack inbox;
    MyStack outbox;

    void shiftStacks() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    void enqueue(int value) {
        inbox.push(value);
    }

    void dequeue() {
        shiftStacks();
        if (!outbox.empty()) {
            outbox.pop();
        }
    }

    int peek() {
        shiftStacks();
        return outbox.top();
    }

    bool isEmpty() {
        return inbox.empty() && outbox.empty();
    }
};

int main() {
    StackQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl;

    return 0;
}