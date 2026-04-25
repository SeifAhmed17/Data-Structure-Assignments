#include<iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() 
    {
        if (s2.empty()) 
        {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) 
        {
            return -1; // queue is empty
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }
};

int main() 
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 

    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl;

    cout << q.dequeue() << endl;
}