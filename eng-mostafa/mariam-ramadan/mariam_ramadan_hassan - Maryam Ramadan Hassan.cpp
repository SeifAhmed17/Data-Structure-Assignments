//task section 6
#include <iostream>
#include <cassert>
using namespace std;
class Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
public:
    Node *head{};
    Node *tail{};
    int length = 0;
    void insert_end(int value) {
        Node* item = new Node(value);
        if (!head)
            head = tail = item;
        else {
            tail->next = item;
            tail = item;
        }
        length++;
    }
    int delete_front() {
        assert(length);
        int value = head->data;
        Node* cur = head;
        head = head->next;
        delete cur;
        length--;
        if (length == 0)
            tail = nullptr;
        return value;
    }
    void print() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
};

class Queue {
    LinkedList list;

public:
    void enqueue(int value) {
        list.insert_end(value); [cite: 16]
    }

    int dequeue() {
        return list.delete_front(); [cite: 29]
    }

    void display() {
        list.print(); [cite: 32]
    }
    void rotate(int k) {
        int size = list.length;
        if (size <= 1 || k == 0) return;
        k = k % size;
        if (k == 0) return;
        for (int i = 0; i < k; i++) {
            int val = dequeue();
            enqueue(val);
        }
    }
};
int main() {
Queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);

cout << "Original Queue: ";
q.display();
q.rotate(2);

cout << "After Rotate (k=2): ";
q.display();

return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
// task section 5
// task one ****
dequeue using shift approach
int dequeue(){
assert(!isempty());
int value=arr[0];
for(int i=0;i<counter-1;i++){
    arr[i]=arr[i+1];
}
counter--;
return value;
}
///////////////////////////////
// task two ****
queue using two stacks
#include <iostream>
#include<cassert>
#include<stack>
using namespace std;
class stackqueue{
public:
stack<int> s1;
stack<int> s2;

void enqueue(int item){
s1.push(item);
cout<<"Enqueued:"<<item<<"\n";
}

int dequeue(){
if(s2.empty()){
    if(s1.empty()){
        cout<<"Queue is empty"<<"\n";
        return -1;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
int topvalue=s2.top();
s2.pop();
return topvalue;
}
}

bool isempty(){
return s1.empty()&&s2.empty();
}
};

int main()
{
stackqueue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
cout<<"Dequeued:"<<q.dequeue()<<"\n";


    return 0;
}
/////////////////////////////////////////////////////////////////////////
// task section 4
#include <iostream>
#include<cassert>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
class Node{
public:
int data;
Node*next;
};
class stack{
public:
Node*top;
stack(){
top=nullptr;
}

void push(int element){
Node*newnode=new Node();
newnode->data=element;
newnode->next=top;
top=newnode;
}

int pop(){
if(top==nullptr)
    cout<<"empty";
int value=top->data;
Node*temp=top;
top=top->next;
delete temp;
return value;
}

bool isoperand(char c){
return(c>='0'&&c<='9');
}

bool isoperator(char c){
return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int precedence(char op){
if(op=='^') return 3;
if(op=='*'||op=='/') return 2;
if(op=='+'||op=='-') return 1;
return 0;
}

string infixtoprefix(string infix){
reverse(infix.begin(),infix.end());
for(int i=0;i<infix.length();i++){
    if(infix[i]=='(' ;infix[i]==')');
    else if(infix[i]==')' ;infix[i]=='(');
}
string prefix=infixtoprefix(infix);
reverse(prefix.begin(),prefix.end());
return prefix;
}

int evaluateprefix(string prefix){
stack s;
for(int i=prefix.length()-1;i>=0;i--){
    if(isoperand(prefix[i])){
        s.push(prefix[i]-'0');
    }
    else{
        int op1=s.pop();
        int op2=s.pop();
        switch(prefix[i]){
        case '+':push(op1+op2);break;
        case '-':push(op1-op2);break;
        case '*':push(op1*op2);break;
        case '/':push(op1/op2);break;
        case '^':push(pow(op1,op2));break;
        }
    }
}

return s.pop();

}
};
int main()
{
string expression = "(2+3)*4";

    cout << "Infix: " << expression << endl;

    string prefix = infixtotrefix(expression);
    cout << "Prefix: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;


    return 0;
}
