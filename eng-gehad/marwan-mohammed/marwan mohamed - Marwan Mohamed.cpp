#include <bits/stdc++.h>
using namespace std;

// ================= Node Definition =================
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ================= 1. Get Nth Node =================
Node* get_nth(Node* head, int n) {
    int count = 0;
    while (head) {
        if (count == n)
            return head;
        count++;
        head = head->next;
    }
    return NULL;
}

// ================= 2. Merge Two Sorted Lists =================
Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

// ================= 3. Reverse Linked List =================
Node* reverseList(Node* head) {
    Node* prev = NULL;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// ================= 4. Delete Node at Position =================
Node* deleteAt(Node* head, int x) {
    if (!head) return NULL;

    if (x == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < x - 1 && cur->next; i++)
        cur = cur->next;

    if (cur->next) {
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    return head;
}

// ================= 5. Reverse Number using Stack =================
int reverse_num(int num) {
    stack<int> s;

    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }

    int rev = 0, place = 1;
    while (!s.empty()) {
        rev += s.top() * place;
        s.pop();
        place *= 10;
    }
    return rev;
}

// ================= 6. Valid Parentheses =================
bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
                return false;
        }
    }
    return st.empty();
}

// ================= 7. Remove Stars =================
string removeStars(string s) {
    string res;
    for (char c : s) {
        if (c == '*') {
            if (!res.empty()) res.pop_back();
        } else res += c;
    }
    return res;
}

// ================= 8. Stack using Array =================
#define N 100
class StackArr {
    int arr[N];
    int top;
public:
    StackArr() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int x) {
        if (top < N - 1)
            arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1;
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        return -1;
    }
};

// ================= 9. Remove Duplicates =================
vector<int> removeDuplicates(vector<int>& arr) {
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1])
            res.push_back(arr[i]);
    }
    return res;
}

// ================= 10. Queue using 2 Stacks =================
class Queue2Stacks {
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
        int x = s2.top();
        s2.pop();
        return x;
    }
};

// ================= 11. Check if Exists =================
bool exists(vector<int>& arr, int x) {
    for (int v : arr)
        if (v == x) return true;
    return false;
}

// ================= 12. Palindrome Queue =================
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

// ================= 13. Rotate Queue =================
void rotate(queue<int>& q, int k) {
    int n = q.size();
    k %= n;

    for (int i = 0; i < k; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

// =================(Examples Testing) =================
int main() {
    // ===== Linked List Example =====
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "get_nth(2): " << get_nth(head, 2)->data << endl;

    head = reverseList(head);
    cout << "Reversed list: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = deleteAt(head, 1);
    cout << "After delete index 1: ";
    temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // ===== Merge Lists =====
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    Node* merged = mergeLists(l1, l2);
    cout << "Merged: ";
    temp = merged;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // ===== Stack Reverse Number =====
    cout << "reverse_num(1234): " << reverse_num(1234) << endl;

    // ===== Valid Parentheses =====
    cout << "isValid(\"()[]{}\"): " << isValid("()[]{}") << endl;

    // ===== Remove Stars =====
    cout << "removeStars(\"leet**cod*e\"): " << removeStars("leet**cod*e") << endl;

    // ===== Stack Array =====
    StackArr st;
    st.push(10); st.push(20);
    cout << "Stack peek: " << st.peek() << endl;

    // ===== Remove Duplicates =====
    vector<int> arr = {1,1,2,3,3,4};
    vector<int> uniqueArr = removeDuplicates(arr);
    cout << "Unique: ";
    for (int x : uniqueArr) cout << x << " ";
    cout << endl;

    // ===== Queue using 2 Stacks =====
    Queue2Stacks q2;
    q2.enqueue(1); q2.enqueue(2);
    cout << "Dequeue: " << q2.dequeue() << endl;

    // ===== Exists =====
    cout << "Exists 3: " << exists(arr, 3) << endl;

    // ===== Palindrome Queue =====
    queue<int> q;
    q.push(1); q.push(2); q.push(1);
    cout << "Is Palindrome: " << isPalindrome(q) << endl;

    // ===== Rotate Queue =====
    queue<int> rq;
    rq.push(1); rq.push(2); rq.push(3); rq.push(4); rq.push(5);
    rotate(rq, 2);
    cout << "Rotated Queue: ";
    while (!rq.empty()) {
        cout << rq.front() << " ";
        rq.pop();
    }
    cout << endl;

    return 0;
}
