#include <iostream>
#include <algorithm>
using namespace std ;
class Node 
{
    public:
    int data ;
    Node *next ;
};
class LinkedList 
{
    public:
    Node *head ;
    LinkedList()
    {
        head=0;
    }
    bool isEmpty()
    {
        if (head==0)
            return true ;
        else 
            return false ;
    }
    void InsertFirst(int newitem)
    {
        if (isEmpty())
        {
        Node *newnode = new Node () ;
        newnode->data= newitem;
        newnode->next= 0 ;
        head=newnode ;
        }
        else 
        {
        Node *newnode= new Node() ;
        newnode->data=newitem ;
        newnode->next=head;
        head=newnode ;
        }
    }
    int count ()
    {
        int counter=0 ;
        Node *temp=head ;
        while(temp!=0)
        {
            counter++ ;
            temp=temp->next ;
        }
        return counter ;
    }
//ASS1 section2
//##############################ASS1 section2 ##################
    void print () 
    {    
        for( Node *temp =head ; temp!=0 ; temp=temp->next) 
        {
            cout << temp->data <<" ";
        }
        cout << endl ;
    }

    //##############################Task1######################################
    //task Get_nth item
    Node* get_nth(int pos) 
    {
        int counter=1 ;
        Node*temp=head ;
        while(temp!=NULL)
        {
            if(counter==pos)
            return temp ;
       
            temp=temp->next ;
            counter++ ;

        }
        return NULL ;
    }

    //##############################Task2######################################
    //Merge Two Sorted Lists

    Node* Merge(Node* a, Node* b)  
    {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result = NULL;

    if (a->data <= b->data)
    {
    result = a;
    result->next = Merge(a->next, b);
    }
    else 
    {
    result = b;
    result->next = Merge(a, b->next);
    }
    return result;
    }
        
    //##############################Task3######################################
    //Reverse linked list
    
    void reverse () 
    {
        Node *prev , *next, *curr ;
        prev=NULL;
        curr=head ;
        next=curr->next ;
        while(next!=NULL)
        {
        next=curr->next ;
        curr->next=prev ;
        prev=curr;
        curr=next;
        }
    head=prev ;
    }

//##############################Task4######################################
//remove the node at position x and return the updated list.

Node* deletItem(int pos)
{
    if (isEmpty())
    {
        cout << "error" << endl;
        return head;
    }
    if (pos == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    int counter = 0;

    while (curr != NULL)
    {
        if (counter == pos)
        {
            prev->next = curr->next;
            delete curr;
            return head;
        }

        prev = curr;
        curr = curr->next;
        counter++;
    }

    cout << "invalid position" << endl;
    return head;
}


//##############################Task9######################################
//Given a sorted list of integers, remove all duplicate elements and return a list that contains only unique elements.

void removeDuplicates()
{
    if (head == NULL) return;

    Node* curr = head; 
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)   
        {
            Node* temp = curr->next; 
            curr->next = curr->next->next;    
            delete temp;
        }
        else
        {
            curr = curr->next;      
        }
    }
}

};
//##############################Task8######################################
//Implement a stack data structure using an array

const int N=100 ;
template<class t>
class Stack 
{
    int top ;
    t item[N] ;
    public :
    Stack() :top(-1) {}
    void push(t elemnt)
    {
        if (top>=N-1)
        {
            cout<< "stack full" << endl ;
        }
        else 
        {
            top++;
            item[top]=elemnt;
        }
    }
    //ASS 3 size of stack 
    //###################### section 3 ASS 3 #####################
    int sizeofStack()
    {
        return top+1;
    }
    bool isEmpty()
    {
        return top<0 ;
    }

    t pop()
    {
        t dlElement;
        if(isEmpty())
        {
            cout << "stack empty" << endl;
            return t();
        }
        else 
        {
            dlElement =item[top];
            top-- ;
            return dlElement ;
        }
        
    }

    t peek ()
    {
        t stackTop;
        if (isEmpty())
        {
            cout<<"error" <<endl ;
            return t() ;
        }
        else 
        {
            stackTop=item[top];
            return stackTop;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout<<"stack empty for print" <<endl ;
            return;
        }
        for (int i=top;i>=0;i--)
        {
            cout<<item[i] << " " ;
        }
        cout << endl ; 
    }
} ;


