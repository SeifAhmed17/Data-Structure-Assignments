#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

class Stack {
private:
    Node* topnode;

public:
    Stack() {
        topnode = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topnode;
        topnode = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = topnode;
        topnode = topnode->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) return -1;
        return topnode->data;
    }

    bool isEmpty() {
        return topnode == NULL;
    }

    void display() {
        Node* temp = topnode;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Task 2
    Stack copyStack() {
        Stack tempStack, copy;
        Node* temp = topnode;
        while (temp != NULL) {
            tempStack.push(temp->data);
            temp = temp->next;
        }
        Node* temp2 = tempStack.topnode;
        while (temp2 != NULL) {
            copy.push(temp2->data);
            temp2 = temp2->next;
        }
        return copy;
    }

    // Task 3
    int getSize() {
        int count = 0;
        Node* temp = topnode;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

// task Get_nth item
Node* get_nth(Node* head, int n) {
    int count = 1;
    Node* current = head;
    while (current != NULL) {
        if (count == n) return current;
        count++;
        current = current->next;
    }
    return NULL;
}

// task Merge Two Sorted Lists
Node* mergeTwoLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->data <= list2->data) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

// task:Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Problem: remove the node at position x
Node* removeAtX(Node* head, int x) {
    if (!head) return NULL;
    if (x == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; curr != NULL && i < x - 1; i++) curr = curr->next;
    if (!curr || !curr->next) return head;
    Node* next = curr->next->next;
    delete curr->next;
    curr->next = next;
    return head;
}

// Problem: Reverse a number using stack
int reverse_num(int num) {
    stack<int> s;
    int temp = num;
    if (num == 0) return 0;
    while (temp > 0) {
        s.push(temp % 10);
        temp /= 10;
    }
    int reversed = 0;
    int place = 1;
    while (!s.empty()) {
        reversed += s.top() * place;
        s.pop();
        place *= 10;
    }
    return reversed;
}

// Problem : Valid Parentheses
bool isValid(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') s.push(c);
        else {
            if (s.empty()) return false;
            if (c == ')' && s.top() != '(') return false;
            if (c == '}' && s.top() != '{') return false;
            if (c == ']' && s.top() != '[') return false;
            s.pop();
        }
    }
    return s.empty();
}

// Task:Removing stars from a string
string removeStars(string s) {
    string result;
    for (char c : s) {
        if (c == '*') {
            if (!result.empty()) result.pop_back();
        } else result.push_back(c);
    }
    return result;
}

// Problem: remove all duplicate elements
vector<int> removeDuplicates(int arr[], int n) {
    vector<int> result;
    if (n == 0) return result;
    result.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) result.push_back(arr[i]);
    }
    return result;
}

// Problems1: Queue using 2 Stacks
class QueueUsingStacks {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};

// Problem 1: Check if a Number Exists
bool numberExists(Node* head, int val) {
    Node* curr = head;
    while (curr) {
        if (curr->data == val) return true;
        curr = curr->next;
    }
    return false;
}

// problem 2:Check Palindrome
bool isPalindrome(vector<int> q) {
    int n = q.size();
    for (int i = 0; i < n / 2; i++) {
        if (q[i] != q[n - i - 1]) return false;
    }
    return true;
}

// Task: Rotate the linked list by k positions
Node* rotateQueue(Node* head, int k, int size) {
    if (!head || k == 0 || k % size == 0) return head;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = head;
    k = k % size;
    for (int i = 0; i < k; i++) curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
}

int main() {
    return 0;
}