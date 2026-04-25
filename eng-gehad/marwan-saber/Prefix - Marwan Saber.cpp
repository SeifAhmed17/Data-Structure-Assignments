#include <bits/stdc++.h>
#include <ctime>
#include<ext/pb_ds/assoc_container.hpp>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <windows.h>
#pragma warning(disable : 4996)
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedset;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>orderdmultiset;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
template<class T>
class Stack {
    struct Node {
        T data;
        Node *next;
    };
    Node *top,*cur;
    public:
    Stack() {
        top = NULL;
    }
    void push(T x) {
        Node *temp=new Node;
        temp->data=x;
        temp->next=top;
        top=temp;
    }
    bool IsEmpty() {
        return top==NULL;
    }

    T pop() {
        if (IsEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        T element=top->data;
        Node *temp=top;
        top=top->next;
        delete temp;
        return element;
    }
    T peek() {
        if (IsEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return top->data;
    }


    void display() {
        cur=top;
        while(cur!=NULL) {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }



};

string Reverse(string s) {
    string res="";

    for(int i=s.size()-1;i>=0;i--) {
        if (s[i]!=')' and s[i]!='(') {
            res+=s[i];
        }
        else if (s[i]==')') {
            res+='(';
        }
        else {
            res+=')';
        }
    }
    return res;
}


int Precedence(char op) {
    if (op=='+' or op=='-') return 1;
    else if (op=='*' or op=='/') return 2;
    else if (op=='^') return 3;
     return 0;

}
string InfixToPostfix(string expression) {
    Stack<char> st;
    string res="";
    for(char c:expression) {
        if (isdigit(c)) {
            res+=c;
        }
        else if (c=='(') {
            st.push(c);
        }
        else if (c==')') {
            while (st.peek()!='(') {
                res+=st.pop();
            }
            st.pop();

        }
        else {
           while (!st.IsEmpty() and Precedence(st.peek()) >= Precedence(c) ) {
               res+=st.pop();
           }
            st.push(c);

        }

    }
    while(!st.IsEmpty()) {
        res+=st.pop();
    }

    return res;


}


string PostfixToPrefix(string s) {
   string expression= InfixToPostfix(Reverse(s));
    reverse(expression.begin(), expression.end());
    return expression;
}
int operation(int a,int b,char op) {
    switch (op) {
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':return a/b;
    }
}


int Evaluate(string expression) {
    Stack<int> st;
    for(int i=expression.size()-1;i>=0;i--) {
        if (isdigit(expression[i])) {
            st.push(expression[i]-'0');
        }
        else {
            int a=st.pop();
            int b=st.pop();
            st.push(operation(b,a,expression[i]));
        }
    }
    return st.pop();
}


void CR7() {
    string s; cin>>s;
    cout<<PostfixToPrefix(s)<<endl;
    cout<<Evaluate(PostfixToPrefix(s));
}

signed main()
{
    fast();
int ts=1; //cin>>ts;
    while(ts--) {
        CR7();
    }


}
