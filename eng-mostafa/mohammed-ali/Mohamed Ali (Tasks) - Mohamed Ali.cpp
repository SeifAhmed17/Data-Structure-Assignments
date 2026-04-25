#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr) ,size(0) {}
    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
//================================================================
    bool isEmpty() {
        return head == nullptr;
    }
//================================================================

    void insert_end(int val) {
        size++;
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }


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
    void delete_end (){ 
        if(isEmpty())return;
        Node* temp =head;
        if(size==1){
            delete head;
            head=tail=nullptr;
            return;
        }
        while (temp->next!=tail)
        {
            temp=temp->next;
        }
        delete tail;
        temp->next=nullptr;
        tail=temp; 
        size--;
    }


    void delete_front(){
        if(isEmpty())return;
        Node* temp =head;
        if(size==1){
            delete head;
            head=tail=nullptr;
            size=0;
            return;
        }
        temp=head->next;
        head=temp;
        size--;
    }
//================================================================
   void clear(){
    if(isEmpty())return;
    Node* temp =head;
     Node* next;
    while (temp!=nullptr)
    {
      next=temp->next;
       delete temp;
       temp=next;
    }
    head=tail=nullptr;
    size=0;
   }
  
   int Size() {return size;}


//=======================(Task 1)=====================================
    Node* get_pos (int pos){
       if(pos<1||pos>size)return nullptr;
       int cnt=1;
       Node* temp =head;
       bool found=0;
       while (cnt!=pos)
       {
         temp=temp->next;
         cnt++;
       }
       return temp;
    }


