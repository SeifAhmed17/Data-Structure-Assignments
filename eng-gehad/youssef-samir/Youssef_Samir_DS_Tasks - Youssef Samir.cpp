// TASK 1 - Get Nth Node in Linked List

/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* link;

    ListNode(int num) {
        val = num;
        link = nullptr;
    }
};

ListNode* fetchNodeAt(ListNode* head, int pos) {
    ListNode* ptr = head;
    int idx = 1;

    while (ptr != nullptr) {
        if (idx == pos) {
            return ptr;
        }
        ptr = ptr->link;
        idx++;
    }

    return nullptr;
}

int main() {
    ListNode* head = new ListNode(6);
    head->link = new ListNode(10);
    head->link->link = new ListNode(8);
    head->link->link->link = new ListNode(15);

    ListNode* found = fetchNodeAt(head, 4);

    if (found != nullptr) {
        cout << "Value: " << found->val << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 2 - Merge Two Sorted Linked Lists

/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* link;

    ListNode(int v) : val(v), link(nullptr) {}
};

ListNode* combineSortedLists(ListNode* a, ListNode* b) {
    ListNode placeholder(0);
    ListNode* end = &placeholder;

    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            end->link = a;
            a = a->link;
        } else {
            end->link = b;
            b = b->link;
        }
        end = end->link;
    }

    end->link = (a != nullptr) ? a : b;

    return placeholder.link;
}

ListNode* buildList(int nums[], int len) {
    if (len == 0) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head;

    for (int i = 1; i < len; i++) {
        ptr->link = new ListNode(nums[i]);
        ptr = ptr->link;
    }

    return head;
}

void showList(ListNode* head) {
    ListNode* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->val;
        if (ptr->link != nullptr) cout << " -> ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    int nums1[] = { 1, 2, 4 };
    ListNode* listA = buildList(nums1, 3);

    int nums2[] = { 1, 3, 4 };
    ListNode* listB = buildList(nums2, 3);

    cout << "List 1: ";
    showList(listA);

    cout << "List 2: ";
    showList(listB);

    ListNode* combined = combineSortedLists(listA, listB);

    cout << "Merged: ";
    showList(combined);

    ListNode* tmp;
    while (combined != nullptr) {
        tmp = combined;
        combined = combined->link;
        delete tmp;
    }

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 3 - Reverse a Linked List

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* nxt) : data(x), next(nxt) {}
};

class LinkedList {
public:
    Node* flipList(Node* head) {
        Node* before = nullptr;
        Node* curr = head;
        Node* ahead = nullptr;

        while (curr != nullptr) {
            ahead = curr->next;
            curr->next = before;
            before = curr;
            curr = ahead;
        }

        return before;
    }
};

void showList(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->next != nullptr) cout << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    showList(head);

    LinkedList ll;
    Node* flipped = ll.flipList(head);

    cout << "Reversed list: ";
    showList(flipped);

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 4 - Remove Node at Position

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* nxt) : data(x), next(nxt) {}
};

class LinkedList {
public:
    Node* deleteAt(Node* head, int pos) {
        if (head == nullptr) return nullptr;

        if (pos == 0) {
            Node* updated = head->next;
            delete head;
            return updated;
        }

        Node* ptr = head;
        for (int i = 0; i < pos - 1; i++) {
            if (ptr == nullptr || ptr->next == nullptr) {
                return head;
            }
            ptr = ptr->next;
        }

        if (ptr->next != nullptr) {
            Node* target = ptr->next;
            ptr->next = ptr->next->next;
            delete target;
        }

        return head;
    }
};

void showList(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->next != nullptr) cout << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);

    cout << "Original list: ";
    showList(head);

    LinkedList ll;
    int pos = 1;
    Node* modified = ll.deleteAt(head, pos);

    cout << "After removing node at position " << pos << ": ";
    showList(modified);

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 5 - Reverse a Number Using Stack

