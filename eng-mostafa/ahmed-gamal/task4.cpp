#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* reverseList(Node* head)
{
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;

    while(current!=NULL)
    {
        next=current->next;

        current->next=prev;

        prev=current;

        current=next;
    }

    return prev;
}

int main()
{
    Node* head=new Node{1,NULL};
    head->next=new Node{2,NULL};
    head->next->next=new Node{3,NULL};
    head->next->next->next=new Node{4,NULL};
    head->next->next->next->next=new Node{5,NULL};

    head=reverseList(head);

    printList(head);

    return 0;
}