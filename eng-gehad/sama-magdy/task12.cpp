#include<iostream>
#include<cassert>
#include<queue>
using namespace std;
class stack
{
    int top = -1;
    int num[100];
public:
    bool isfull()
    {
        return(top == 99);
    }
    bool isempty()
    {
        return(top == -1);
    }
    void push(int x)
    {
        assert(!isfull());
        num[++top] = x;
    }
    int pop()
    {
        assert(!isempty());
        return num[top--];
    }
    int peek()
    {
        return num[top];
    }
};

bool isPalindrome(queue<int> q)
{
    stack st;
    queue<int> temp = q;
    while(!temp.empty())
    {
        st.push(temp.front());
        temp.pop();
    }
    while(!q.empty())
    {
        if(q.front() != st.peek())
            return false;
        q.pop();
        st.pop();
    }
    return true;
}

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    if(isPalindrome(q))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
    return 0;
}