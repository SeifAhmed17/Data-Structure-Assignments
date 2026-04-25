#include <bits/stdc++.h>
using namespace std;

//نبنى ال linled list 
struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "null" << endl;
}

//ايجاد n من ال lined list
Node* get_nth(Node* head, int n)
{
    Node* current = head;
    int count = 1;
    while (current != nullptr)
    {
        if (count == n)
        {
            return current;
        }
        current = current->next;
        count++;
    }
    return nullptr;
}

//merge 2 linked list
Node* mergeLists(Node* l1, Node* l2)
{
    if (!l1)
    {
        return l2;
    }
    else if (!l2)
    {
        return l1;
    }
    else if (l1->data <= l2->data)
    {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

// reverse linked list
Node* reverseList(Node* head)
{
    Node* prev = nullptr, * curr = head, * next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// delete x
Node* removeAt(Node* head, int x)
{
    if (!head)
    {
        return nullptr;
    }
    if (x == 0)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; curr && i < x - 1; i++)
    {
        curr = curr->next;
    }
    if (!curr || !curr->next)
    {
        return head;
    }
    Node* toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;
    return head;
}

// rotate queue by k 
Node* rotateLinkedList(Node* head, int k, int size)
{
    if (!head || k == 0 || k % size == 0)
    {
        return head;
    }
    k %= size;
    Node* tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = head;
    for (int i = 0; i < k; i++)
    {
        tail = tail->next;
        head = head->next;
    }
    tail->next = nullptr;
    return head;
}
// بناء stack
const int N = 100;

struct ArrayStack {
    int arr[N];
    int topIndex;

    ArrayStack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int x) {
        if (topIndex < N - 1) {
            arr[++topIndex] = x;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[topIndex--];
        }
        cout << "Stack Empty" << endl;
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        return -1;
    }

//reverse number using stack
int reverse_num(int num)
{
    stack<int> s;
    string str = to_string(num);
    for (char c : str)
    {
        s.push(c - '0');
    }
    int reversed = 0, place = 0;
    while (!s.empty())
    {
        reversed += s.top() * pow(10, place++);
        s.pop();
    }
    return reversed;
}

//valid parentheses
bool isValid(string str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            if ((c == ')' && s.top() != '(') || (c == '}' && s.top() != '{') || (c == ']' && s.top() != '['))
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

//removing stars
string removeStars(string s)
{
    string res = "";
    for (char c : s)
    {
        if (c == '*')
        {
            if (!res.empty())
            {
                res.pop_back();
            }
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}

//queue using 2stacks
struct StackQueue
{
    stack<int> s1, s2;
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top()); s1.pop();
            }
        }
        int val = s2.top(); s2.pop();
        return val;
    }
};

//check exist
void removeDuplicates(int arr[], int n)
{
    if (n == 0) return;
    cout << "Unique elements: " << arr[0] << " ";
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) cout << arr[i] << " ";
    }
    cout << endl;
}

// Palindrome in queue 
bool isPalindromeQueue(queue<int> q)
{
    vector<int> v;
    while (!q.empty())
    {
        v.push_back(q.front()); q.pop();
    }
    for (int i = 0; i < v.size() / 2; i++)
    {
        if (v[i] != v[v.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    

    //  Linked List
    Node* list1 = new Node(1); list1->next = new Node(2); list1->next->next = new Node(4);
    cout << "Original List: "; printList(list1);

    Node* nth = get_nth(list1, 2);
    if (nth) cout << "2nd node value: " << nth->data << endl;

    cout << "After removing index 1: ";
    list1 = removeAt(list1, 1); printList(list1);

    //  Stack
    cout << "--- Array Stack ---" << endl;
    ArrayStack a_stack;
    a_stack.push(50);
    a_stack.push(100);
    cout << "Peek: " << a_stack.peek() << endl;
    cout << "Pop: " << a_stack.pop() << endl;
    cout << "IsEmpty: " << (a_stack.isEmpty() ? "True" : "False") << endl << endl;
    cout << "Reverse 1234: " << reverse_num(1234) << endl;
    cout << "Is (()) valid? " << (isValid("(())") ? "Yes" : "No") << endl;
    cout << "String 'leet**cod*e' becomes: " << removeStars("leet**cod*e") << endl;

    //  Array/Queue
    int arr[] = { 1, 1, 2, 3, 3, 4 };
    removeDuplicates(arr, 6);

    queue<int> q; q.push(1); q.push(2); q.push(1);
    cout << "Is queue [1,2,1] palindrome? " << (isPalindromeQueue(q) ? "Yes" : "No") << endl;

    return 0;
}