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
Node*Merged(Node*head1,Node*head2)
{
if(head1==NULL)return head2;
if(head2==NULL)return head1;
Node*result=NULL;
if(head1->data<=head2->data)
{
result=head1;
result->next=Merged(head1->next,head2);
}
else{
result=head2;
result->next=Merged(head1,head2->next); 
}
return result;
}
void display(Node*Merged_list)
{
Node*Temp=Merged_list;
while(Temp!=NULL)
{
cout<<Temp->data<<" ";
Temp=Temp->next;
}
}
};
int main()
{
int n;
int m;
cout<<"enter the numbers of elementst to lst1: ";
cin>>n;
cout<<"enter the numbers of elementst to lst2: ";
cin>>m;
linked_list lst1,lst2;
for(int i=0;i<n;i++)
{
int x;
cout<<"enter the elements to lst1: ";
cin>>x;
lst1.insert(x);
}
for(int i=0;i<m;i++)
{
int y;
cout<<"enter the elements to lst2: ";
cin>>y;
lst2.insert(y);
}
linked_list M;
Node*merge=M.Merged(lst1.head,lst2.head);
M.display(merge);
return 0;
}