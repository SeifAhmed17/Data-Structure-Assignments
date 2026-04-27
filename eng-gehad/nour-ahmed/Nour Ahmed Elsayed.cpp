//			TASK 1

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* get_nth(Node* head, int n) {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (position == n) {
            return current;
        }
        current = current->next;
        position++;
    }

    return nullptr;
}

int main() {
    Node* head = new Node(6);
    head->next = new Node(10);
    head->next->next = new Node(8);
    head->next->next->next = new Node(15);

    Node* result = get_nth(head, 4);

    if (result != nullptr) {
        cout << "Value: " << result->data << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////

//                  TASK 2
/*

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

Node* mergeSortedLists(Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->value <= list2->value) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }

    return dummy.next;
}

Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = { 1, 2, 4 };
    Node* list1 = createList(arr1, 3);

    int arr2[] = { 1, 3, 4 };
    Node* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeSortedLists(list1, list2);

    cout << "Merged: ";
    printList(merged);

    Node* temp;
    while (merged != nullptr) {
        temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
*/

////////////////////////////////////////////////////////////

//                      TASK 3 

/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////
//              TASK 4
/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNode(ListNode* head, int x) {
        if (head == nullptr) return nullptr;

        if (x == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* current = head;
        for (int i = 0; i < x - 1; i++) {
            if (current == nullptr || current->next == nullptr) {
                return head;
            }
            current = current->next;
        }

        if (current->next != nullptr) {
            ListNode* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        }

        return head;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    int x = 1;
    ListNode* updatedHead = solution.removeNode(head, x);

    cout << "After removing node at position " << x << ": ";
    printList(updatedHead);

    return 0;
}

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//                  task 5
/*
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int reverse_num(int num) {
    if (num == 0) return 0;

    stack<int> s;

    while (num > 0) {
        s.push(num % 10);
        num = num / 10;
    }

    int reversed = 0;
    int multiplier = 0;

    while (!s.empty()) {
        reversed = reversed + s.top() * pow(10, multiplier);
        s.pop();
        multiplier++;
    }

    return reversed;
}

int main() {
    int num1 = 1234;
    int num2 = 56789;
    int num3 = 100;
    int num4 = 9;
    int num5 = 0;

    cout << "Original: " << num1 << " -> Reversed: " << reverse_num(num1) << endl;
    cout << "Original: " << num2 << " -> Reversed: " << reverse_num(num2) << endl;
    cout << "Original: " << num3 << " -> Reversed: " << reverse_num(num3) << endl;
    cout << "Original: " << num4 << " -> Reversed: " << reverse_num(num4) << endl;
    cout << "Original: " << num5 << " -> Reversed: " << reverse_num(num5) << endl;

    return 0;
}

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//                  task 6


/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char top = s.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                s.pop();
            }
            else {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";
    string test6 = "((()))";
    string test7 = "";
    string test8 = "{[()]}";
    string test9 = "((";
    string test10 = "))";

    cout << "\"" << test1 << "\" -> " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test2 << "\" -> " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test3 << "\" -> " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test4 << "\" -> " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test5 << "\" -> " << (isValid(test5) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test6 << "\" -> " << (isValid(test6) ? "Valid" : "Invalid") << endl;
    cout << "\"\" -> " << (isValid(test7) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test8 << "\" -> " << (isValid(test8) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test9 << "\" -> " << (isValid(test9) ? "Valid" : "Invalid") << endl;
    cout << "\"" << test10 << "\" -> " << (isValid(test10) ? "Valid" : "Invalid") << endl;

    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////       task 7
/*
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeStars(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '*') {
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
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

int main() {
    string test1 = "leet**cod*e";
    string test2 = "ab**cd";
    string test3 = "a*b*c*d*e";
    string test4 = "erase*****";
    string test5 = "hello*world*";
    string test6 = "abc*def**ghi";

    cout << "Input: \"" << test1 << "\" -> Output: \"" << removeStars(test1) << "\"" << endl;
    cout << "Input: \"" << test2 << "\" -> Output: \"" << removeStars(test2) << "\"" << endl;
    cout << "Input: \"" << test3 << "\" -> Output: \"" << removeStars(test3) << "\"" << endl;
    cout << "Input: \"" << test4 << "\" -> Output: \"" << removeStars(test4) << "\"" << endl;
    cout << "Input: \"" << test5 << "\" -> Output: \"" << removeStars(test5) << "\"" << endl;
    cout << "Input: \"" << test6 << "\" -> Output: \"" << removeStars(test6) << "\"" << endl;

    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////

//                          TASK 8
/*
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5);

    cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    stack.display();

    cout << "Top element (peek): " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    stack.display();

    cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    cout << "Top element (peek): " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//                  task 9

/*
#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int uniqueIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1;
}

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    int arr[] = { 1, 1, 2, 3, 3, 4 };
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);
    cout << endl;

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    printArray(arr, newSize);
    cout << endl;

    int arr2[] = { 1, 1, 1, 1, 1 };
    int n2 = 5;

    cout << "\nOriginal array: ";
    printArray(arr2, n2);
    cout << endl;

    newSize = removeDuplicates(arr2, n2);

    cout << "Array after removing duplicates: ";
    printArray(arr2, newSize);
    cout << endl;

    return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //              task 10

/*

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    void enqueue(int value) {
        inputStack.push(value);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return -1;
        }
        transferIfNeeded();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek" << endl;
            return -1;
        }
        transferIfNeeded();
        return outputStack.top();
    }

    bool isEmpty() {
        return inputStack.empty() && outputStack.empty();
    }

    int size() {
        return inputStack.size() + outputStack.size();
    }
};

int main() {
    QueueUsingStacks q;

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue size: " << q.size() << endl;
    cout << "Front element (peek): " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element (peek): " << q.peek() << endl;

    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue size: " << q.size() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//              task 11

/*
#include <iostream>
using namespace std;

bool numberExists(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int numbersToCheck[] = { 3, 10, 7, 0, 5 };
    int checkCount = sizeof(numbersToCheck) / sizeof(numbersToCheck[0]);

    for (int i = 0; i < checkCount; i++) {
        int num = numbersToCheck[i];
        bool exists = numberExists(arr, size, num);

        cout << "Number " << num << " exists? "
            << (exists ? "true" : "false") << endl;
    }

    return 0;
}

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//          task 12

/*
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<int> q) {
    stack<int> s;
    int size = q.size();

    for (int i = 0; i < size / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    if (size % 2 != 0) {
        q.pop();
    }

    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }
        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(2);
    q1.push(1);

    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.push(5);

    cout << "Queue 1: ";
    if (isPalindrome(q1)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    cout << "Queue 2: ";
    if (isPalindrome(q2)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//      task 13

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        size--;
    }

    int frontValue() {
        return front->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void rotate(int k) {
        if (isEmpty() || k <= 0) return;

        k = k % size;
        if (k == 0) return;

        for (int i = 0; i < k; i++) {
            int val = frontValue();
            pop();
            push(val);
        }
    }

    void display() {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original queue: ";
    q.display();

    int k = 2;
    q.rotate(k);

    cout << "After rotating by " << k << ": ";
    q.display();

    return 0;
}
*/