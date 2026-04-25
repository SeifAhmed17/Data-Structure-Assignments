#include <iostream>
#include <stack>
#include <queue>
#include <cassert>
using namespace std;
const int MAX = 100;
class linkedlist {
    struct Node {
        int item;
        Node* next;

    };
    Node* first;
    Node* last;
    int length;
public:
    linkedlist() {
        first = last = NULL;
        length = 0;
    }
    bool isempty() {
        return length == 0;
    }
    void insertfirst(int value)
    {
        Node* newNode = new Node;
        newNode->item = value;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = first;
            first = newNode;

        }
        length++;

    }
    void insertlast(int  value) {
        Node* newNode = new Node;
        newNode->item = value;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }

        length++;
    }
    void insertatpos(int pos, int value) {

        if (pos<0 || pos>length)
        {
            cout << "out of the range";
        }
        else {
            Node* newNode = new Node;
            newNode->item = value;
            if (pos == 0)
            {
                insertfirst(value);
            }
            else if (pos == length)
            {
                insertlast(value);
            }
            else {
                Node* cur = first;
                for (int i = 1; i < pos; i++) {
                    cur = cur->next;
                }
                newNode->next = cur->next;
                cur->next = newNode;

                length++;

            }
        }
    }
    void print() {
        if (length == 0) {
            cout << "linked list is empty";
        }
        else {
            Node* cur = first;
            while (cur != NULL) {
                cout << cur->item << "";
                cur = cur->next;
            }
        }
    }

    void removefirst(int element) {
        Node* curr;
        if (!isempty()) {
            curr = first;
            first = first->next;
            delete curr;
            length--;
        }
        else if (length == 1)
        {
            last = NULL;
            delete last;
        }
        else
        {
            return;
        }

    }
    void removelast()
    {
        if (isempty()) {
            return;
        }
        else if (length == 1)
        {
            last = NULL;
            delete last;

        }
        else {
            Node* curr = first->next; Node* prev = first;
            while (curr != last) {
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;
            last = prev;
            length = length - 1;
        }
    }
    void removeposition(int element) {
        if (isempty())
        {
            return;
        }
        else if (length == 0)
        {
            last = NULL;
            delete last;
        }
        else if (first->item == element)
        {
            Node* curr = first;
            first = first->next;
            delete curr;
            length--;
        }
        else {
            Node* curr = first->next; Node* prev = first;
            while (curr != NULL, curr->item != element) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL) {
                cout << "not found";
            }
            else
            {
                prev->next = curr->next;
                if (last == curr)
                    last == prev;
                delete curr;
                length = length - 1;

            }
        }

    }
    //====================delete position===================//
    void deletposition(int pos)
    {
        if (length == 0)
        {
            return;
        }
        else {
            Node* temp = first;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
  //====================== reverse linkedlist===================//

    void reverse() {
        Node* curr = first;
        Node* next = NULL;
        Node* prev = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first = prev;


    }
    int search(int element) {
        Node* curr = first;
        while (curr != NULL) {
            if (curr->item == element)
                return element;
            curr = curr->next;

        }


        return -1;
    }
    //=============================deleteduplicate=====================//
    void deleteduplicate()
    {
        if (first == NULL)
            return;
        Node* curr = first;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->item == curr->next->item)
            {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
    }
    //============================is exist===================//

    bool isexist(int element) {
        Node* curr = first;
        while (curr != NULL) {
            if (curr->item == element)
                return true;
            curr = curr->next;

        }
        return false;
    }

    //=======================stack tasks===============//
    class Stack {
    private:
        int top;
        int s[MAX];
    public:
        Stack() {
            top = -1;
        }
        bool isempty()
        {
            return top == NULL;
        }
        void push(int x) {
            if (top < MAX - 1) {
                top++;
                s[top] = x;
            }
        }
        int pop() {
            if (top == -1) {
                cout << "stack is empty";
            }
            else {
                return s[top--];
            }

        }
        void display() {
            if (top != -1) {
                for (int i = top; i >= 0; i--)

                {
                    cout << s[i];
                }
            }
            else
            {
                cout << "stack is empty" << endl;
            }

        }
        int getsize()
        {
            return top + 1;
        }
    };

    // ==========reverse num=============//
    void reverse_num(int& num) {
        if (num >= 10) {
            Stack s;
            while (num) {
                s.push(num % 10);
                num /= 10;
            }

            int p = 1;
            while (!s.isempty()) {
                num += p * s.pop();
                p *= 10;
            }
        }
    }

    //==================== copy two stack===============//
    
    stack<int>s;
    stack<int>c;
    stack<int>d;
    void pushelementstostack()
    {
        s.push(10);
        s.push(20);
        s.push(30);
    }
    void copystack() {

        while (!s.empty()) {
            c.push(s.top());

        }

    }

    //===================without stars task===================//

    string withoutstars(string s) {
        stack<char> c;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*')
            {
                c.push(s[i]);

            }
            else
            {
                if (!c.empty()) {
                    c.pop();
                }
            }
        }
        string r = "";

        while (!c.empty()) {
            r = c.top() + r;
            c.pop();
        }
        return r;

    }
    //===============valid parenthese===============//

    bool ArePair(char open, char close)

    {

        if (open == '(' && close == ')')

            return true;

        else if (open == '{' && close == '}')

            return true;

        else if (open == '[' && close == ']')

            return true;

        return false;

    }

    bool AreBalanced(string exp)

    {

        stack<char>  S;

        int length = exp.length();

        for (int i = 0; i < length; i++)

        {

            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')

                S.push(exp[i]);

            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')

            {

                if (S.empty() || !ArePair(S.top(), exp[i]))

                    return false;

                else

                    S.pop();

            }

        }

        return S.empty() ? true : false;

    }
    //======infix to prefix===============//

    class Stack
    {
        Node* top;

    public:
        Stack() { top = NULL; }

        void push(char x)
        {
            Node* n = new Node();
            n->data = x;
            n->next = top;
            top = n;
        }

        void pop()
        {
            if (top != NULL)
            {
                Node* t = top;
                top = top->next;
                delete t;
            }
        }

        char Top() {
            if (top != NULL) {
                return top->data;
            }
        }

        bool empty() { return top == NULL; }
    };

    bool IsOperand(char c)
    {
        return isalnum(c);
    }

    bool IsOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }

    int Priority(char op)
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '$') return 3;
        return 0;
    }

    bool RightAssoc(char op)
    {
        return op == '$';
    }

    string InfixToPostfix(string s)
    {
        Stack st;
        string postfix = "";

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (c == ' ') continue;

            if (IsOperand(c))
                postfix += c;

            else if (c == '(')
                st.push(c);

            else if (c == ')')
            {
                while (!st.empty() && st.Top() != '(')
                {
                    postfix += st.Top();
                    st.pop();
                }
                st.pop();
            }

            else if (IsOperator(c))
            {
                while (!st.empty() && st.Top() != '(' &&
                    (Priority(st.Top()) > Priority(c) ||
                        (Priority(st.Top()) == Priority(c) && !RightAssoc(c))))
                {
                    postfix += st.Top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            postfix += st.Top();
            st.pop();
        }

        return postfix;
    }
    string InfixToPrefix(string s)
    {
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }

        string post = InfixToPostfix(s);
        reverse(post.begin(), post.end());

        return post;
    }
    int app(char op, int a, int b)
    {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
    }
    int value(string s)
    {
        Stack st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (isdigit(c)) {
                st.push(c - '0');
            }
            else {
                int a = st.Top();
                st.pop();
                int b = st.Top();
                st.pop();
                int result = app(c, a, b);
                st.push(result);
            }
        }
        return st.Top();

    }


