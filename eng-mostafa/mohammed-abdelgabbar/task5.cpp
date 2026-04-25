int reverse_num(int num) {
    stack<int> s;

    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }

    int result = 0;
    while (!s.empty()) {
        result = result * 10 + s.top();
        s.pop();
    }

    return result;
}