/*
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int flipNumber(int num) {
    if (num == 0) return 0;

    stack<int> digits;

    while (num > 0) {
        digits.push(num % 10);
        num = num / 10;
    }

    int result = 0;
    int place = 0;

    while (!digits.empty()) {
        result = result + digits.top() * pow(10, place);
        digits.pop();
        place++;
    }

    return result;
}

int main() {
    int a = 1234;
    int b = 56789;
    int c = 100;
    int d = 9;
    int e = 0;

    cout << "Original: " << a << " -> Reversed: " << flipNumber(a) << endl;
    cout << "Original: " << b << " -> Reversed: " << flipNumber(b) << endl;
    cout << "Original: " << c << " -> Reversed: " << flipNumber(c) << endl;
    cout << "Original: " << d << " -> Reversed: " << flipNumber(d) << endl;
    cout << "Original: " << e << " -> Reversed: " << flipNumber(e) << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 6 - Valid Brackets

/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBrackets(string str) {
    stack<char> st;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;

            char topChar = st.top();
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";
    string s6 = "((()))";
    string s7 = "";
    string s8 = "{[()]}";
    string s9 = "((";
    string s10 = "))";

    cout << "\"" << s1  << "\" -> " << (checkBrackets(s1)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s2  << "\" -> " << (checkBrackets(s2)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s3  << "\" -> " << (checkBrackets(s3)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s4  << "\" -> " << (checkBrackets(s4)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s5  << "\" -> " << (checkBrackets(s5)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s6  << "\" -> " << (checkBrackets(s6)  ? "Valid" : "Invalid") << endl;
    cout << "\"\" -> "              << (checkBrackets(s7)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s8  << "\" -> " << (checkBrackets(s8)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s9  << "\" -> " << (checkBrackets(s9)  ? "Valid" : "Invalid") << endl;
    cout << "\"" << s10 << "\" -> " << (checkBrackets(s10) ? "Valid" : "Invalid") << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 7 - Remove Stars from String

/*
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string eraseWithStars(string input) {
    stack<char> charStack;

    for (char ch : input) {
        if (ch == '*') {
            if (!charStack.empty()) {
                charStack.pop();
            }
        } else {
            charStack.push(ch);
        }
    }

    string output = "";
    while (!charStack.empty()) {
        output += charStack.top();
        charStack.pop();
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    string s1 = "leet**cod*e";
    string s2 = "ab**cd";
    string s3 = "a*b*c*d*e";
    string s4 = "erase*****";
    string s5 = "hello*world*";
    string s6 = "abc*def**ghi";

    cout << "Input: \"" << s1 << "\" -> Output: \"" << eraseWithStars(s1) << "\"" << endl;
    cout << "Input: \"" << s2 << "\" -> Output: \"" << eraseWithStars(s2) << "\"" << endl;
    cout << "Input: \"" << s3 << "\" -> Output: \"" << eraseWithStars(s3) << "\"" << endl;
    cout << "Input: \"" << s4 << "\" -> Output: \"" << eraseWithStars(s4) << "\"" << endl;
    cout << "Input: \"" << s5 << "\" -> Output: \"" << eraseWithStars(s5) << "\"" << endl;
    cout << "Input: \"" << s6 << "\" -> Output: \"" << eraseWithStars(s6) << "\"" << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 8 - Stack Implementation Using Array

/*
#include <iostream>
using namespace std;

class MyStack {
private:
    int* buffer;
    int maxSize;
    int topPos;

public:
    MyStack(int cap) {
        maxSize = cap;
        buffer = new int[maxSize];
        topPos = -1;
    }

    ~MyStack() {
        delete[] buffer;
    }

    void push(int num) {
        if (topPos == maxSize - 1) {
            cout << "Stack overflow! Cannot push " << num << endl;
            return;
        }
        buffer[++topPos] = num;
    }

    int pop() {
        if (empty()) {
            cout << "Stack underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        return buffer[topPos--];
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty! Nothing to peek" << endl;
            return -1;
        }
        return buffer[topPos];
    }

    bool empty() {
        return topPos == -1;
    }

    int count() {
        return topPos + 1;
    }

    void print() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topPos; i >= 0; i--) {
            cout << buffer[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyStack st(5);

    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    st.print();

    cout << "Top element (peek): " << st.top() << endl;
    cout << "Stack size: " << st.count() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    st.print();

    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Top element (peek): " << st.top() << endl;

    st.pop(); st.pop(); st.pop(); st.pop();

    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 9 - Remove Duplicates from Sorted Array

/*
#include <iostream>
using namespace std;

int dropDuplicates(int nums[], int len) {
    if (len == 0) return 0;

    int writeIdx = 0;

    for (int readIdx = 1; readIdx < len; readIdx++) {
        if (nums[readIdx] != nums[writeIdx]) {
            writeIdx++;
            nums[writeIdx] = nums[readIdx];
        }
    }

    return writeIdx + 1;
}

void printArray(int nums[], int len) {
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i < len - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    int arr1[] = { 1, 1, 2, 3, 3, 4 };
    int len1 = 6;

    cout << "Original array: ";
    printArray(arr1, len1);
    cout << endl;

    int newLen = dropDuplicates(arr1, len1);

    cout << "Array after removing duplicates: ";
    printArray(arr1, newLen);
    cout << endl;

    int arr2[] = { 1, 1, 1, 1, 1 };
    int len2 = 5;

    cout << "\nOriginal array: ";
    printArray(arr2, len2);
    cout << endl;

    newLen = dropDuplicates(arr2, len2);

    cout << "Array after removing duplicates: ";
    printArray(arr2, newLen);
    cout << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 10 - Queue Using Two Stacks

/*
#include <iostream>
#include <stack>
using namespace std;

class TwoStackQueue {
private:
    stack<int> pushStack;
    stack<int> popStack;

    void moveElements() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
    }

public:
    void enqueue(int num) {
        pushStack.push(num);
    }

    int dequeue() {
        if (empty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return -1;
        }
        moveElements();
        int frontVal = popStack.top();
        popStack.pop();
        return frontVal;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty! Nothing to peek" << endl;
            return -1;
        }
        moveElements();
        return popStack.top();
    }

    bool empty() {
        return pushStack.empty() && popStack.empty();
    }

    int length() {
        return pushStack.size() + popStack.size();
    }
};

int main() {
    TwoStackQueue q;

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue size: " << q.length() << endl;
    cout << "Front element (peek): " << q.front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element (peek): " << q.front() << endl;

    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue size: " << q.length() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 11 - Linear Search

/*
#include <iostream>
using namespace std;

bool searchValue(int nums[], int len, int key) {
    for (int i = 0; i < len; i++) {
        if (nums[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    int len = sizeof(nums) / sizeof(nums[0]);

    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int targets[] = { 3, 10, 7, 0, 5 };
    int totalTargets = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < totalTargets; i++) {
        int key = targets[i];
        bool found = searchValue(nums, len, key);
        cout << "Number " << key << " exists? " << (found ? "true" : "false") << endl;
    }

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 12 - Palindrome Queue

/*
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkPalindrome(queue<int> q) {
    stack<int> half;
    int total = q.size();

    for (int i = 0; i < total / 2; i++) {
        half.push(q.front());
        q.pop();
    }

    if (total % 2 != 0) {
        q.pop();
    }

    while (!q.empty()) {
        if (q.front() != half.top()) {
            return false;
        }
        q.pop();
        half.pop();
    }

    return true;
}

int main() {
    queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3); q1.push(2); q1.push(1);

    queue<int> q2;
    q2.push(1); q2.push(2); q2.push(3); q2.push(4); q2.push(5);

    cout << "Queue 1: ";
    cout << (checkPalindrome(q1) ? "Palindrome" : "Not Palindrome") << endl;

    cout << "Queue 2: ";
    cout << (checkPalindrome(q2) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////

// TASK 13 - Queue Rotation Using Linked List

#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int val) : data(val), next(nullptr) {}
};

class LinkedQueue {
private:
    QNode* head;
    QNode* tail;
    int len;

public:
    LinkedQueue() : head(nullptr), tail(nullptr), len(0) {}

    void enqueue(int val) {
        QNode* node = new QNode(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        len++;
    }

    void dequeue() {
        if (!head) return;
        QNode* tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
        len--;
    }

    int peekFront() {
        return head->data;
    }

    int length() {
        return len;
    }

    bool empty() {
        return len == 0;
    }

    void rotate(int steps) {
        if (empty() || steps <= 0) return;

        steps = steps % len;
        if (steps == 0) return;

        for (int i = 0; i < steps; i++) {
            int val = peekFront();
            dequeue();
            enqueue(val);
        }
    }

    void display() {
        QNode* ptr = head;
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    ~LinkedQueue() {
        while (!empty()) {
            dequeue();
        }
    }
};

int main() {
    LinkedQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Original queue: ";
    q.display();

    int steps = 2;
    q.rotate(steps);

    cout << "After rotating by " << steps << ": ";
    q.display();

    return 0;
}
