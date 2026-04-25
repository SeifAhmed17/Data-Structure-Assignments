#include <iostream>
#include<string>
using namespace std;

template <class t>
class stack {
private:
    int top;
    int size;
    t *items;
public:
    stack(int s) : top(-1), size(s) {
        items = new t[size];
    }
    bool isEmpty() {
        return top < 0;
    }
    bool isFull(){
        return top >= size - 1;
    }
    void push(t new_element) {
        if (isFull())
            cout << "Stack is Full" << endl;
        else
        items[++top] = new_element;
    }
    void pop() {
        if (isEmpty())
            cout << "Stack is Empty" << endl;
        else
            --top;
    }
    t getTop() {
        if (isEmpty())
            return t();
        else
            return items[top];
    }

    void print() {
        cout << "[";
        for (int i = top; i >= 0; i--) {
            cout << " " << items[i];
        }
        cout << " ]" << endl;
    }

    //------------ Task 2 ----------------//

    void copy(stack& st) {
        top = st.top;
        size = st.size;
        for (int i = 0; i <= top; i++) {
            items[i] = st.items[i];
        }
    }
   
    //------------ Task 3 ----------------//

    int getSize() {
        return top + 1;
    }

};


//------------ Task 1 ----------------//

string remove_stars(string s) {
    stack<char> s2(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            if (!s2.isEmpty())
                s2.pop();
        }
        else {
            s2.push(s[i]);
        }
    }
    string after_remove(s2.getSize(), ' ');
    int i = s2.getSize() - 1;
    while (!s2.isEmpty()) {
        after_remove[i] = s2.getTop();
        s2.pop();   i--;
    }
    return after_remove;
}


int main()
{
    stack<int> st1(15), st2(20);
    st1.push(5); st1.push(10); st1.push(15); st1.push(20); st1.push(25);

    cout << "Stack size = " << st1.getSize() << endl;

    st2.copy(st1);
    st2.print();

    string s = "Leet**cod*e";
    s = remove_stars(s);
    cout << s << endl;
    return 0;
}