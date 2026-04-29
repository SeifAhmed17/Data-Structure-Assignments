// Q1:

Node* get_nth(int n) {
    int count = 1; 
    Node* current = head;
    while (current != NULL) {
        if (count == n) return current;
        current = current->next;
        count++;
    }
    return NULL;
}

// Q2:

Node* mergeTwoLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

// Q3:

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// Q4:

Node* removeAt(Node* head, int x) {
    if (head == NULL) return NULL;
    if (x == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* current = head;
    for (int i = 0; current != NULL && i < x - 1; i++) {
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        Node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
    }
    return head;
}

// Q5:

int reverse_num(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }
    int reversed = 0;
    int multiplier = 1;
    while (!s.empty()) {
        reversed += (s.top() * multiplier);
        s.pop();
        multiplier *= 10;
    }
    return reversed;
}

// Q6:

bool isValid(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            if (s.empty()) return false;
            if (c == ')' && s.top() != '(') return false;
            if (c == '}' && s.top() != '{') return false;
            if (c == ']' && s.top() != '[') return false;
            s.pop();
        }
    }
    return s.empty();
}

// Q7:

string removeStars(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '*') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}
// Q8:

struct Stack {
    static const int N = 100;
    int arr[N];
    int topIndex = -1;

    void push(int val) {
        if (topIndex < N - 1) arr[++topIndex] = val;
    }

    int pop() {
        return arr[topIndex--];
    }

    int peek() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

// Q9:

LinkedList<int> remove_duplicates(LinkedList<int> l) {
    int p = -2e9;
    LinkedList<int> ret;
    for (Node<int> *cur = l.head; cur != nullptr; cur = cur->nxt)
        if (cur->val != p) p = cur->val, ret.insert(p);
    return ret;
}

// Q10:

struct MyQueue {
    stack<int> s1, s2;

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

// Q11:
bool exists(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->val == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Q12:

bool isPalindrome(queue<int> q) {
    stack<int> s;
    queue<int> temp = q;
    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }
    while (!q.empty()) {
        if (q.front() != s.top()) return false;
        q.pop();
        s.pop();
    }
    return true;
}

// Q13:

void rotateQueue(Node* &head, int k, int size) {
    if (head == NULL || k <= 0 || k % size == 0) return;
    Node* tail = head;
    while (tail->next != NULL) tail = tail->next;
    tail->next = head;
    for (int i = 0; i < k; i++) {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
}

// Q14:


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top = NULL;

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!top) return 0;
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        return top ? top->data : 0;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int getPrecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string output = "";
    Stack s;

    for (char c : infix) {
        if (isdigit(c)) {
            output += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                output += (char)s.pop();
            }
            s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && getPrecedence(s.peek()) > getPrecedence(c)) {
                output += (char)s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        output += (char)s.pop();
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    
    return 0;
}
