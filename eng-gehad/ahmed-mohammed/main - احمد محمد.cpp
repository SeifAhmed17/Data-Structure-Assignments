#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class linkedlist
{
public:
    Node* head;

    linkedlist()
    {
        head = nullptr;
    }
    bool isempty()
    {
        if(head==nullptr)
            return true;
        else
            return false;
    }

    void insertEnd(int val)
    {
      if(isempty()){
        Node* newnode = new Node();
        newnode->data = val;
        newnode->next = nullptr;
        head = newnode;
      }
       else {
        Node* temp = head;
        while (temp->next != nullptr)
          temp=temp->next;

    }
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp =temp ->next;
        }
        cout << endl;
    }

    Node* get_nth(int n)
    {
        int count = 0;
        Node* temp= head;

        while (temp!= nullptr)
        {
            if (count == n)
                return temp;

            count++;
            temp = temp->next;
        }
        return nullptr;
    }

    void reverse()
    {
        Node* prev = nullptr;
        Node* cur = head;

        while (cur != nullptr)
        {
            Node* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        head = prev;
    }

    void removeAt(int x)
    {
        if (x == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
      else {
        Node* cur = head;
        for (int i = 0; i < x - 1; i++)
            cur = cur->next;

        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
      }
    }


        void removeDuplicates()
    {
        Node* cur = head;

        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->data == cur->next->data)
            {
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
    }
};
// reverse number
int reverse_num(int num) {
    stack<int> s;

    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }

    int result = 0;
    while (!s.empty()) {
        result = result * 10 + s.top();
        s.pop();
    }

    return result;
}
bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}
string removeStars(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '*') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }

    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    return res;
}
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

bool exists(queue<int> q, int x) {
    while (!q.empty()) {
        if (q.front() == x)
            return true;
        q.pop();
    }
    return false;
}

bool isPalindrome(queue<int> q) {
    stack<int> s;
    queue<int> temp = q;

    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }

    while (!q.empty()) {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }

    return true;
}

void rotate(queue<int>& q, int k) {
    int n = q.size();
    k %= n;

    for (int i = 0; i < k; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

int main()
{
    linkedlist l1;

    l1.insertEnd(1);
    l1.insertEnd(4);
    l1.insertEnd(7);
    l1.insertEnd(2);
    l1.insertEnd(3);
    l1.insertEnd(8);

    cout << "List: ";
    l1.display();

    l1.reverse();
    cout << "Reversed: ";
    l1.display();

    l1.removeAt(2);
    cout << "After Delete: ";
    l1.display();

    Node* p = l1.get_nth(1);
    if (p != nullptr)
        cout << "Nth Node: " << p->data << endl;

    linkedlist d;
    d.insertEnd(1);
    d.insertEnd(1);
    d.insertEnd(2);
    d.insertEnd(3);
    d.insertEnd(3);
    d.insertEnd(4);

    cout << "Before Remove Duplicates: ";
    d.display();

    d.removeDuplicates();

    cout << "After Remove Duplicates: ";
    d.display();
    cout << "Reverse Number: " << reverse_num(1234) << endl;
    cout << "Valid: " << isValid("()[]{}") << endl;
    cout << "Remove Stars: " << removeStars("leet**cod*e") << endl;


    enqueue(1); enqueue(2); enqueue(3);
    cout << "Dequeue: " << dequeue() << endl;

    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(2); q.push(1);

    cout << "Palindrome: " << isPalindrome(q) << endl;

    rotate(q, 2);
    cout << "After Rotate: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
