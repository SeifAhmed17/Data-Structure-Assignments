#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
class linked
{
    Node* head = NULL;
public:
    void insertend(int value)
    {
        Node* newnode = new Node();
        newnode->data = value;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void delete_first()
    {
        if(head == NULL) return;
        Node* del = head;
        head = head->next;
        delete del;
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool isFound(int x)
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->data == x) return true;
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
linked l;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
int val;
cin>>val;
l.insertend(val);
}
l.display();
int t;
cout<<"enter a value";
cin>>t;
if(l.isFound(t))
 cout << "Found" << "\n";
else
  cout << "Not Found" << "\n";
return 0;
}