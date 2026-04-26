#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head=NULL;
    }

    void add(int value)
    {
        Node* newNode=new Node();

        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
        }
    }

    void print1()
    {
        for(Node* temp=head ; temp!=NULL ; temp=temp->next)
        {
            cout<<temp->data<<" ";
        }
    }
};

int main()
{
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.print1();

    return 0;
}