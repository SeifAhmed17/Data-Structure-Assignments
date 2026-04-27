#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;
    int added_elements = 0;
public:
    bool isEmpty() { return added_elements == 0; }
    bool isFull() { return false; }
    int size() { return added_elements; }

    void enqueue(int value) {
        assert(!isFull());
        s1.push(value);
        added_elements++;
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
        added_elements--;
        return value;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}