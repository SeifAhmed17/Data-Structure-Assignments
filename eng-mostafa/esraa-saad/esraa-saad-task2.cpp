

#include <iostream>
#include <stack>
using namespace std;
void copystack(stack<int>&s,stack<int>&c) {
    stack<int>t;
    while (!s.empty())
    {
        t.push(s.top());
        s.pop();
    }
    while (!t.empty())
    {
        c.push(t.top());
        t.pop();
    }

      
}

int main()
{
    stack<int>s;
    stack<int>c;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    copystack(s,c);
    cout << "c.top" << c.top();
}
