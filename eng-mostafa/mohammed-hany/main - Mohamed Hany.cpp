#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 99) {
            cout << "Stack is full"<<endl;;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty"<<endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue is full"<<endl;
        }
        else{
        arr[++rear] = x;}
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty"<<endl;
            
        }
        else{
            front++;
        }
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.peek() << endl; // 20
    s.pop();
    cout << s.peek() << endl; // 10

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.peek() << endl; // 1
    q.dequeue();
    cout << q.peek() << endl; // 2

    return 0;
}