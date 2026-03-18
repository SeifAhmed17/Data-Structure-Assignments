#include <iostream>
using namespace std;

template <class t>

class stack
{
private:
    int maxSize;
    t *item;
    int top;

public:
    stack(int size) : top(-1), maxSize(size)
    {
        item = new t[maxSize];
    }

    bool isEmpty()
    {
        return top == -1;
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

    void pop()
    {
        if (isEmpty())
            cout << "Stack Is Empty\n";
        else
            top--;
    }

    t getTop()
    {
        if (isEmpty())
            return t();
        return item[top];
    }

    // Task 2//
    void copy(stack &s)
    {
        top = -1;
        for (int i = 0; i <= s.top; i++)
        {
            push(s.item[i]);
        }
    }

    // Task 3//
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

    ~stack()
    {
        delete[] item;
    }
};

// Task 1//
string removeStars(string s)
{
    stack<char> st(100);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
            st.pop();
        else
            st.push(s[i]);
    }
    string ans;
    while (!st.isEmpty())
    {
        ans = st.getTop() + ans;
        st.pop();
    }
    return ans;
}

int main()
{
    stack<int> st1(10);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    stack<int> st2(10);
    st2.copy(st1);
    st2.print();
    cout << removeStars("leet**cod*e") << endl;
    cout << st1.getSize() << endl;
    cout << st2.getSize() << endl;
}