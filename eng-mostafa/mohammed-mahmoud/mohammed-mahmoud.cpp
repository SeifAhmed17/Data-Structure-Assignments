#include <iostream>
#include <stack>
using namespace std;
//Task 1
string removeStars(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '*') 
        {
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}
//Task 2: 
void copyStack(stack<int>& s1, stack<int>& s2)
{
    stack<int> temp;
    while (!s1.empty()) 
    {
        temp.push(s1.top());
        s1.pop();
    }
    while (!temp.empty()) {
        s1.push(temp.top());
        s2.push(temp.top());
        temp.pop();
    }
}
//Task 3:
int stackSize(stack<int> s)
{
    int count = 0;
    while (!s.empty()) {
        count++;
        s.pop();
    }
    return count;
}
int main() {
    //Task 1 
    string s = "leet**cod*e";
    cout << "After removing stars: " << removeStars(s) << endl;
    //Task 2 
    stack<int> s1, s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    copyStack(s1, s2);
    cout << "Copied stack elements: ";
    stack<int> temp = s2;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    //Task 3 
    cout << "Size of stack s1: " << stackSize(s1) << endl;

    return 0;
}