#include<iostream>
#include <algorithm>
using namespace std;
#include<stack>
// task 1:
string remove_star(string st)
{
    stack<char>s;
    string s2;
    for(int i=0; i<st.length(); i++)
    {
        if(st[i] !='*')
        {
            s.push(st[i]);
        }
        else 
        {
            if(s.empty())
            {
                continue;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        return "string has been removed";
    }
    else
    {
        while(!s.empty())
        {
            s2+=s.top();
            s.pop();
        }
    }
    reverse(s2.begin(),s2.end());
    return s2;
}
// ------------------------------------------
// Task 2: 
stack<int> copy(stack<int>s1,stack<int>&s2)
{
    stack<int>s3;
    while(!s1.empty())
    {
        s3.push(s1.top());
        s1.pop();
    }
    while(!s3.empty())
    {
        s2.push(s3.top());
        s3.pop();
    }
    return s2;
}
// ------------------------------------------
// task 3:
int size(stack<int>s)
{
    if(s.empty())
    {
        return 0;
    }
    s.pop();
   return 1+size(s);
}
// Task 3 in another way:
int size2(stack<int>s)
{
    int count=0;
    if(s.empty())
    {
        return 0;
    }
    else
    { 
        while(!s.empty())
        {
            count++;
            s.pop();
        }
    }
    return count;
}
int main()
{
    // task 1:
    string s;
    cout<<"Enter the string : ";
    cin>>s;
   cout<<remove_star(s)<<endl;
   // task 2:
   stack<int>s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   stack<int>s2;
   copy(s1,s2);
   cout<<"Top of s1: "<<s1.top()<<endl;
   cout<<"Top of s2: "<<s2.top()<<endl;
   s2.pop();
   cout<<"Top of s2: "<<s2.top()<<endl;
   s2.pop();
   cout<<"Top of s2: "<<s2.top()<<endl;
    // task 3: 
    stack<int>s3;
    s3.push(1);
    s3.push(2);
    s3.push(3);
    s3.push(4);
    s3.push(5);
    s3.push(6);
    s3.push(7);
    cout<<"Size of stack is: "<<size(s3)<<endl;
    cout<<"Size of stack is: "<<size2(s3)<<endl;
    return 0;
}
