#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL) return -1;

        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

class Queue
{
private:
    Stack s1, s2;

public:

    void enqueue(int value)
    {
        s1.push(value);
    }

    int dequeue() {

        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }

        return s2.pop();
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}