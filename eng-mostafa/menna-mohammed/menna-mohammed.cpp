#include <iostream>
using namespace std;
const int maxx = 100;
template <class t>
class stack
{
private:
    int top;
    t item[maxx];

public:
    stack()
    {
        top = -1;
    }
    void push(t value)
    {
        if (top >= maxx - 1)
            cout << "stack is full" << endl;
        else
        {
            top++;
            item[top] = value;
        }
    }
    bool isempty()
    {
        return top < 0;
    }
    void pop()
    {
        if (isempty())
            cout << "stack is empty" << endl;
        else
        {
            top--;
        }
    }
    void get_top(t &value)
    {
        if (isempty())
            cout << "stack is empty" << endl;
        else
        {
            value = item[top];
            cout << value << endl;
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
    void get_size()
    {
        cout << top + 1 << endl;
    }
    stack copy_stack()
    {
        stack copy;
        copy.top = top;
        for (int i = 0; i <= top; i++)
        {
            copy.item[i] = item[i];
        }
        return copy;
    }
    void get_string()
    {
        for (int i = 0; i <=top; i++)
        {
            cout << item[i];
        }
        cout << endl;
    }
    void remove_stars(string s)
    {
        stack<char> result;
        for (char n : s)
        {
            if (n == '*')
                result.pop();
            else
                result.push(n);
        }
        result.get_string();
    }
};
int main()
{
    // task 1
    stack<char> s1;
    string k = "meee**nna*a";
    s1.remove_stars(k);
    // task 2
    stack<int>s2;
    s2.push(5);
    s2.push(10);
    s2.push(15);
    s2.push(20);
    s2.get_size();
    // task 3
    stack <int>s3;
    s3=s2.copy_stack();
    s3.display();
}