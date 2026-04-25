#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* get_nth(Node* head, int n) {
    int count = 1;
    Node* current = head;
    while (current != nullptr) {
        if (count == n) return current;
        count++;
        current = current->next;
    }
    return nullptr;
}

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

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* removeAt(Node* head, int x) {
    if (!head) return nullptr;
    if (x == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; curr != nullptr && i < x - 1; i++) {
        curr = curr->next;
    }
    if (!curr || !curr->next) return head;
    Node* temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
    return head;
}

int reverse_num(int num) {
    stack<int> s;
    int temp = num;
    while (temp > 0) {
        s.push(temp % 10);
        temp /= 10;
    }
    int reversed = 0;
    int multiplier = 1;
    while (!s.empty()) {
        reversed += s.top() * multiplier;
        s.pop();
        multiplier *= 10;
    }
    return reversed;
}

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

string removeStars(string s) {
    string res = "";
    for (char c : s) {
        if (c == '*') {
            if (!res.empty()) res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}

template <size_t N>
class ArrayStack {
    int arr[N];
    int topIndex = -1;
public:
    void push(int val) {
        if (topIndex < (int)N - 1) arr[++topIndex] = val;
    }
    int pop() {
        if (!isEmpty()) return arr[topIndex--];
        return -1;
    }
    int peek() {
        if (!isEmpty()) return arr[topIndex];
        return -1;
    }
    bool isEmpty() {
        return topIndex == -1;
    }
};

vector<int> removeDuplicates(int arr[], int n) {
    if (n == 0) return {};
    vector<int> result;
    result.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

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

bool numberExists(queue<int> q, int val) {
    while (!q.empty()) {
        if (q.front() == val) return true;
        q.pop();
    }
    return false;
}

bool checkPalindrome(queue<int> q) {
    vector<int> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        if (v[i] != v[n - i - 1]) return false;
    }
    return true;
}

Node* rotateQueue(Node* head, int k, int size) {
    if (!head || k == 0 || k % size == 0) return head;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = head;
    int steps = k % size;
    for (int i = 0; i < steps; i++) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;
    return head;
}

int main() {
    Node* head = new Node(6);
    head->next = new Node(10);
    head->next->next = new Node(8);
    head->next->next->next = new Node(15);

    Node* nth = get_nth(head, 4);
    if (nth) cout << "Nth node: " << nth->data << endl;

    head = reverseLinkedList(head);
    
    head = removeAt(head, 1);

    cout << "Reversed num: " << reverse_num(1234) << endl;

    cout << "Valid brackets: " << isValid("(()[])") << endl;

    cout << "Removed stars: " << removeStars("leet**cod*e") << endl;

    int arr[] = {1, 1, 2, 3, 3, 4};
    vector<int> unique = removeDuplicates(arr, 6);

    QueueUsingStacks qs;
    qs.enqueue(10);
    qs.enqueue(20);
    cout << "Dequeued: " << qs.dequeue() << endl;

    queue<int> palQ;
    palQ.push(1); palQ.push(2); palQ.push(1);
    cout << "Is Palindrome: " << checkPalindrome(palQ) << endl;

    Node* qHead = new Node(1);
    qHead->next = new Node(2);
    qHead->next->next = new Node(3);
    qHead->next->next->next = new Node(4);
    qHead->next->next->next->next = new Node(5);
    qHead = rotateQueue(qHead, 2, 5);

    return 0;
}