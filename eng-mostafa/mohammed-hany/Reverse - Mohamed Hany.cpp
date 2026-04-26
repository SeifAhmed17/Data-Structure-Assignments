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
    LinkedList reverse(){
        LinkedList temp;
        if (head==NULL)
        {
            return temp;
        }
        
        Node * ptr;
        ptr=tail;
        while (ptr!=NULL)
        {
            temp.append(ptr->data);
            ptr= ptr->prev;
        }
        return temp;
        
    }
};
int main (){
    LinkedList l1;
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    LinkedList l2 =  l1.reverse();
    l2.print();
}