//##############################Task5######################################
//Reverse a number using stack
int ReverseNum(int num)
{
    Stack<int> stack1 ;

    if(num==0)
        return 0;
    
    while (num)
    {
        stack1.push(num%10);
        num/=10;
    }

    int tens=1 ;
    while(!stack1.isEmpty())
    {
        num=stack1.pop() *tens +num ;
        tens*=10;
    }
    return num;
    
}

//##############################Task6######################################
//Valid Parentheses
bool arePair (char open , char close )
{
    if(open=='(' && close==')')
        return true ;
    else if (open=='{' && close=='}')
        return true ;
    else if (open=='[' && close==']')
        return true ;
    else 
        return false ;
}
bool isValied (string exp)
{
    Stack <char> s ;
     for ( size_t i=0;i<exp.length() ; i++)
     {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
            s.push(exp[i]) ;
        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
                if( s.isEmpty() || !arePair (s.peek() , exp[i]))
                    return false ;
                else 
                    s.pop() ;
            }
     }
     return s.isEmpty();
}

//##############################Task7######################################
//Removing stars from a string
string RemoveStar(string exp)
{
    string final="";
    Stack <char> s;
    for(int i=0 ; i<exp.length() ; i++)
    {
        if(exp[i]!='*')
        {
            s.push(exp[i]) ;
        }
        else if (exp[i]=='*')
        {
            if(!s.isEmpty())
            s.pop() ;
        }
    }
    while(!s.isEmpty())
    {
        final=s.peek()+final;
        s.pop() ; 
    }

    return final ;
}

//##############################Task10######################################
//: Queue using 2 Stacks: 
class queueUsingTwoStacks
{
    Stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() 
    {
        if (s2.isEmpty()) 
        {
            while (!s1.isEmpty()) 
            {
                s2.push(s1.peek());
                s1.pop();
            }
        }

        if (s2.isEmpty()) 
        {
            return -1; 
        }

        int topVal = s2.peek();
        s2.pop();
        return topVal;
    }
};

class QueueNormal
{
    public :
    Node *front ;
    Node *rear ;

    QueueNormal() {front=rear=NULL;}

    bool isEmpty()
    {
        if(front==NULL && rear==NULL)
            return true ;
        else
            return false ;
    }

void EnqueueNormal (int item)
{
    Node *newnode = new Node();
    newnode->data = item;
    if(isEmpty())
    {
        front = newnode;
        front->data=item;
        front->next=NULL;
        rear=front;

    }
    else 
    {
        newnode->data=item;
        newnode->next=NULL;
        rear->next=newnode;
        rear = newnode;
    }
} 
int DequeueNormal()
{
    int delvalue=-1 ;
    if(isEmpty())
    {
        cout << "queue empty" << endl;
        return -1;
    }
    else
    {
        if(front==rear)
        {
            delvalue = front->data;
            delete front;
            front = rear = NULL;
        }
        else 
        {
            Node*dlptr=front ;
            front=front->next;
            dlptr->next=NULL;
            delvalue=dlptr->data;
            delete dlptr;
        }
       return delvalue;
    }
}
void display()
{
    Node *curr=front;
    while(curr!=NULL)
    {
        cout<<curr->data<<" " ;
        curr=curr->next;
    }
    cout<<endl ;
}
int getfront()
{
    if(isEmpty())
    {
        cout << "queue empty" << endl;
        return -1;
    }
    return front->data;
}
//##############################Task11######################################
//Check if a Number Exists 
bool search(int item)
{
    Node*temp=front ;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            return true ;
        }
        temp=temp->next ;
    }
    return false ;
}

//##############################Task13######################################
//Rotate the linked list by k positions
void rotate(int k)
{
    if (isEmpty() || k == 0)
        return;

    for (int i = 0; i < k; i++)
    {
        int val = DequeueNormal();  
        EnqueueNormal(val);         
    }
}

};
//##############################Task12######################################
//Check whether the queue elements form a palindrome.

bool isPalindrome(QueueNormal q)
{
    Stack<int> s;
    QueueNormal temp;

    while (!q.isEmpty())
    {
        int val = q.getfront();
        temp.EnqueueNormal(val);
        s.push(val);
        q.DequeueNormal();
    }

    while (!temp.isEmpty())
    {
        if (temp.getfront() != s.peek())
            return false;

        temp.DequeueNormal();
        s.pop();
    }

    return true;
}



//ASS 2 copy stack 
//###################### section 3 ASS 2 #####################
Stack<int> copyStack(Stack<int> original) 
{
    Stack<int> temp, copy;

    while (!original.isEmpty()) 
    {
        temp.push(original.peek());
        original.pop();
    }

    while (!temp.isEmpty())
    {
        copy.push(temp.peek());
        temp.pop();
    }

    return copy;
}