//=======================(Task 2)=====================================
void sorted_merge(LinkedList& other) {
        LinkedList result;
        Node* ptr1 = head;
        Node* ptr2 = other.head;
        while(ptr1 != nullptr && ptr2 != nullptr) {
            if(ptr1->data < ptr2->data) {
                result.insert_end(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                result.insert_end(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 != nullptr) {
            result.insert_end(ptr1->data);
            ptr1 = ptr1->next;
        }
        while(ptr2 != nullptr) {
            result.insert_end(ptr2->data);
            ptr2 = ptr2->next;
        }
        clear();
        head = result.head;
        tail = result.tail;
        size = result.size;
        result.head = nullptr;
        result.tail = nullptr;
    }
//=======================(Task 3)=====================================
   void reverse (){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while (curr!=nullptr)
    {
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;   
    }
    swap(head,tail);
   }
//=======================(Task 4)=====================================
    void delete_at_pos (int pos){
        pos++;
        if(pos<1||pos>size)return;
        if(pos==1){delete_front();return;}
        if(pos==size){delete_end();return;}
        Node* temp =head;
        int cnt=2;
        while (cnt!=pos)
        {
          temp=temp->next;  
          cnt++; 
        }
        temp->next=temp->next->next;
        size--;
    }
//=======================(Task 11)=====================================
 bool search_val(int val){
        Node* temp =head;
        bool flag=0;
        while (temp!=nullptr)
        {
            if (temp->data==val){
                flag=1;
               break;
            } 
          temp=temp->next;  
        }
        return flag;

    }
//=======================(Task 9)=====================================
  void unique_items(){
    map<int,int>mp;
    int cnt=0;
    Node* curr = head;
        while (curr != nullptr) {
            if(mp[curr->data]==1){
                curr = curr->next;
                delete_at_pos(cnt);
            }
            else{
                cnt++;
                mp[curr->data]++;
                curr = curr->next;
            }
        }
      }
};

//=======================(Task 8)=====================================
class Stack{
   int size{};
   int top{};
   int* arr{};
   public:
   Stack(int s):size(s),top(-1){
    arr = new int[size];
   }
//================================================================
   void display(){
    if (!isEmpty())
    {
       for (int i = top; i >-1; i--)
       {
         cout<<arr[i]<<" ";
       }
       cout<<endl;
    }
   }

//================================================================
   bool isEmpty() {return top==-1;}

   bool isFull() {return top==size;}
//================================================================
   void push(int val){
    if(!isFull())arr[++top]=val;
   }


   int pop(){
    if(!isEmpty()){
      return arr[top--];
    }
    return 0; 
   }


   int peek(){
    if(!isEmpty()){
      return arr[top];
    }
    return 0 ;
   }
//================================================================
   void copy(Stack source,Stack& destination){
    Stack temp(source.size);
    while(!source.isEmpty()){
        temp.push(source.pop());
    }
     while(!temp.isEmpty()){
        destination.push(temp.pop());
    }
   }
//================================================================

      int Size(){
        return size;
    }

    // ~Stack() {
    //  delete[] arr;
    // }
};

//=======================(Task 5)=====================================
int reverse_Num(int n){
    Stack s(100);
    int tens=0,n1=0;
    while (n)
    {
       s.push(n%10);
       n/=10;
       tens++;
    }
    int i=0;
    while (i<tens)
    {
       n1+=int(pow(10,i))*s.pop();
       i++;
    }
    return n1;
}
//=======================(Task 6)=====================================
bool is_open(char c){
   if(c=='['||c=='{'||c=='(')return 1;
   return 0;
}

char open(char c){
   if (c==']')return '[';
   if (c=='}')return '{';
   if (c==')')return '(';
}

bool isvalid(string s){
    stack<char> st;
    for(char c:s){
        if(is_open(c))st.push(c);
        else{
            if(st.top()!=open(c))return 0;
            st.pop();
        }
    }
    if(!st.empty())return 0;
    return 1;
}
//=======================(Task 7)=====================================
string remove_stars(string s){
    stack<char> st;
    for (char c:s){
        if(c=='*'){
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            st.push(c);
        }
    }
    string s1;
    while(!st.empty()){
        s1+=st.top();
        st.pop();
    }
    reverse(s1.begin(),s1.end());
    return s1;
}
//=======================(Task 10)=====================================
//        I solved it in (Mohamed Ail (Task2)) file
//=======================(Task 12)=====================================
bool is_pal(queue<int>&q){
    queue<int>q1=q;
    Stack s(q.size());
    while (!q1.empty())
    {
        s.push(q1.front());
        q1.pop();
    }
    while (!s.isEmpty())
    {
        if(q.front()!=s.pop())return 0;
        q.pop();
    }
    return 1;
}
//=======================(Task 13)=====================================
class Queue{
    LinkedList list;
public:
  void enqueue(int val){
    list.insert_end(val);
  }
  int dequeue (){
    int val=list.get_pos(1)->data;
    list.delete_front();
    return val;
  }
  void rotate(int k){
    if(k==0||list.Size()==0)return;
    k%=list.Size();
    for (int i = 1; i < k; i++)
    {
       int val=dequeue();
       enqueue(val);
    }
    
  }
  void display(){
    list.printList();
  }
};




int main() {

    // LinkedList list,list1;
    // list.insert_end(1);
    // list1.insert_end(1);
    // list.insert_end(2);
    // list1.insert_end(2);
    // list.insert_end(3);
    // list1.insert_end(3);
    // list.insert_end(4);
    // list1.insert_end(4);
    // list.insert_end(5);
    // list1.insert_end(5);
    // cout<<list.get_pos(4)->data<<endl;          // output task 1
    // list1.sorted_merge(list);                   // output task 2
    // list1.printList();                          // output task 2
    // list.reverse();                             // output task 3
    // list.printList();                           // output task 3
    // list.delete_at_pos(2);                      // output task 4
    // list.printList();                           // output task 4
    // cout<<reverse_Num(1234)<<endl;              // output task 5
    // cout<<isvalid("(){}[]")<<endl;              // output task 6
    // cout<<isvalid("(][)")<<endl;                // output task 6
    // cout<<remove_stars("leet**cod*e")<<endl;    // output task 7
    // Stack st(5);
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // st.display();                                // output task 8
    // cout<<st.isEmpty()<<endl;                    // output task 8
    // list1.unique_items();                        // output task 9
    // list1.printList();                           // output task 9
    // cout<<list1.search_val(5)<<endl;             // output task 11
    // queue<int> q;                                
    // q.push(1);                                   
    // q.push(2);                                   
    // q.push(3);                                   
    // q.push(2);                                   
    // q.push(1);                                   
    // cout<<is_pal(q)<<endl;                       // output task 12 
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(3);
    // q.push(1);
    // cout<<is_pal(q)<<endl;                       // output task 12
    // Queue q1;
    // q1.enqueue(1);
    // q1.enqueue(2);
    // q1.enqueue(3);
    // q1.enqueue(4);
    // q1.enqueue(5);
    // q1.display();
    // q1.rotate(3);
    // q1.display();                                // output task 13

}