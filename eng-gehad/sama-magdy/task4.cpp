#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node*next;
};
class linked
{
Node*head=NULL;
public:
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
void display()
{
Node*temp=head;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
void delbypos(int position)
{
Node*del=head;
Node*temp=head;
int pos=0;
if(position==0)
{
head=head->next;
delete del;
}
else
{
while(temp->next!=NULL&&pos<position-1)
{
temp=temp->next;
pos++;
}
del=temp->next;
temp->next=del->next;
delete del;
}
}
};
int main()
{
linked l;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
 int value;
 cin>>value;
 l.insert(value);
}
l.display();
int pos;
cout<<"enter a pos: ";cin>>pos;
l.delbypos(pos);
l.display();
return 0;
}