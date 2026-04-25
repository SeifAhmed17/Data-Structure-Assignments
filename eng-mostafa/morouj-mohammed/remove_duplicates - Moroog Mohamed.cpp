#include<bits/stdc++.h>
using namespace std;

void remove_duplicate(int arr[], int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || arr[i] != s.top())
            s.push(arr[i]);
    }
    int sz = s.size();
    for (int i = sz - 1; i >= 0; i--) {
        arr[i] = s.top();
        s.pop();
    }
    for (int i = sz; i < n; i++) {
        arr[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    remove_duplicate(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}