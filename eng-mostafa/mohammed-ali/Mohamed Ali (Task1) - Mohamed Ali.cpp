#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList1 {
    Node* head{};
    Node* tail{};
    int size;
public:
    LinkedList1() : head(nullptr), tail(nullptr) ,size(0) {}
//================================================================
    bool isEmpty() {
        return head == nullptr;
    }
//================================================================

    void insert_front(char val) {
        size++;
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

//================================================================

    void delete_front(){
        if(isEmpty())return;
        Node* temp =head;
        if(size==1){
            head=tail=nullptr;
            return;
        }
        temp=head->next;
        head=temp;
        size--;
    }


//================================================================
    char get_pos (int pos){
       if(pos<1||pos>size)return -1;
       int cnt=1;
       Node* temp =head;
       while (cnt!=pos)
       {
         temp=temp->next;
         cnt++;
       }
       return temp->data;
    }


};

class LinkedList {
    Node* head{};
    Node* tail{};
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr) ,size(0) {}

//================================================================
    bool isEmpty() {
        return head == nullptr;
    }
//================================================================


    void insert_front(int val) {
        size++;
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

//================================================================
  
    void delete_front(){
        if(isEmpty())return;
        Node* temp =head;
        if(size==1){
            head=tail=nullptr;
            return;
        }
        temp=head->next;
        head=temp;
        size--;
    }

//================================================================
    int get_pos (int pos){
       if(pos<1||pos>size)return -1;
       int cnt=1;
       Node* temp =head;
       while (cnt!=pos)
       {
         temp=temp->next;
         cnt++;
       }
       return temp->data;
    }



};

class Stack1{
    LinkedList1 list;
public:
    void push(char val){
        list.insert_front(val);
    }


    char pop(){
        if(!isEmpty()){
        char val =list.get_pos(1);
        list.delete_front();
        return val;
        }
        return 0;
    }

    char peek(){
       if(!list.isEmpty()){return list.get_pos(1);}
       return 0;
    }

    bool isEmpty(){
        return list.isEmpty();
    }
};

class Stack{
    LinkedList list;
public:
    void push(int val){
        list.insert_front(val);
    }


    int pop(){
        if(!isEmpty()){
        int val =list.get_pos(1);
        list.delete_front();
        return val;
        }
        return 0;
    }

    int peek(){
       if(!list.isEmpty()){return list.get_pos(1);}
       return 0;
    }

    bool isEmpty(){
        return list.isEmpty();
    }
};


bool isdigit(char c){
    if(c>='0'&&c<='9')return 1;
    return 0;
}

int  precedence(char op) {
 if (op=='^') return 3;
 if (op=='*'||op=='/') return 2;
 if (op=='+'||op=='-') return 1;
return 0;
}


string infixtopostfix(string& infix){
    Stack1 operators;
    string postfix;
   int size= infix.length();
   for (int i = 0; i < size; i++)
   {
     if(isdigit(infix[i]))postfix+=infix[i];
     else if (infix[i]=='(')operators.push(infix[i]);
     else if (infix[i]==')')
     {
        while(!operators.isEmpty()&&operators.peek()!='('){
            postfix+=operators.pop();
        }
        operators.pop();
     }   
     else{
        while(!operators.isEmpty()&&precedence(infix[i])<=precedence(operators.peek())){
           postfix+=operators.pop();
        }
        operators.push(infix[i]);
     }
   }
   while (!operators.isEmpty()){
    postfix+=operators.pop();
   }
   return postfix;
}

string infixtoprefix(string& infix){
    reverse(infix.begin(),infix.end());
    for (char& c:infix){
        if(c=='(')c=')';
        else if(c==')')c='(';
    }
    string prefix=infixtopostfix(infix);
    reverse(prefix.begin(),prefix.end());
   return prefix;
}

int oper (char op ,int a,int b){
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    if(op=='*')return a*b;
    if(op=='/')return (int)a/b;
    if(op=='^')return (int)pow(a,b);
    return 0;
}

int evaluate (string prefix){
    Stack s;
    int size=prefix.length();
    for (int i = size; i >=0; i--)
    {
       if(isdigit(prefix[i])){
         s.push(prefix[i]-'0');
       }
       else {
         int a=s.pop(),b=s.pop();
         s.push(oper(prefix[i],a,b));
       }
    }
    return s.pop();
}

int main() {
    string s="(2+3)*4";
    cout<<evaluate(infixtoprefix(s))<<endl;

}