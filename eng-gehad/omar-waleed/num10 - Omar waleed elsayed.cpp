#include<iostream>
using namespace std;

void removeDuplicates(int arr[], int n) {
    if (n == 0) {
        cout << "list is empty" << endl;
        return;
    }

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    cout << "list after removing duplicates: ";
    for (int i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[100];
    int n;

    cout << "enter size of list" << endl;
    cin >> n;

    cout << "enter sorted elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeDuplicates(arr, n);

    return 0;
}