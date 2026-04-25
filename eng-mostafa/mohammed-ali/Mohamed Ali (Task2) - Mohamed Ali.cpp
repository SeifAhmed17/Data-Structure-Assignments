#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
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

class Queue {
    Stack s;
    Stack s1;
public:
    void enqueue (int val){
      s.push(val);
    }
;
    int dequeue(){
    if(!s.isEmpty()||!s1.isEmpty()){
       if(s1.isEmpty()){
         while (!s.isEmpty()){
            s1.push(s.pop());
         }
       }
    }
    return s1.pop();
}
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

}


