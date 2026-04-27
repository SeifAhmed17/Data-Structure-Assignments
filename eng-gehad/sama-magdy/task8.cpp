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
bool arepaired(char open,char close)
{
 if(open=='['&& close==']')
 return true;
 else if(open=='{'&& close=='}')
 return true;
 else if(open=='('&& close==')')
 return true;
return false;
}
bool isbalanced(string str)
{
 stack s;
 for(int i=0;i<str.size();i++)
 {
 if(str[i]=='{'||str[i]=='['||str[i]=='(')
 s.push(str[i]);
else if(str[i]=='}'||str[i]==']'||str[i]==')')
{
if(s.isempty()||!s.arepaired(s.peek(),str[i]))
return false;
else
s.pop();
}
}
if(s.isempty())
{
return true;
}
else
return false;
}
};
int main()
{
return 0;
}