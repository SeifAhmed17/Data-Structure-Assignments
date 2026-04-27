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
int getnth(int nth)
{
int n=0;
Node*Temp=head;
while(Temp!=NULL)
{
n++;
if(n==nth)
{
return Temp->data;
}
Temp=Temp->next;
}
}
};
int main()
{
int n;
cout<<"enter the numbers of elements: ";
cin>>n;
linked_list lst;
for(int i=0;i<n;i++)
{
int x;
cout<<"enter a num iwill put into lst: ";
cin>>x;
lst.insert(x);
}
int num;
cout<<"enter the number you want to take: ";
cin>>num;
cout<<lst.getnth(num);
return 0;
}