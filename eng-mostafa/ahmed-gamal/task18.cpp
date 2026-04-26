#include <iostream>
#include <queue>
using namespace std;

void rotate(queue<int>& q, int k) {
    for (int i = 0; i < k; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    rotate(q, 2);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}