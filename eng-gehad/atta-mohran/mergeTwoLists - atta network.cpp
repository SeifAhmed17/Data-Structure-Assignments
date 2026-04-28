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
};
    Node * merge(Node*head1,Node*head2){
        if (head1==NULL)
        {
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        Node * result = NULL;
        if (head1->data<=head2->data)
        {
             result = head1;
             result->next = merge(head1->next,head2);
        }else
        {
            result = head2;
            result->next = merge(head1,head2->next);
        }
        return result;
    }
    

int main (){
    LinkedList l1;
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    LinkedList l2;
    l2.append(4);
    l2.append(6);
    l2.append(7);
    l2.append(8);
    // l1.print();
    // l2.print();
    merge(l1.head,l2.head);
    l1.print();
}