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
            head=newNode;

        else
        {
            Node* temp=head;

            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newNode;
        }
    }

    Node* get_nth(int n)
    {
        Node* temp=head;
        int count=1;

        while(temp!=NULL)
        {
            if(count==n)
                return temp;

            count++;
            temp=temp->next;
        }

        return NULL;
    }
};

int main()
{
    LinkedList list;

    list.add(5);
    list.add(10);
    list.add(15);
    list.add(20);

    Node* result=list.get_nth(4);

    if(result!=NULL)
        cout<<result->data;

    return 0;
}