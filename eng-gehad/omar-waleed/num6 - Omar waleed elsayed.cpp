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

    char peek() {
        if (isempty()) {
            return '\0';
        }

        return top->data;
    }
};

bool isValid(char str[]) {
    stack s;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isempty()) {
                return false;
            }

            char open = s.pop();

            if (ch == ')' && open != '(') {
                return false;
            }

            if (ch == ']' && open != '[') {
                return false;
            }

            if (ch == '}' && open != '{') {
                return false;
            }
        }
    }

    if (s.isempty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char str[100];

    cout << "enter parentheses string" << endl;
    cin >> str;

    if (isValid(str)) {
        cout << "valid" << endl;
    }
    else {
        cout << "invalid" << endl;
    }

    return 0;
}