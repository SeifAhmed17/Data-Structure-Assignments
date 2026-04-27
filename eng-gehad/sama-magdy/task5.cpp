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
int reverseanum(int num)
{
stack s;
while(num)
{
s.push(num%10);
num/=10;
}
int re=1;
while(!s.isempty())
{
num=s.pop()*re+num;
re*=10;
}
return num;
}
};
int main()
{
stack s;
int n;
cin>>n;
cout<<s.reverseanum(n);
return 0;
}