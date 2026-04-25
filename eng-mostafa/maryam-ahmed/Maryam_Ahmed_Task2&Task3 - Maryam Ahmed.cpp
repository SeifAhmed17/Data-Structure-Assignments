#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
// Task(1)- Infix to Prefix
class MyStack{
    private:
    struct node
    {
        char val;
        node*next;
    };
    int length=0;
    public:
    node*head=NULL;
    void push(char val)
    {
        node*newnode=new node;
        newnode->val=val;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
            length++;
        }
        else
        {
            node*current=head;
            head=newnode;
            newnode->next=current;
            length++;
        }
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"stack is empty\n";
        }
        else
        {
            node*current=head;
            head=head->next;
            delete(current);
            length--;
        }
    }
    bool empty() 
    {
        return head == NULL;
    }
    char top() 
    {
        return head->val;
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"stack is empty\n";
        }
        else
        {
            int a=length;
            node*current=head;
            while(a--)
            {
                cout<<current->val<<" ";
                current=current->next;
            }
            cout<<endl;
        }
    }
    
};
int pirority(char ch)
{
    if(ch=='+'||ch=='-')return 1;
    if(ch=='*'||ch=='/')return 2;
    if(ch=='^')return 3;
    return 0;
}
string prefix(string s)
{
    string s2="";
    MyStack op;
    for(int i=s.length()-1; i>=0;i--)
    {
        if(isalnum(s[i]))
        {
            s2+=s[i];
        }
        else if(s[i]==')')
        {
            op.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(!op.empty()&&op.top()!=')')
            {
                s2+=op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while(!op.empty()&&pirority(op.top())>=pirority(s[i]))
            {
                s2+=op.top();
                op.pop();
            }
            op.push(s[i]);
        }

    }
    while(!op.empty()) {
        s2 += op.top();
        op.pop();
    }
    reverse(s2.begin(),s2.end());
    return s2;
}
int result(string s2)
{
    stack<int>num;
    int a=0;
    int b=0;
    int result=0;
    for(int i=s2.length()-1;i>=0;i--)
    {
        if(isalnum(s2[i]))
        {
            num.push(s2[i]-'0');
        }
        else
        {
            a=num.top();
            num.pop();
            b=num.top();
            num.pop();
            if(s2[i]=='+')result=a+b;
            if(s2[i]=='-')result=a-b;
            if(s2[i]=='*')result=a*b;
            if(s2[i]=='/')result=a/b;
            num.push(result);
        }

    }
    return num.top();
}
// ------------------------------------------------------------

// Task(2)- Queue using Two Stacks
class queue
{
    private:
    stack<int>s1;
    stack<int>s2;
    public:
    void enqueue(int val)
    {
        if(s1.empty())
        {
            s1.push(val);
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    void dequeue()
    {
        if(s1.empty())
        {
            cout<<"queue is empty\n";
        }
        else
        {
            s1.pop();
        }
    }
    void display()
    {
        if(s1.empty())
        {
            cout<<"queue is empty\n";
        }
        else
        {
            stack<int>temp=s1;
            while(!temp.empty())
            {
                cout<<temp.top()<<" ";
                temp.pop();
            }
            cout<<endl;
        }
    }
};
int main()
{
    // Task(1)- Infix to Prefix
    string s="(2+3)*4";
    string s2=prefix(s);
    cout<<"prefix is: "<<s2<<endl;
    cout<<"result = "<<result(s2)<<endl;
    // -------------------------------------------------------
    // Task(2)- Queue using Two Stacks
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.display();
    q1.dequeue();
    q1.display();
    return 0;
}