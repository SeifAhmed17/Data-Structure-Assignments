#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node() {
        data = 0;
        next = NULL;
    }
};

class stack {
private:
    node* top;

public:
    stack() {
        top = NULL;
    }

    bool isempty() {
        if (top == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int item) {
        node* newnode = new node();
        newnode->data = item;

        if (isempty()) {
            top = newnode;
        }
        else {
            newnode->next = top;
            top = newnode;
        }
    }

    int pop() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }

        int value;
        node* delptr = top;
        value = top->data;
        top = top->next;
        delete delptr;

        return value;
    }
};

int reverse_num(int num) {
    stack s;

    if (num == 0) {
        return 0;
    }

    while (num > 0) {
        int digit = num % 10;
        s.push(digit);
        num = num / 10;
    }

    int reversed = 0;
    int place = 1;

    while (!s.isempty()) {
        reversed = reversed + s.pop() * place;
        place = place * 10;
    }

    return reversed;
}

int main() {
    int num;

    cout << "enter number" << endl;
    cin >> num;

    cout << "reversed number = " << reverse_num(num) << endl;

    return 0;
}