#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long sl;
int pre(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 0;
}
void in_pre(string& s) {
    string res = "";
    stack<char> op;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (std::isdigit(s[i]) || std::isalpha(s[i])) res = s[i] + res;
        else {
            if (op.empty() || (!op.empty() && (s[i] == ')' || pre(op.top()) < pre(s[i])))) op.push(s[i]);
            else if (!op.empty() && pre(op.top()) >= pre(s[i])) {
                if (s[i] == '(') {
                    while (!op.empty() && op.top() != ')' && pre(op.top()) >= pre(s[i])) {
                        res = op.top() + res;
                        op.pop();
                    }
                    op.pop();
                }
                else {
                    while (!op.empty() && (pre(s[i]) <= pre(op.top()))) {
                        res = op.top() + res;
                        op.pop();
                    }
                    op.push(s[i]);
                }
            }
        }
    }
    while (!op.empty()) {
        res = op.top() + res;
        op.pop();
    }
    s = res;
}
int ev_pre(string s) {
    stack<double>nums;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (std::isdigit(s[i])) nums.push(s[i] - '0');
        else {
            double result = nums.top();
            nums.pop();
            if (s[i] == '+') result += nums.top();
            else if (s[i] == '-') result -= nums.top();
            else if (s[i] == '/') result /= nums.top();
            else result *= nums.top();
            nums.pop();
            nums.push(result);
        }
    }
    return nums.top();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; //  3+(8/2)/4
    in_pre(s);
    cout << "prefix: " << s << endl;  //    +3//824
    cout << "result: " << ev_pre(s) << endl; // 4
    return 0;
}
