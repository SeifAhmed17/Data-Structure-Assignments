#include <iostream>
using namespace std;
class Node {
    public:
    Node*next;
    Node*prev;
    int data;

};
class LinkedList {
    private:
        Node*head;
        Node*tail;
        bool isEmpty(){
            return (head == NULL)&&(tail== NULL); 
        }
    public:
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
    int get_nth(int i ){
        Node * ptr;
        ptr= head;
        int count = -1 ;
        int value = -1;
        while (ptr!=NULL&&count!=i)
        {
            value= ptr->data;
            count++;
            ptr=ptr->next;
        }
        delete ptr;
        return value;

    }
};
int main (){
    LinkedList l1;
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.print();
    cout<<l1.get_nth(2)<<endl;
}