#include<iostream>
using namespace std;

class stack {
private:
    int* arr;
    int top;
    int size;

public:
    stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    bool isempty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isfull() {
        if (top == size - 1) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int item) {
        if (isfull()) {
            cout << "stack is full" << endl;
        }
        else {
            top++;
            arr[top] = item;
        }
    }

    int pop() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        else {
            int value = arr[top];
            top--;
            return value;
        }
    }

    int peek() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    void display() {
        if (isempty()) {
            cout << "stack is empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, item;

    cout << "enter stack size" << endl;
    cin >> n;

    stack s(n);

    for (int i = 0; i < n; i++) {
        cout << "enter item to push" << endl;
        cin >> item;
        s.push(item);
        s.display();
    }

    cout << "top element is " << s.peek() << endl;

    cout << s.pop() << " deleted" << endl;
    s.display();

    if (s.isempty()) {
        cout << "stack is empty" << endl;
    }
    else {
        cout << "stack is not empty" << endl;
    }

    return 0;
}