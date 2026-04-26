#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct Node
{
   int data;
   Node* next;
};

class Stack
{
private:
   Node* top;

public:

Stack()
{
 top=NULL;
}

void push(int val)
{
   Node* newNode=new Node();

   newNode->data=val;
   newNode->next=top;

   top=newNode;
}

int pop()
{
   if(top==NULL)
      return -1;

   int value=top->data;

   Node* temp=top;

   top=top->next;

   delete temp;

   return value;
}

int peek()
{
   if(top==NULL)
      return -1;

   return top->data;
}

bool isEmpty()
{
   return top==NULL;
}

};



bool isOperand(char c)
{
 return(c>='0' && c<='9');
}



bool isOperator(char c)
{
 return(
 c=='+' ||
 c=='-' ||
 c=='*' ||
 c=='/' ||
 c=='^'
 );
}



int precedence(char op)
{
 if(op=='^') return 3;

 if(op=='*'||op=='/')
 return 2;

 if(op=='+'||op=='-')
 return 1;

 return 0;
}



string infixToPrefix(string infix)
{
 reverse(infix.begin(),infix.end());

 for(int i=0;i<infix.size();i++)
 {
   if(infix[i]=='(')
      infix[i]=')';

   else if(infix[i]==')')
      infix[i]='(';
 }

 Stack s;

 string postfix="";

 for(int i=0;i<infix.size();i++)
 {
   char c=infix[i];

   if(isOperand(c))
      postfix+=c;

   else if(c=='(')
      s.push(c);

   else if(c==')')
   {
      while(s.peek()!='(')
         postfix+=char(s.pop());

      s.pop();
   }

   else
   {
      while(!s.isEmpty() &&
      precedence(s.peek())>=precedence(c))
      {
         postfix+=char(s.pop());
      }

      s.push(c);
   }

 }

 while(!s.isEmpty())
   postfix+=char(s.pop());

 reverse(postfix.begin(),postfix.end());

 return postfix;
}



int applyOp(char op,int a,int b)
{
 if(op=='+') return a+b;

 if(op=='-') return a-b;

 if(op=='*') return a*b;

 if(op=='/') return a/b;

 if(op=='^') return pow(a,b);

 return 0;
}



int evaluatePrefix(string prefix)
{
 Stack s;

 for(int i=prefix.size()-1;i>=0;i--)
 {
   if(isOperand(prefix[i]))
   {
      s.push(prefix[i]-'0');
   }

   else
   {
      int a=s.pop();
      int b=s.pop();

      s.push(
      applyOp(prefix[i],a,b)
      );
   }
 }

 return s.pop();
}



int main()
{
 string infix="(2+3)*4";

 string prefix=
 infixToPrefix(infix);

 int result=
 evaluatePrefix(prefix);

 cout<<"Infix: "<<infix<<endl;

 cout<<"Prefix: "<<prefix<<endl;

 cout<<"Value: "<<result<<endl;

 return 0;
}