#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long sl;
class stack{
private:
    int top, size, * array , length;
public:
    stack(int siz) :top(-1), length (0) {
        size = siz;
        array = new int[size];
    }
    bool isfull() {
        return top == size - 1;
    }
    void push(int element) {
        if (isfull()) return;
        array[++top] = element;
        length++;
    }
    bool isempty() {
        return top == -1;
    }
    int peek() {
        if (!isempty())
            return array[top];
    }
    void pop() {
        if (isempty()) {
            return;
        }
        top--, length--;
    }
    //Task 1:Removing stars from a string.
    string remove_stars(string& st) {
        for (int i=0 ; i <st.size();i++) {
            if (st[i] != '*') push(st[i]);
            else pop();
        }
        st="";
        string temp ="";
        while(!isempty()){
            temp += peek();
            pop();
        }
        int s = temp.size()-1;
        for (int i=0 ; i < temp.size() ; i ++ ){
            st += temp[s--];
        }
        return st;
    }
    //Task 2: Write a function to copy a stack to another.
    void copy_stack(stack & s) {
        stack temp(size);
        int temp_top = top;
        while (temp_top != -1) {
            temp.push(array[temp_top--]);
        }
        while (!temp.isempty()) {
            s.push(temp.peek());
            temp.pop();
        }
    }
    //Task3: Write a function to return the size of a stack
    int getsize() {
        return length;
    }

};
int main() {
    stack temp(100);
    string s = "leet**cod*e";
    cout<<temp.remove_stars(s);
    return 0;
}
