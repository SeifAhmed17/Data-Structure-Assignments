#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* Next;
};

template <class T>
class Stack {
public:
    Node<T>* Top;

    Stack() {
        Top = NULL;
    }

    bool isEmpty() {
        return (Top == NULL);
    }

    void push(T item) {
        Node<T>* newnode = new Node<T>();
        newnode->data = item;

        newnode->Next = Top;
        Top = newnode;
    }

    string Display() {
        string s;
        Node<T>* temp = Top;
        while (temp != NULL) {
            s.push_back(temp->data);
            temp = temp->Next;
        }
        return s;
    }

    void Pop() {
        if (isEmpty()) return;

        Node<T>* delptr = Top;
        Top = Top->Next;
        delete delptr;
    }
    T Peek(){
        return Top->data;
    }
    //task/ 2
    void copy(Stack<T> &st){
        while(!this->isEmpty()) this->Pop();
        Stack<T> temp;
        Node<T>*cur = st.Top;
        while(cur != NULL){
            temp.push(cur->data);
            cur=cur->Next;
        }

        while (!temp.isEmpty())
        {
            this->push(temp.Peek());
            temp.Pop();
        }
    }
    //task 3
    int SizeOfStack(){
        int cnt=0;
        Node<T>*temp=Top;
        while (temp!=NULL)
        {
            cnt++;
            temp=temp->Next;
        }
        return cnt;
    }
};
int main(){
    Stack<char> st;
    string s; cin >> s;
    int sz=s.size();
    for(int i=0; i<sz; ++i){
        if(s[i] != '*') st.push(s[i]);
        else st.Pop();
    }
    string removed =st.Display();
    reverse(removed.begin(), removed.end());
    cout << removed;
}