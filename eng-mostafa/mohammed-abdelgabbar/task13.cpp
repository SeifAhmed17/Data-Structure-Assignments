void rotate(queue<int>& q, int k) {
    int n = q.size();
    k = k % n;

    for (int i = 0; i < k; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }
}