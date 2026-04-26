#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<int> q) {
    stack<int> st;
    queue<int> temp = q;

    while (!temp.empty()) {
        st.push(temp.front());
        temp.pop();
    }

    while (!q.empty()) {
        if (q.front() != st.top())
            return false;

        q.pop();
        st.pop();
    }

    return true;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << isPalindrome(q);
    return 0;
}