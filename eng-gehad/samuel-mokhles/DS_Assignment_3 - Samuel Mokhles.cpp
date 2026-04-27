#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    int val = top->data;
    top = top->next;
    return val;
}

int peek() {
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

//PRINT LIST

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//TASK 1: GET NTH NODE

Node* get_nth(Node* head, int n) {
    Node* cur = head;
    int count = 1;

    while (cur != nullptr) {
        if (count == n)
            return cur;
        count++;
        cur = cur->next;
    }
    return nullptr;
}

//TASK 2: MERGE TWO SORTED LISTS

Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->data <= list2->data) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

//TASK 3: REVERSE LINKED LIST

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur  = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next      = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = next;
    }
    return prev;
}

//TASK 4: REMOVE NODE AT POSITION X

Node* removeAt(Node* head, int x) {
    if (x == 0)
        return head->next;

    Node* cur = head;
    int count = 0;

    while (cur != nullptr) {
        if (count == x - 1) {
            cur->next = cur->next->next;
            break;
        }
        count++;
        cur = cur->next;
    }
    return head;
}

//TASK 5: REVERSE NUMBER USING STACK

int reverse_num(int num) {
    while (num > 0) {
        push(num % 10);
        num /= 10;
    }

    int result = 0;
    int place  = 1;

    while (!isEmpty()) {
        result += pop() * place;
        place  *= 10;
    }
    return result;
}

//TASK 6: VALID PARENTHESES

bool isValid(string str) {
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
            if (isEmpty()) return false;
            int t = pop();
            if (c == ')' && t != '(') return false;
            if (c == '}' && t != '{') return false;
            if (c == ']' && t != '[') return false;
        }
    }
    return isEmpty();
}

// TASK 7: REMOVE STARS

string removeStars(string s) {
    string result = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            result = result.substr(0, result.size() - 1);
        } else {
            result += s[i];
        }
    }
    return result;
}

// TASK 8: STACK USING ARRAY

int stackArr[100];
int topArr = -1;

void pushArr(int val) { stackArr[++topArr] = val; }
int  popArr()         { return stackArr[topArr--]; }
int  peekArr()        { return stackArr[topArr];   }
bool isEmptyArr()     { return topArr == -1;        }

//TASK 9: REMOVE DUPLICATES

Node* removeDuplicates(Node* head) {
    Node* cur = head;

    while (cur != nullptr && cur->next != nullptr) {
        if (cur->data == cur->next->data)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}

//TASK 10: QUEUE USING 2 STACKS

Node* stack1 = nullptr;
Node* stack2 = nullptr;

void s1push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = stack1;
    stack1 = newNode;
}

int s1pop() {
    int val = stack1->data;
    stack1  = stack1->next;
    return val;
}

void s2push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = stack2;
    stack2 = newNode;
}

int s2pop() {
    int val = stack2->data;
    stack2  = stack2->next;
    return val;
}

void enqueue(int val) {
    s1push(val);
}

int dequeue() {
    if (stack2 == nullptr) {
        while (stack1 != nullptr)
            s2push(s1pop());
    }
    return s2pop();
}

//TASK 11: CHECK IF NUMBER EXISTS

bool numberExists(Node* head, int num) {
    Node* cur = head;

    while (cur != nullptr) {
        if (cur->data == num)
            return true;
        cur = cur->next;
    }
    return false;
}

//TASK 12: CHECK PALINDROME

bool isPalindrome(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i])
            return false;
    }
    return true;
}

//TASK 13: ROTATE QUEUE BY K

Node* rotateQueue(Node* head, int k) {
    Node* cur = head;

    for (int i = 1; i < k; i++)
        cur = cur->next;

    Node* newHead  = cur->next;
    cur->next      = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr)
        tail = tail->next;

    tail->next = head;
    return newHead;
}