//###########################infix to prefix############################
//ASS2 
int precedence(char c) 
{
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPrefix(string s) 
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')') 
            s[i] = '(';
    }

    Stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) 
        {
            result += c;
        }

        else if (c == '(') 
        {
            st.push(c);
        }

        else if (c == ')') 
        {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.peek();
                st.pop();
            }
            st.pop();
        }

        else 
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) 
    {
        result += st.peek();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int evaluatePrefix(string exp) {

    Stack<int> st;

    for (int i = exp.length() - 1; i >= 0; i--) {

        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            int a = st.peek(); st.pop();
            int b = st.peek(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.peek();
}









int main()
{
    LinkedList l1 ;
    l1.InsertFirst(5);
    l1.InsertFirst(3);
    l1.InsertFirst(1);
    l1.print();
    Node* res = l1.get_nth(2);
    if (res != NULL)
        cout << res->data << endl;
    else
        cout << "Not found" << endl;
    LinkedList l2 ;
    l2.InsertFirst(6);
    l2.InsertFirst(4);
    l2.InsertFirst(2);
    l2.print();
    l1.head=l1.Merge(l1.head,l2.head);
    l1.print() ;

    LinkedList l3;
    l3.InsertFirst(4);
    l3.InsertFirst(2);
    l3.InsertFirst(1);
    l3.print();
    l3.deletItem(1) ;
    cout << "after"<<endl;
    l3.print();


    Stack <int> st ;
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    st.pop();
    st.print() ;
    int x=st.pop() ;
    cout << x << endl ;
    st.print();


    cout<<"##############reverse number##################" <<endl;
    int num=1234 ;
    int num2=ReverseNum(num) ;
    cout << "num after reverse " << num2 << endl;


    /*string expression ;
    cout<<"Enter Expression " <<endl ;
    cin>> expression ;
    cout<<RemoveStar(expression) <<endl;*/



   /*string expression2 ;
    cout << "Enter an Expression \n" ;
    cin >> expression2 ;
    if (isValied(expression2))
        cout << "Valied " <<endl ;
    else 
        cout << "inValied "<<endl ;*/

    
    
    LinkedList l;
    int arr[] = {1, 1, 2, 3, 3, 4}; 
    int n = 6;
    for (int i = n - 1; i >= 0; i--)
    {
        l.InsertFirst(arr[i]);   
    }

    cout << "Before: ";
    l.print();

    l.removeDuplicates(); 

    cout << "After: ";
    l.print();


    queueUsingTwoStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 

    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl;

    cout << q.dequeue() << endl;

cout<<"##############################################" <<endl ;
QueueNormal newq;
newq.EnqueueNormal(10);
newq.EnqueueNormal(20);
newq.EnqueueNormal(30);
newq.EnqueueNormal(40);
newq.display() ;
newq.DequeueNormal();
newq.display();
newq.EnqueueNormal(70);
newq.display();
newq.DequeueNormal() ;
newq.display() ;
cout<<newq.getfront()<<endl;
newq.rotate(2) ;
newq.display() ;

cout<< "###################################################" <<endl;
QueueNormal q2;
q2.EnqueueNormal(1); q2.EnqueueNormal(2); q2.EnqueueNormal(3); q2.EnqueueNormal(2); q2.EnqueueNormal(1);

    if (isPalindrome(q2))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

cout<< "###################################################" <<endl;
QueueNormal LQ ;
LQ.EnqueueNormal(1);LQ.EnqueueNormal(2);
LQ.EnqueueNormal(3);LQ.EnqueueNormal(4);
LQ.EnqueueNormal(5);
LQ.display();
LQ.rotate(2);
LQ.display();


cout<< "######################### for search ##########################" <<endl;

QueueNormal forsearch ;
forsearch.EnqueueNormal(10);
forsearch.EnqueueNormal(20);
forsearch.EnqueueNormal(30);
if(forsearch.search(50))
{
    cout << "found" <<endl;
}
else 
{
    cout<<"not found " <<endl ;
}





cout<< "###################################################" <<endl;

Stack<int> ss;
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);

    Stack<int> newStack = copyStack(ss);
    
    while (!newStack.isEmpty()) 
    {
        cout << newStack.peek() << " ";
        newStack.pop();
    }



string infix;
    cout << "Enter Infix: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Prefix: " << prefix << endl;

    cout << "Value: " << evaluatePrefix(prefix) << endl;

}