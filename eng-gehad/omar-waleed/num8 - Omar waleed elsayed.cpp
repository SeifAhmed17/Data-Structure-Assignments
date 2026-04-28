#include<iostream>
using namespace std;

class node {
public:
    char data;
    node* next;

    node() {
        data = '\0';
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

    void push(char item) {
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

    char pop() {
        if (isempty()) {
            return '\0';
        }

        char value;
        node* delptr = top;
        value = top->data;
        top = top->next;
        delete delptr;

        return value;
    }
};

void removeStars(char str[], char result[]) {
    stack s;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*') {
            if (!s.isempty()) {
                s.pop();
            }
        }
        else {
            s.push(str[i]);
        }
    }

    stack reverseStack;

    while (!s.isempty()) {
        reverseStack.push(s.pop());
    }

    int i = 0;

    while (!reverseStack.isempty()) {
        result[i] = reverseStack.pop();
        i++;
    }

    result[i] = '\0';
}

int main() {
    char str[100];
    char result[100];

    cout << "enter string" << endl;
    cin >> str;

    removeStars(str, result);

    cout << "output: " << result << endl;

    return 0;
}