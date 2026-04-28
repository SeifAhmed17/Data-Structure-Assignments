#include <iostream>
using namespace std;
class Node {
    public:
    Node*next;
    Node*prev;
    int data;

};
class LinkedList {
    
    public:
        Node*head;
        Node*tail;
        bool isEmpty(){
            return (head == NULL)&&(tail== NULL); 
        }
    LinkedList(){
        head=tail=NULL;
    }
    void append(int data){
        Node *newNode = new Node;
        newNode->data = data;
        if(isEmpty()){
            head = tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void print(){
        Node * ptr;
        ptr= head;
        while (ptr!=NULL)
        {
            cout<<ptr->data<<"  ";
            ptr=ptr->next;
        }
        cout<<endl;
        delete ptr;
    }
    void remove(int item){
        Node*temp = head;
        if (temp==NULL)
        {
            return;
        }
        
        if (head!=NULL&&tail!=NULL&&head==tail)
        {
            temp = head;
            head=tail=NULL;
            delete temp;
            return;
        }
        
        while (temp->data!=item&&temp!=NULL)
        {
            temp = temp->next;
        }
        if(temp==NULL){
            return;
        }
        if(temp==head){
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return;
        }
        if (temp==tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        
    }
};
int main (){
    LinkedList l1;
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.print();
    l1.remove(5);  
    l1.print();

}