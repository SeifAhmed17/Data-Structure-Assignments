#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;
    int size;
    int capacity;

public:
    QueueUsingStacks(int cap) {
        capacity = cap;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        assert(!isFull());

        
        s1.push(value);

        size++;
    }

    int dequeue() {
        assert(!isEmpty());

        
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int value = s2.top();
        s2.pop();

        size--;

        return value;
    }
};

int main() {
    QueueUsingStacks q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 

    q.enqueue(40);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 

    return 0;
}