//=====================queue tasks==========================//
class queue {
    struct Node {
        int data;
        Node* next;
    };
    int length;
    Node* front;
    Node* rear;
public:
    queue() {
        front = rear = NULL;
        length = 0;
    }
    bool isempty()
    {
        return(length == 0);

    }
    void enqueue(int value)
    {
        Node* newnode = new Node;
        newnode->data = value;
        newnode->next = NULL;
        if (isempty())
        {
            rear = front = newnode;

        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
        length++;
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty";
        }
        else if (length == 1)
        {
            delete front;
            rear = NULL;
            length = 0;
        }
        else
        {
            Node* curr = front;
            front = front->next;
            delete curr;
            length--;
        }
    }
    int getfront()
    {
        assert(!isempty());
        return front->data;
    }
    int getrear()
    {
        assert(!isempty());
        return rear->data;

    }
    void clear()
    {
        Node* temp;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        length = 0;

    }
    void display()
    {
        Node* cur = front;
        while (cur != NULL)
        {
            cout << cur->data;
            cur = cur->next;
        }
    }

    //==========rotate======================//
    void rotate(int k)
    {
        queue q;
        for (int i = 0; i < 2; i++)
        {
            Node* temp = front;
            front = front->next;
            rear->next = temp;
            rear = temp;
            temp->next = NULL;


        }

    }

    };
    //============= queue using two stack===================//

    stack <int> s1, s2;
    void enqueue(int value)
    {
        s1.push(value);
    }
    int dequeue() {
        if (s2.empty())
        {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();

            }
        }
        int item = s2.top();
        s2.pop();
        return item;
    }
    //=======================palindrome===================//

    bool ispalindrome(queue<int>q1) {
        stack <int> st;
        queue <int> q = q1;
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
        while (!q.empty())
        {
            if (q.front() != st.top())
            {
                return false;
                q.pop();
                st.pop();
            }
            else
            {
                return true;
            }
        }










