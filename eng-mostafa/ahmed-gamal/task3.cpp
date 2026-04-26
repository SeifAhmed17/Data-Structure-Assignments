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

Node* mergeTwoLists(Node* list1, Node* list2)
{
    Node dummy;
    Node* tail=&dummy;

    dummy.next=NULL;

    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data < list2->data)
        {
            tail->next=list1;
            list1=list1->next;
        }

        else
        {
            tail->next=list2;
            list2=list2->next;
        }

        tail=tail->next;
    }

    if(list1!=NULL)
        tail->next=list1;

    if(list2!=NULL)
        tail->next=list2;

    return dummy.next;
}

int main()
{
    Node* a=new Node{1,NULL};
    a->next=new Node{2,NULL};
    a->next->next=new Node{4,NULL};

    Node* b=new Node{1,NULL};
    b->next=new Node{3,NULL};
    b->next->next=new Node{4,NULL};

    Node* merged=mergeTwoLists(a,b);

    printList(merged);

    return 0;
}