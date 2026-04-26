#include <iostream>
#include <stack>
using namespace std;

int reverse_num(int num) {
    stack<int> st;

    while (num > 0) {
        st.push(num % 10);
        num /= 10;
    }

    int result = 0;

    while (!st.empty()) {
        result = result * 10 + st.top();
        st.pop();
    }

    return result;
}

int main() {
    cout << reverse_num(1234);
    return 0;
}