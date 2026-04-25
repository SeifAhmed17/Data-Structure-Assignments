#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
//------------------------------(SEC ONE TASKS)------------------------------
// linked list basics:
class linkedlist
{
    private:
    struct node
    {
        int data;
        node*next;
    };
    int length=0;
    public:
    node*head=NULL;
    node*tail=NULL;
    void addnode(int val)
    {
        node*newnode=new node;
        newnode->data=val;
        if(head==NULL)
        {
            head=tail=newnode;
            newnode->next=NULL;
            length++;
        }
        else
        {
            tail->next=newnode;
            tail=tail->next;
            newnode->next=NULL;
            length++;
        }
    }
    void deletenode()
    {
        if(head==NULL)
        {
            cout<<"linked list is empty\n";
        }
        else if(head->next==NULL)
        {
            node*current=head;
            delete(current);
            head=tail=NULL;
            length--;
        }
        else
        {
            node*current=head;
            while(current->next!=tail)
            {
                current=current->next;
            }
            node*deleteval=tail;
            tail=current;
            delete(deleteval);
            tail->next=NULL;
            length--;
        }
    }
    void display()
    {
        int a=length;
        node*current=head;
        while(a--)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    void delete_front()
    {
        if(head==NULL)
        {
            cout<<"linked list is empty\n";
        }
        else if(head->next==NULL)
        {
            node*current=head;
            delete(current);
            head=NULL;
            length--;
        }
        else
        {
            node*current=head;
            head=head->next;
            delete(current);
            length--;
        }
    }
    // -------------------------------------------------------------------
    // Task one (Rewrite the print1 function using for loop):
    void print()
    {
        if(head==NULL)
        {
            cout<<"linked list is empty\n";
        }
        else
        {
            node*current=head;
            for(int i=length;i>0;i--)
            {
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }
    }
    // ---------------------------------------------------------------------
    // Task two (get_nth item):
    void getnode(int index)
    {
        int a=index-1;
        node*current=head;
        while(a--)
        {
            current=current->next;
        }
        cout<<"The "<<index<<"th value is: "<<current->data<<endl;
    }
    // ---------------------------------------------------------------------
    // Task three (merge two sorted lists):
    void addnode(node*&head , int val)
    {
        node*newnode=new node;
        newnode->data=val;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            node*current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next=newnode;
            newnode->next=NULL;
        }
    }
    void merge(node*&h1 , node*&h2 ,node*&h3)
    {
        node*c1=h1;
        node*c2=h2;
        while(c1!=NULL && c2!=NULL)
        {
            if(c1->data<=c2->data)
            {
                addnode(h3,c1->data);
                c1=c1->next;
            }
            else if(c2->data<c1->data)
            {
                addnode(h3,c2->data);
                c2=c2->next;
            }
        }
        while(c1!=NULL)
        {
            addnode(h3,c1->data);
            c1=c1->next;
        }
        while(c2!=NULL)
        {
            addnode(h3,c2->data);
            c2=c2->next;
        }
        
    }
    void display_merged_list(node*&head)
    {
        if(head==NULL)
        {
            cout<<"merged list is empty\n";
        }
        else
        {
            node*current=head;
            while(current!=NULL)
            {
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }
    }
    // ---------------------------------------------------------------------
    // Task four (reverse linked list):
    void reversenode(node*head)
    {
        if(head==NULL)
        {
            return;
        }
        reversenode(head->next);
        cout<<head->data<<" ";
    }
    // ---------------------------------------------------------------------
    // Task one (remove node in a specific index):
    void remove_index(int index)
    {
        if(head==NULL)
        {
            cout<<"linked list is empty\n";
        }
        else if(index==length-1)
        {
            deletenode();
        }
        else if(index==0)
        {
            delete_front();
        }
        else
        {
            node*current=head;
            int a=index-1;
            while(a--)
            {
                current=current->next;
            }
            node*deletedval=current->next;
            current->next=deletedval->next;
            delete(deletedval);
        }
    }
};
//------------------------------(SEC TWO TASKS)------------------------------
    // Task one (reverse a number using stack):
    int reverse_num(int num)
    {
        stack<int>s;
        int result=0;
        int i=1;
        while(num>0)
        {
            s.push(num%10);
            num/=10;
        }
        while(!s.empty())
        {
            result+=s.top()*i;
            s.pop();
            i*=10;
        }
        return result;
    }
    // ---------------------------------------------------------------------
    // Task two (valid parentheses):
    bool ispair(char c1,char c2)
    {
        if(c1=='(' && c2==')') return 1;
        if(c1=='{' && c2=='}') return 1;
        if(c1=='[' && c2==']') return 1;
        else return 0;
    }
    string valid_parentheses(string s)
    {
        stack<char>s2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                s2.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(s2.empty())
                {
                    return "Invalid\n";
                }
                else if(ispair(s2.top(),s[i]))
                {
                    s2.pop();
                }
                else
                {
                    return "Invalid\n";
                }
            }
        }
        return s2.empty() ? "Valid\n" : "Invalid\n";
    }
    // ---------------------------------------------------------------------
    // Task three (remove stars from string):
    string remove_star(string st)
    {
        stack<char>s;
        string s2;
        for(int i=0; i<st.length(); i++)
        {
            if(st[i] !='*')
            {
                s.push(st[i]);
            }
            else 
            {
                if(s.empty())
                {
                    continue;
                }
                else
                {
                    s.pop();
                }
            }
        }
        if(s.empty())
        {
            return "string has been removed";
        }
        else
        {
            while(!s.empty())
            {
                s2+=s.top();
                s.pop();
            }
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
    // ---------------------------------------------------------------------
    // Task four (stack using array):
    const int max_size=100;
    class my_stack
    {
        private:
        int top;
        int items[max_size];
        public:
        my_stack():top(-1){}
        void pop()
        {
            if(top==-1)
            {
                cout<<"stack is empty\n";
            }
            else
            {
                cout<<"Top is: "<<items[top]<<endl;
                top--;
            }
        }
        void peek()
        {
            if(top==-1)
            {
                cout<<"stack is empty\n";
            }
            else
            {
                cout<<"Top is: "<<items[top]<<endl;
            }
        }
        bool isEmpty()
        {
            return top==-1;
        }
    };
    // ---------------------------------------------------------------------
    // Task five (remove duplicate):
    void remove_duplicate(int a[] , int size )
    {
        linkedlist l1;
        l1.addnode(a[0]);
        for(int i=1;i<size;i++)
        {
            if(a[i]==l1.tail->data)
            {
                continue;
            }
            else
            {
                l1.addnode(a[i]);
            }
        }
        l1.display();
    }
    // ---------------------------------------------------------------------
   //------------------------------(SEC Three & four TASKS)------------------------------
   // Task(1)- Infix to Prefix
    class MyStack
    {
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
class MyQueue
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
//------------------------------(SEC Five TASKS)------------------------------
// Task basic:
class linked_queue
{
    private:
    struct node
    {
        int data;
        node*next;
    };
    int length=0;
    public:
    node*front=NULL;
    node*rear=NULL;
    void enqueue(int val)
    {
        node*newnode=new node;
        newnode->data=val;
        if(length==0)
        {
            front=rear=newnode;
            newnode->next=NULL;
            length++;
        }
        else
        {
            rear->next=newnode;
            rear=rear->next;
            newnode->next=NULL;
            length++;
        }
    }
    void dequeue()
    {
        if(length==0)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            node*current=front;
            front=front->next;
            delete(current);
            length--;
        }
    }
    void display()
    {
        if(length==0)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            node*current=front;
            int a=length;
            while(a--)
            {
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }
    }
    // Task one (Check if a Number Exists):
    bool check_exist_number(int value)
    {
        bool check=false;
        if(length==0)
        {
            cout<<"queue is empty\n";
            return false;
        }
        else
        {
            node*current=front;
            int a=length;
            while(a--)
            {
                if(current->data==value)
                {
                    check=true;
                    return check;
                }
                else
                {
                    current=current->next;
                }
            }
        return check;
        }
    }
    // -----------------------------------------------------------
    // Task two (Check Palindrome):
    string palindrome()
    {
        node*current=front;
        int a=length;
        stack<int>copy;
        if(length==0)
        {
            return "queue is empty\n";
        }
        else
        {
            while(a--)
            {
                copy.push(current->data);
                current=current->next;
            }
        }
        a=length;
        current=front;
        while(a--)
        {
            if(current->data==copy.top())
            {
                current=current->next;
                copy.pop();
            }
            else
            {
                return "This queue is not palindrome\n";
            }
        }
        return "This queue is palindrome\n";
    }
    // -----------------------------------------------------------
    // Task three (Rotate the linked list by k positions):
    void rotate_queue(int k)
    {
        if(length==0)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            node*c=front;
            while(k--)
            {
                node*next_node=c->next;
                enqueue(c->data);
                dequeue();
                c=next_node;
            }
        }
    }
    // -----------------------------------------------------------
};
// -----------------------------------------------------------
int main()
{
    //------------------------------(SEC ONE TASKS)------------------------------
    // linked list basics:
    linkedlist l;
    l.addnode(1);
    l.addnode(2);
    l.addnode(3);
    l.addnode(4);
    l.addnode(5);
    // ---------------------------------------------
    // Task one (Rewrite the print1 function using for loop):
    l.print();
    cout<<"============================\n";
    // ----------------------------------------------
    // Task two (get_nth item):
    l.getnode(3);
    cout<<"============================\n";
    // ----------------------------------------------
    // Task three (merge two sorted lists):
    linkedlist l1;
    l1.addnode(1);
    l1.addnode(2);
    l1.addnode(4);
    linkedlist l2;
    l2.addnode(1);
    l2.addnode(3);
    l2.addnode(4);
    linkedlist l3;
    l3.merge(l1.head,l2.head,l3.head);
    l3.display_merged_list(l3.head);
    cout<<"============================\n";
    // ----------------------------------------------
    // Task four (reverse linked list):
    linkedlist l4;
    l4.addnode(1);
    l4.addnode(2);
    l4.addnode(3);
    l4.addnode(4);
    l4.addnode(5);
    l4.reversenode(l4.head);
    cout<<"\n============================\n";
    // ----------------------------------------------
    linkedlist l5;
    l5.addnode(1);
    l5.addnode(2);
    l5.addnode(3);
    l5.addnode(4);
    l5.addnode(5);
    l5.remove_index(2);
    l5.display_merged_list(l5.head);
    cout<<"============================\n";
    //------------------------------(SEC TWO TASKS)------------------------------
    // Task one (reverse a number using stack):
    int num=1234;
    cout<<"reversed number is: "<<reverse_num(num)<<endl;
    cout<<"============================\n";
    // ----------------------------------------------
    // Task two (valid parentheses):
    string s="{(((({{[[()]]}}))))}";
    cout<<valid_parentheses(s);
    string s2="{(((([{()}]))))";
    cout<<valid_parentheses(s2);
    cout<<"============================\n";
    // ----------------------------------------------
    // Task three (remove stars from string):
    string s3="leet**cod*e";
    cout<<remove_star(s3)<<endl;
    cout<<"============================\n";
    // ----------------------------------------------
    // Task five (remove duplicate):
    int a[6]={1,1,2,3,3,4};
    remove_duplicate(a,6);
    cout<<"============================\n";
    // ----------------------------------------------
    //------------------------------(SEC Three & four TASKS)------------------------------
    // Task(1)- Infix to Prefix
    string st="(2+3)*4";
    string st2=prefix(st);
    cout<<"prefix is: "<<st2<<endl;
    cout<<"result = "<<result(st2)<<endl;
    cout<<"============================\n";
    // -------------------------------------------------------
    // Task(2)- Queue using Two Stacks
    MyQueue q1;
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
    cout<<"============================\n";
    // -------------------------------------------------------
    //------------------------------(SEC FIVE TASKS)------------------------------
    // Task one (Check if a Number Exists):
    linked_queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.check_exist_number(4)<<endl;
    cout<<"============================\n";
    // -------------------------------------------------------
    // Task two (Check Palindrome):
    linked_queue q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(2);
    q2.enqueue(1);
    cout<<q2.palindrome();
    cout<<"============================\n";
    // -------------------------------------------------------
    // Task three (Rotate the linked list by k positions):
    linked_queue q3;
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(4);
    q3.enqueue(5);
    q3.rotate_queue(2);
    q3.display();
    cout<<"============================\n";
    return 0;
}