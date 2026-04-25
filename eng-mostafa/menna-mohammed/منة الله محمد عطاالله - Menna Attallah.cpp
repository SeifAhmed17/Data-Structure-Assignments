#include<iostream>
#include<stack>
using namespace std;
/*===================================================================*/
/*queue with using two stack*/
class queue
{
    stack<int>s1,s2;
    public:
    void enqueue(int item)
    {
        s1.push(item);
    }
    void dequeue()
    {
        if(s1.empty()&&s2.empty())
        {
            cout<<"the queue is empty...\n";
            return;
        }
        if (s2.empty()) 
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    void get_top()
    {
        if(s1.empty()&&s2.empty()) 
        {
            cout<<"queue is empty...\n";
            return;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<s2.top()<<"\n";
    }
};
int precedence(char k)
{
    if (k == '+' || k == '-')
        return 1;
    if (k == '/' || k == '*')
        return 2;
    return 0;
}
/*===========================================================================*/
/*prefix*/
string prefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    string s;
    stack<char>st;
    for (char c : infix)
    {
        if (c == ' ') continue;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            s += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                s += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(c) < precedence(st.top()))
            {
                s += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    /*prefix*/
    
    string l = "(A + B) * (C + D) - E / F";
    cout << prefix(l);
    /*queue with using two stack*/
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.get_top(); 

    q.dequeue(); 
    q.get_top(); 

    q.enqueue(40);
    q.dequeue(); 
    q.get_top();

}