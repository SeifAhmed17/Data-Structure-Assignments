bool isPalindrome(queue<int> q) {
    stack<int> s;
    queue<int> temp = q;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!temp.empty()) {
        if (temp.front() != s.top())
            return false;
        temp.pop();
        s.pop();
    }
    return true;
}