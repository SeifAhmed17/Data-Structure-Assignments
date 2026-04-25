#include<bits/stdc++.h>
using namespace std;

int  reverse_num(int& num) {
    stack<int>nums;
    int cnt = 0;
    while (num) {
        nums.push(num % 10);
        num /= 10;
        cnt++;
    }
    int i = 1;
    num = 0;
    while (cnt--) {
        num += (i * nums.top());
        nums.pop();
        i *= 10;

    }
    return num;

}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    cout<<reverse_num(n);
    return 0;
}