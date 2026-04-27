#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node*next;
};
class linked_list
{
public:
Node*head=NULL;
void insert(int data)
{
Node*newnode=new Node();
newnode->data=data;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}
void reverse(Node*Temp)
{
if(Temp==NULL)
return;
reverse(Temp->next);
cout<<Temp->data<<" ";
}
};                                                                                                                                 
int main()
{
int n;
cout<<"enter the numbers of elementst to lst1: ";
cin>>n;
linked_list lst1;
for(int i=0;i<n;i++)
{
int x;
cout<<"enter the elements to lst1: ";
cin>>x;
lst1.insert(x);
}
lst1.reverse(lst1.head);
return 0;
}