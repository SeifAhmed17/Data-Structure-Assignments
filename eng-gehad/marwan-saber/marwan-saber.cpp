#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
class Node {
public:
    char   data;
    Node* next;
    Node() : data(0), next(NULL) {}
};
class Stack {
    Node* top = NULL;  // always points to newest node
public:
    bool isEmpty() { return top == NULL; }

    void push(char item) {
        Node* n = new Node();
        n->data = item;
        n->next = top;   // point to old top
        top     = n;     // update top
    }

    void pop() {
        if (isEmpty()) return;
        Node* del = top;
        top = top->next;  // move top down
        delete del;
    }

    char peek() { return top->data; }
};
// Task 3:
int count_stack(Stack* st) {
    int count = 0;
    Stack *s = new Stack();
    while (!st->isEmpty()) {
        count++;
        s->push(st->peek());
        st->pop();
    }
    while (!s->isEmpty()) {
        st->push(s->peek());
        s->pop();
    }
    delete s;
    return count;
}
//Task 1:
string non_star(string str) {
    Stack st;

    string res="";
       for (char c : str) {
           if (c != '*') {
               st.push(c);
           }
           else {
               st.pop();
           }
       }
    while (!st.isEmpty()) {
        res += st.peek();
        st.pop();
    }

    reverse(res.begin(),res.end());
    return res;
}
//Task 3:
Stack *copy_stack(Stack *&st) {
   Stack *s1 = new Stack();
   Stack *s2 = new Stack();
    while (!st->isEmpty()) {
        s1->push(st->peek());
        st->pop();
    }

    while (!s1->isEmpty()) {
        s2->push(s1->peek());
        st->push(s1->peek());
        s1->pop();
    }
    delete s1;
    return s2;
}
signed main() {
    // fast();
    Stack *st = new Stack();
    string str; cin >> str;
             //NON-Star task
    cout << non_star(str) << endl;
              //copy task
    st->push('A'); st->push('B'); st->push('C');
    Stack *co= copy_stack(st);
    while (!co->isEmpty()) {
        cout << co->peek() << " ";
        co->pop();
    }
    cout << endl;
            // count task
    cout << count_stack(st) << endl;
 delete st;
}