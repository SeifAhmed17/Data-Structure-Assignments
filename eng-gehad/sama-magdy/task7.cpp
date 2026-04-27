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
void push(char x)
{
 assert(!isfull());
 num[++top]=x;
}
int pop()
{
 assert(!isempty());
 return num[top--];
}
char peek()
{
return num[top];
}
void removstar(string str)
{
 stack s;
 for(int i=0;i<str.size();i++)
 {
 if(str[i]=='*')
  {
 s.pop();
  }
  else
  {
  s.push(str[i]);
  }
 }
string result="";
while(!s.isempty())
{
 result=s.peek()+result;
 s.pop();
}
cout<<result<<" ";
}
};
int main()
{
stack s;
string str;
cin>>str;
s.removstar(str);
return 0;
}