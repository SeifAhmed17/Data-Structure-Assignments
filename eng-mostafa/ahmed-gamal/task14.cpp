#include <iostream>
#include <stack>
using namespace std;

string removeStars(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '*') {
            if (!st.empty())
                st.pop();
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    cout << removeStars("leet**cod*e");
    return 0;
}