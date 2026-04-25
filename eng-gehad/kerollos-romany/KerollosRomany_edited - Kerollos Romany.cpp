#include<bits/stdc++.h>
using namespace std;
struct  Node
{
    int data;
    Node *next{};
    Node(int x) : data(x){};
};
class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;

public:
    LinkedList(int x) {
        head = new Node(x);
        tail = head;
        length = 1;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        tail->next = newNode;
        tail = newNode;
        length++;
    }

    //task1 Get_nth item:
    Node* getNth(int n) {
        if (n <= 0 || n > length)
            return nullptr;
        Node* cur = head;
        for (int i = 1; i < n; i++)
            cur = cur->next;

        return cur;
    }
    // Merge Two Sorted Lists
    static Node* mergeLists(Node* list1, Node* list2) {

        Node tempNode(0);
        Node* tail = &tempNode;

        while (list1 && list2) {
            if (list1->data <= list2->data) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        return tempNode.next;
    }
    // Reverse linked list
    static Node* reverseList(Node* head) {

        Node* prev = nullptr;
        Node* cur = head;

        while (cur) {
            Node* next = cur->next; // save next
            cur->next = prev;       // reverse link
            prev = cur;
            cur = next;
        }

        return prev;
    }
    // task 4
    static Node* removeAtPos(Node* head, int x) {
        if (!head) return nullptr;
        if (x == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node* cur = head;
        for (int i=0; i < x-1 and cur->next; i++) {
            cur = cur->next;
        }
        if (!cur->next) {
            return head;
        }
        Node*temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return head;
    }
};


const int N = 1000;
// task 8
class Stack {
private:
    int arr[N];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (top == N - 1) {
            cout << "Stack is Full\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "there is no item to pop\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    // task 5
    int reverseNum(int num) {
        int res = 0;
        Stack st;
        while (num > 0) {
            st.push(num % 10);
            num /= 10;
        }
        int multiplier = 1;
        while (!st.isEmpty()) {
            res += multiplier * st.pop();
            multiplier *= 10;
        }
        return res;
    }
    // task 6
    bool isValid(string s) {
        Stack st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.isEmpty()) return false;
                if (c == ')' && st.peek() != '(') return false;
                if (c == '}' && st.peek() != '{') return false;
                if (c == ']' && st.peek() != '[') return false;
                st.pop();
            }
        }
        return st.isEmpty();
    }
    // task 7
    string removeStars(string s) {
        Stack st;
        for (char c : s) {
            if (c == '*') {
                if (!st.isEmpty())
                    st.pop();
            } else {
                st.push(c);
            }
        }
        string res = "";
        while (!st.isEmpty()) {
            res += (char)st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//=================================================================================
//task 10
class QueueUsingStacks {
    private:
        Stack s1, s2;
    public:
    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
    void display() {
        QueueUsingStacks temp = *this;
        while (!temp.isEmpty()) {
            cout << temp.dequeue() << " ";
        }
    }
};
//task 11
bool Exist(QueueUsingStacks q, int num) {
    while (!q.isEmpty()) {
        if (q.dequeue() == num) return  true;
    }
    return false;
}
//task 12
bool isPalindrome(QueueUsingStacks q) {
    vector<int> v;
    while (!q.isEmpty()) {
        v.push_back(q.dequeue());
    }
    int sz=v.size();
    for (int i=0; i*i < sz; ++i) {
        if (v[i] != v[sz-i-1]) return false;
    }
    return true;
}
//task 13
class Queue {
    struct Node {
        int data;
        Node* next;
        Node(int x): data(x), next(NULL) {};
    };
    Node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node* newnode = new Node(x);
        if (!rear) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = rear->next;
        }
    }
    int dequeue() {
        if(!front) return -1;
        int x = front->data;
        Node* temp = front;
        front=front->next;
        if(!front) rear = NULL;
        delete temp;
        return x;
    }
    bool empty() {
        return front == NULL;
    }
    void rotate(int k){
        while(k-- && front) {
            enqueue(dequeue());
        }
    }
};
int main(){
    // task 9 according array is sorted
    int arr[] = {1, 1, 2, 3, 3, 6};
    int n = 6;
    Stack st;
    for (int i = 0; i < n; i++) {
        if (st.isEmpty() || st.peek() != arr[i]) {
            st.push(arr[i]);
        }
    }
    vector<int> res;
    while (!st.isEmpty()) {
        res.push_back(st.pop());
    }
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x << " ";
    }
}