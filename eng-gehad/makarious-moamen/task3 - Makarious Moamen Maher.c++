#include <iostream>
#include <stack>
using namespace std;

class QueueTwoStacks {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int value) {
        s1.push(value);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueTwoStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl; // 1
    cout << q.dequeue() << endl; // 2

    q.enqueue(4);

    cout << q.dequeue() << endl; // 3
    cout << q.dequeue() << endl; // 4

    return 0;
}