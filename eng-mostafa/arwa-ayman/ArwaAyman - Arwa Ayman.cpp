#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

template <class t>
struct Node
{
    t item;
    Node<t> *next;
};

template <class t>

class LinkedList
{
private:
    Node<t> *head, *tail;
    int length;

public:
    LinkedList()
    {
        head = tail = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void insertEnd(t item)
    {
        Node<t> *newNode = new Node<t>;
        newNode->item = item;
        newNode->next = NULL;
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    //---------------------Get nth item-------------------------//
    Node<t> *get_nth(int n)
    {
        assert(!isEmpty());
        if (n < 1 || n > length)
            return NULL;
        Node<t> *curr = head;
        for (int i = 1; i < n; i++)
        {
            curr = curr->next;
        }
        return curr;
    }

    //-------------------Print With For Loop-----------------------//
    void print()
    {
        if (isEmpty())
        {
            cout << "List is Empty\n";
            return;
        }
        Node<t> *curr = head;
        for (int i = 0; i < length; i++)
        {
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    //-------------------Merge Two Sorted Lists-----------------------//
    static LinkedList<t> merge(LinkedList<t> &l1, LinkedList<t> &l2)
    {
        LinkedList<t> l3;
        Node<t> *curr1, *curr2;
        curr1 = l1.head, curr2 = l2.head;
        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->item <= curr2->item)
            {
                l3.insertEnd(curr1->item);
                curr1 = curr1->next;
            }
            else
            {
                l3.insertEnd(curr2->item);
                curr2 = curr2->next;
            }
        }
        while (curr1 != NULL)
        {
            l3.insertEnd(curr1->item);
            curr1 = curr1->next;
        }
        while (curr2 != NULL)
        {
            l3.insertEnd(curr2->item);
            curr2 = curr2->next;
        }
        return l3;
    }

    //-------------------Reverse Linked List-----------------------//
    void reverse()
    {
        if (isEmpty())
            return;
        Node<t> *prev, *curr, *next;
        prev = NULL;
        curr = head;
        tail = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    //-------------------Remove At Position-----------------------//
    void removeat(int index)
    {
        assert(!isEmpty());
        if (index < 0 || index >= length)
        {
            cout << "out of range\n";
            return;
        }
        Node<t> *curr = head;
        if (index == 0)
        {
            head = head->next;
            delete curr;
            length--;
            if (length == 0)
                tail = NULL;
            return;
        }
        for (int i = 1; i < index; i++)
        {
            curr = curr->next;
        }
        Node<t> *temp = curr->next;
        if (temp->next != NULL)
            curr->next = temp->next;
        else
            curr->next = NULL;
        if (temp == tail)
            tail = curr;
        delete temp;
        length--;
    }

    //-------------------Remove Duplicate-----------------------//
    void removeDuplicate()
    {
        assert(!isEmpty());
        Node<t> *curr = head;
        while (curr && curr->next)
        {
            if (curr->next->item == curr->item)
            {
                Node<t> *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                length--;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------Implement Stack Using Array---------------------//
template <class t>

class Stack
{
private:
    int maxSize;
    t *item;
    int top;

public:
    Stack(int size) : top(-1), maxSize(size)
    {
        item = new t[maxSize];
    }

    bool isFull()
    {
        return top == maxSize - 1;
    }

    void push(t newItem)
    {
        if (isFull())
            cout << "Stack Is Full\n";
        else
            item[++top] = newItem;
    }

    //----------------------Pop---------------------------//
    void pop()
    {
        if (isEmpty())
            cout << "Stack Is Empty\n";
        else
            top--;
    }

    //----------------------Peek---------------------------//
    t peek()
    {
        if (isEmpty())
            return t();
        return item[top];
    }
    //----------------------IsEmpty---------------------------//
    bool isEmpty()
    {
        return top == -1;
    }

    //----------------------Copy Stack---------------------------//
    void copy(Stack &s)
    {
        top = -1;
        for (int i = 0; i <= s.top; i++)
        {
            push(s.item[i]);
        }
    }

    //--------------------Get Stack Size-------------------------//
    int getSize()
    {
        return top + 1;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty\n";
        }
        else
        {
            cout << "[ ";
            for (int i = top; i >= 0; i--)
            {
                cout << item[i] << " ";
            }
            cout << "]\n";
        }
    }

    ~Stack()
    {
        delete[] item;
    }
};

//----------------Reverse A Number Using Stack---------------------//
int reversenum(int n)
{
    Stack<int> st(100);
    while (n > 0)
    {
        st.push(n % 10);
        n /= 10;
    }
    int ans = 0, tens = 1;
    while (!st.isEmpty())
    {
        ans = st.peek() * tens + ans;
        tens *= 10;
        st.pop();
    }
    return ans;
}

//-------------------Valid Paranthesis------------------------//
bool matchingParanthesis(char c1, char c2)
{
    return c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']';
}
bool isValid(string s)
{
    Stack<char> st(100);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.isEmpty() || !matchingParanthesis(st.peek(), s[i]))
                return false;
            else
                st.pop();
        }
    }
    if (!st.isEmpty())
        return false;
    return true;
}

//----------------Removing Stars of A String---------------------//
string removeStars(string s)
{
    Stack<char> st(100);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            if (!st.isEmpty())
                st.pop();
        }
        else
            st.push(s[i]);
    }
    string ans;
    while (!st.isEmpty())
    {
        ans = st.peek() + ans;
        st.pop();
    }
    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class t>
struct queueNode
{
    t item;
    queueNode<t> *next;
};

template <class t>
class Queue
{
private:
    int length;
    queueNode<t> *front;
    queueNode<t> *rear;

public:
    Queue() : length(0), front(NULL), rear(NULL) {}

    bool isEmpty()
    {
        return length == 0;
    }

    void enqueue(t item)
    {
        queueNode<t> *newItem = new queueNode<t>;
        newItem->item = item;
        newItem->next = NULL;
        if (isEmpty())
        {
            front = rear = newItem;
        }
        else
        {
            rear->next = newItem;
            rear = newItem;
        }
        length++;
    }

    void dequeue()
    {
        assert(!isEmpty());
        if (length == 1)
        {
            delete front;
            rear = NULL;
        }
        else
        {
            queueNode<t> *temp = front;
            front = front->next;
            delete temp;
        }
        length--;
    }

    t getFront()
    {
        return front->item;
    }

    //----------------Check If A Number Exists---------------------//
    bool checkNumber(int n)
    {
        queueNode<t> *curr = front;
        while (curr != NULL)
        {
            if (curr->item == n)
                return true;
            else
                curr = curr->next;
        }
        return false;
    }

    void display()
    {
        queueNode<t> *curr = front;
        while (curr != NULL)
        {
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    //----------------Rotate By K Positions---------------------//
    void rotateByK(int k)
    {
        if (isEmpty() || k == 0 || k == length)
            return;
        if (k > length)
            k %= length;
        for (int i = 0; i < k; i++)
        {
            queueNode<t> *temp = front;
            front = front->next;
            rear->next = temp;
            temp->next = NULL;
            rear = temp;
        }
    }
};

//----------------Check Palindrome---------------------//
bool isPalindrome(queue<int> q)
{
    stack<int> s;
    queue<int> temp = q;
    while (!temp.empty())
    {
        s.push(temp.front());
        temp.pop();
    }
    while (!q.empty())
    {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }
    return true;
}

//----------------Queue Using 2 Stacks---------------------//
class queueWithStack
{
private:
    int length;
    stack<int> s1, s2;

public:
    queueWithStack() : length(0) {}

    void move(stack<int> &s1, stack<int> &s2)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void enqueue(int item)
    {
        s1.push(item);
        length++;
    }

    int dequeue()
    {
        assert(!isEmpty());
        if (s2.empty())
            move(s1, s2);
        int temp = s2.top();
        s2.pop();
        length--;
        return temp;
    }

    void print()
    {
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        move(temp1, temp2);
        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }

    int getSize()
    {
        return length;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------Infix To Prefix------------------//
template <class t>
struct node
{
    t item;
    node<t> *next;
};

template <class t>

class LinkedStack
{
private:
    node<t> *top;

public:
    LinkedStack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(t newItem)
    {
        node<t> *newPtr = new node<t>;
        newPtr->item = newItem;
        newPtr->next = top;
        top = newPtr;
    }

    t peek()
    {
        assert(!isEmpty());
        return top->item;
    }

    void pop()
    {
        assert(!isEmpty());
        node<t> *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c)
{
    return c >= '0' && c <= '9';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '/' || c == '*')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

string infixToPrefix(string s)
{
    string pre = "";
    string rev = "";
    LinkedStack<char> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
        rev += s[i];
    }
    for (int i = 0; i < rev.length(); i++)
    {
        if (isOperator(rev[i]))
        {
            while (!st.isEmpty() && st.peek() != '(' && precedence(st.peek()) > precedence(rev[i]))
            {
                pre += st.peek();
                st.pop();
            }
            st.push(rev[i]);
        }
        else if (isOperand(rev[i]))
            pre += rev[i];
        else if (rev[i] == ')')
        {
            while (st.peek() != '(')
            {
                pre += st.peek();
                st.pop();
            }
            st.pop();
        }
        else if (rev[i] == '(')
            st.push(rev[i]);
    }
    while (!st.isEmpty())
    {
        pre += st.peek();
        st.pop();
    }
    reverse(pre.begin(), pre.end());
    return pre;
}

//-------------------Expression Evaluation------------------//
int perform(int a, int b, char op)
{
    int ans = 0;
    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    case '^':
        ans = pow(a, b);
        break;
    }
    return ans;
}
int expressionEvaluation(string pre)
{
    LinkedStack<int> st;
    for (int i = pre.length() - 1; i >= 0; i--)
    {
        if (isOperand(pre[i]))
        {
            st.push(pre[i] - '0');
        }
        else
        {
            int a = st.peek();
            st.pop();
            int b = st.peek();
            st.pop();
            st.push(perform(a, b, pre[i]));
        }
    }
    return st.peek();
}