int main() {

    //Task 1
    Node* n1 = new Node(); n1->data = 6;
    Node* n2 = new Node(); n2->data = 10;
    Node* n3 = new Node(); n3->data = 8;
    Node* n4 = new Node(); n4->data = 15;
    n1->next = n2; n2->next = n3;
    n3->next = n4; n4->next = nullptr;
    cout << "Task 1  - get_nth(4): " << get_nth(n1, 4)->data << endl;

    //Task 2
    Node* a1 = new Node(); a1->data = 1;
    Node* a2 = new Node(); a2->data = 2;
    Node* a3 = new Node(); a3->data = 4;
    a1->next = a2; a2->next = a3; a3->next = nullptr;
    Node* b1 = new Node(); b1->data = 1;
    Node* b2 = new Node(); b2->data = 3;
    Node* b3 = new Node(); b3->data = 4;
    b1->next = b2; b2->next = b3; b3->next = nullptr;
    cout << "Task 2  - Merge: ";
    printList(mergeTwoLists(a1, b1));

    //Task 3
    Node* r1 = new Node(); r1->data = 1;
    Node* r2 = new Node(); r2->data = 2;
    Node* r3 = new Node(); r3->data = 3;
    Node* r4 = new Node(); r4->data = 4;
    Node* r5 = new Node(); r5->data = 5;
    r1->next = r2; r2->next = r3;
    r3->next = r4; r4->next = r5; r5->next = nullptr;
    cout << "Task 3  - Reverse: ";
    printList(reverseList(r1));

    //Task 4
    Node* d1 = new Node(); d1->data = 1;
    Node* d2 = new Node(); d2->data = 2;
    Node* d3 = new Node(); d3->data = 4;
    d1->next = d2; d2->next = d3; d3->next = nullptr;
    cout << "Task 4  - Remove at 1: ";
    printList(removeAt(d1, 1));

    //Task 5
    cout << "Task 5  - Reverse 1234: " << reverse_num(1234) << endl;

    //Task 6
    cout << "Task 6  - isValid ()[]{}: " << (isValid("()[]{}") ? "true" : "false") << endl;
    cout << "Task 6  - isValid (]:     " << (isValid("(]")     ? "true" : "false") << endl;

    //Task 7
    cout << "Task 7  - Remove stars: " << removeStars("leet**cod*e") << endl;

    //Task 8
    pushArr(10); pushArr(20); pushArr(30);
    cout << "Task 8  - peek: " << peekArr() << endl;
    cout << "Task 8  - pop:  " << popArr()  << endl;

    //Task 9
    Node* e1 = new Node(); e1->data = 1;
    Node* e2 = new Node(); e2->data = 1;
    Node* e3 = new Node(); e3->data = 2;
    Node* e4 = new Node(); e4->data = 3;
    Node* e5 = new Node(); e5->data = 3;
    Node* e6 = new Node(); e6->data = 4;
    e1->next = e2; e2->next = e3;
    e3->next = e4; e4->next = e5; e5->next = e6; e6->next = nullptr;
    cout << "Task 9  - Remove duplicates: ";
    printList(removeDuplicates(e1));

    //Task 10
    enqueue(1); enqueue(2); enqueue(3);
    cout << "Task 10 - dequeue: " << dequeue() << endl;
    cout << "Task 10 - dequeue: " << dequeue() << endl;

    //Task 11
    Node* f1 = new Node(); f1->data = 5;
    Node* f2 = new Node(); f2->data = 10;
    Node* f3 = new Node(); f3->data = 15;
    f1->next = f2; f2->next = f3; f3->next = nullptr;
    cout << "Task 11 - Exists 10: " << (numberExists(f1, 10) ? "true" : "false") << endl;
    cout << "Task 11 - Exists 99: " << (numberExists(f1, 99) ? "true" : "false") << endl;

    //Task 12
    int arr[] = {1, 2, 3, 2, 1};
    cout << "Task 12 - Palindrome: " << (isPalindrome(arr, 5) ? "true" : "false") << endl;

    //Task 13
    Node* q1 = new Node(); q1->data = 1;
    Node* q2 = new Node(); q2->data = 2;
    Node* q3 = new Node(); q3->data = 3;
    Node* q4 = new Node(); q4->data = 4;
    Node* q5 = new Node(); q5->data = 5;
    q1->next = q2; q2->next = q3;
    q3->next = q4; q4->next = q5; q5->next = nullptr;
    cout << "Task 13 - Rotate by 2: ";
    printList(rotateQueue(q1, 2));

    return 0;
}