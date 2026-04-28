#include<iostream>
using namespace std;

bool numberExists(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return true;
        }
    }

    return false;
}

int main() {
    int arr[100];
    int n, target;

    cout << "enter size" << endl;
    cin >> n;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter number to search" << endl;
    cin >> target;

    if (numberExists(arr, n, target)) {
        cout << "number exists" << endl;
    }
    else {
        cout << "number does not exist" << endl;
    }

    return 0;
}