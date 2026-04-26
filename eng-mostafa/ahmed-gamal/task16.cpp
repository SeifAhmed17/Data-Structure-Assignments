#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int n) {
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {1,1,2,3,3,4};
    removeDuplicates(arr, 6);
    return 0;
}