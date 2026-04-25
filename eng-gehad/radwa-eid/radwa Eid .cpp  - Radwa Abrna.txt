#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// task 1
Node* get_nth(Node* head, int n){
    int i = 0;
    while(head){
        if(i == n) return head;
        head = head->next;
        i++;
    }
    return NULL;
}

// task 2
Node* merge(Node* l1, Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->data < l2->data){
        l1->next = merge(l1->next,l2);
        return l1;
    } else {
        l2->next = merge(l1,l2->next);
        return l2;
    }
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// task 3
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// task 4
Node* removeNode(Node* head,int x){
    if(x==0) return head->next;

    Node* temp = head;
    for(int i=0;i<x-1;i++)
        temp = temp->next;

    temp->next = temp->next->next;
    return head;
}

// task 5
int reverse_num(int num){
    stack<int> s;

    while(num>0){
        s.push(num%10);
        num/=10;
    }

    int rev=0;
    while(!s.empty()){
        rev = rev*10 + s.top();
        s.pop();
    }
    return rev;
}

// task 6
bool isValid(string str){
    stack<char> s;

    for(char c : str){
        if(c=='('||c=='{'||c=='[')
            s.push(c);
        else{
            if(s.empty()) return false;

            if((c==')'&&s.top()!='(')||
               (c=='}'&&s.top()!='{')||
               (c==']'&&s.top()!='['))
                return false;

            s.pop();
        }
    }
    return s.empty();
}

// task 7
string removeStars(string s){
    stack<char> st;

    for(char c : s){
        if(c=='*') {
            if(!st.empty()) st.pop();
        }
        else st.push(c);
    }

    string res="";
    while(!st.empty()){
        res = st.top()+res;
        st.pop();
    }
    return res;
}

// task 8
class Stack{
    int arr[100];
    int top;

public:
    Stack(){ top=-1; }

    void push(int x){ arr[++top]=x; }
    int pop(){ return arr[top--]; }
    int peek(){ return arr[top]; }
    bool isEmpty(){ return top==-1; }
};

// task 9
Node* removeDuplicates(Node* head){
    Node* curr = head;

    while(curr && curr->next){
        if(curr->data == curr->next->data)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

// task 10
class Queue{
    stack<int> s1,s2;

public:
    void enqueue(int x){
        s1.push(x);
    }

    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};

// task 11
bool exists(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x) return true;
    }
    return false;
}

// task 12
bool isPalindrome(queue<int> q){
    stack<int> s;
    queue<int> temp=q;

    while(!temp.empty()){
        s.push(temp.front());
        temp.pop();
    }

    while(!q.empty()){
        if(q.front()!=s.top()) return false;
        q.pop();
        s.pop();
    }
    return true;
}

// task 13
void rotate(queue<int>& q,int k){
    int n=q.size();
    k%=n;

    for(int i=0;i<k;i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    return 0;
}
