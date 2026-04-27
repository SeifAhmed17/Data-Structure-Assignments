#include<iostream>
#include<cassert>
using namespace std;
class stack
{
int top=-1;
int num[100];
public:
bool isfull()
{ 
return(top==99);
}
bool isempty()
{
return(top==-1);
}
void push(int x)
{
 assert(!isfull());
 num[++top]=x;
}
int pop()
{
 assert(!isempty());
 return num[top--];
}
int peek()
{
return num[top];
}
void nonrepeat(int num[],int n)
{
stack s;
stack t;
for(int i=0;i<n;i++)
{
if(s.isempty())
{
s.push(num[i]);
}
else if(!s.isempty()&&s.peek()==num[i])
{
s.pop();
s.push(num[i]);
}
else
s.push(num[i]);
}
while(!s.isempty())
{
t.push(s.pop());
}
cout<<"[";
while(!t.isempty())
{
cout<<t.peek();
t.pop();
if(!t.isempty())cout<<",";
}
cout<<"]";
}
};
int main()
{
stack s;
int n;
cin>>n;
int num[100];
for(int i=0;i<n;i++)
{
cin>>num[i];
}
s.nonrepeat(num,n);
return 0;
}