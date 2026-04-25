#include <iostream>
#include <stack>
using namespace std;
/*Implementation linked list*/
class node1
{
public:
    int data;
    node1 *next;
};
class linkedlist
{
public:
    node1 *head;
    linkedlist()
    {
        head = NULL;
    }
    bool isempty()
    {
        return (head == NULL);
    }
    void insert(int item)
    {
        if (isempty())
        {
            node1 *newnode = new node1();
            newnode->data = item;
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            node1 *newnode = new node1();
            newnode->data = item;
            newnode->next = head;
            head = newnode;
        }
    }
    void append(int item)
    {
        if (isempty())
        {
            insert(item);
        }
        else
        {
            node1 *temp = head;
            node1 *newnode = new node1();
            newnode->data = item;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->next = NULL;
            temp->next = newnode;
        }
    }
    int count()
    {
        int counter = 0;
        node1 *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        return counter;
    }
    void display()
    {
        node1 *temp = head;
        for (int i = 0; i < count(); i++)
        {
            if (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
        void del(int value)
    {
        if(isempty())
        {
            cout<<"linked is empty"<<endl;
        }
        else if(head->data==value)
        {
            node1*dele=head;
            head=head->next;
            delete dele;
        }
        else 
        {
            node1*dele;
            node1*temp=head;
            while(temp->next->data!=value)
            {
                temp=temp->next;
            }
            dele=temp->next;
            temp->next=dele->next;
            delete dele;
        }
    }
    /*9-Given a sorted list of integers, remove all duplicate elements and return a list that contains only unique elements.
Ex:
Input:
n = 6
int arr[] = {1, 1, 2, 3, 3, 4}
Output:
list = [1, 2, 3, 4]
*/
    void remove_duplicates() {
    if (head == NULL) return; 
    node1* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            node1* next_node = curr->next->next;
            delete curr->next;
            curr->next = next_node;
        }
        else {
            curr = curr->next;
        }
    }
}
    /*1-task Get_nth item:
    ○ Let’s implement: Node* get_nth(int n)
    ○ The function get the nth node. If not found, it returns NULL
    ○ Below: get_nth(4) return Node with value 15  
    */
    void get_nth(int n)
    {
        node1 *temp = head;
        for (int i = 0; i < n - 1; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
    /*2-task Merge Two Sorted Lists
    You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Ex:
Input: list1 = [1,2,4], list2 = [1,3,4] Output: [1,1,2,3,4,4] 
*/
    node1*merge(node1*list1,node1*list2)
    {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        node1* result;
        if(list1->data<=list2->data)
        {
            result=list1;
            result->next=merge(list1->next,list2);
        }
        else
        {
            result=list2;
            result->next=merge(list1,list2->next);
        }
        return result;
    }
    /*3-task:Reverse linked list
    Given the head of a singly linked list, reverse the list, and return the reversed list.
    Ex:
    Input: head = [1,2,3,4,5] Output: [5,4,3,2,1] */
    void reverse()
    {
        node1*next=NULL;
        node1*curr=head;
        node1*prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    /*4-Given the head of a linked list and an integer x (0-based index),
    remove the node at position x and return the updated list.
    Ex:
    Input: list = [1,2,4] , x = 1
    Output: list = [1,4]
    */
    void remove(int p)
    {
        if(p==0)
        {
            node1*dele=head;
            head=head->next;
            delete dele;
        }
        node1 *temp=head;
        node1*deptr;
        for(int i=0;i<p-1;i++)
        {
            temp=temp->next;
        }
        deptr=temp->next;
        temp->next=temp->next->next;
        delete deptr;
        display();
    }

};
/*Implementation arr_stack*/
const int maxx = 100;
template <class t>
class arr_stack
{
private:
    int top;
    t item[maxx];

public:
    arr_stack()
    {
        top = -1;
    }
    void push(t value)
    {
        if (top >= maxx - 1)
            cout << "stack is full" << endl;
        else
        {
            top++;
            item[top] = value;
        }
    }
    bool isempty()
    {
        return top < 0;
    }
    void pop()
    {
        if (isempty())
            cout << "stack is empty" << endl;
        else
        {
            top--;
        }
    }
    void get_top(t &value)
    {
        if (isempty())
            cout << "stack is empty" << endl;
        else
        {
            value = item[top];
            cout << value << endl;
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
    /*5-Problem: Reverse a number using stack
    ● Implement a method that takes number >= 0 and reverse its 	digits using a stack
    ● int reverse_num(int num)
    ● E.g. Input: 1234, Output: 4321
    ● Find a stack-based idea
    */
    int reverse_num(int num) {
    while (num > 0) {
        push(num % 10); 
        num = num / 10; 
    }
    int reversed = 0;
    int multiplier = 1;
    while (!isempty()) {
        int d = item[top]; 
        pop();
        
        reversed = reversed + (d * multiplier); 
        multiplier = multiplier * 10;           
    }

    return reversed;
}
    void get_size()
    {
        cout << top + 1 << endl;
    }
    arr_stack copy_stack()
    {
        arr_stack copy;
        copy.top = top;
        for (int i = 0; i <= top; i++)
        {
            copy.item[i] = item[i];
        }
        return copy;
    }
    void get_string()
    {
        for (int i = 0; i <=top; i++)
        {
            cout << item[i];
        }
        cout << endl;
    }
    /*7-Task:Removing stars from a string
    You are given a string s, which contains stars *.
    In one operation, you can:
    Choose a star in s.
    Remove the closest non-star character to its left, as well as remove the star itself.
    Return the string after all stars have been removed.
    Ex:
    Input: s = "leet**cod*e" Output: "lecoe"
    */
    void remove_stars(string s)
    {
        stack<char> result;
        for (char n : s)
        {
            if (n == '*')
                result.pop();
            else
                result.push(n);
        }
        result.get_string();
    }
};
    /*6-Given a sorted list of integers, remove all duplicate elements and return a list that contains only unique elements.
    Ex:
    Input:
    n = 6
    int arr[] = {1, 1, 2, 3, 3, 4}
    Output:
    list = [1, 2, 3, 4]
    */
    bool arepair(char open,char close)
    {
        if(open=='('&&close==')')return true;
        else if(open=='{'&&close=='}')return true;
        else if(open=='['&&close==']')return true;
        return false;
    }
    bool balance(string exp)
    {
        stack<char>s;
        for(int i=0;i<exp.length();i++)
        {
            if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            {
                s.push(exp[i]);
            }
            else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
            {
                if(s.empty()||!arepair(s.top(),exp[i]))
                {
                    return false;
                }
                else 
                s.pop();
            }
        }
        return s.empty();
    }
    
    /*10-queue with using two stack*/
class queue
{
    stack<int>s1,s2;
    public:
    void enqueue(int item)
    {
        s1.push(item);
    }
    void dequeue()
    {
        if(s1.empty()&&s2.empty())
        {
            cout<<"the queue is empty...\n";
            return;
        }
        if (s2.empty()) 
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    void get_top()
    {
        if(s1.empty()&&s2.empty()) 
        {
            cout<<"queue is empty...\n";
            return;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<s2.top()<<"\n";
    }
};
int precedence(char k)
{
    if (k == '+' || k == '-')
        return 1;
    if (k == '/' || k == '*')
        return 2;
    return 0;
}
/*implementation queue with linked list*/
class linked_queue
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *front;
    node *rear;
    int length;

public:
    linked_queue()
    {
        rear = front = NULL;
        length = 0;
    }
    bool isempty()
    {
        return length == 0;
    }
    void enqueue(int value)
    {
        if (isempty())
        {
            front = new node;
            front->item = value;
            front->next = NULL;
            rear = front;
            length++;
        }
        else
        {
            node *newnode = new node;
            newnode->item = value;
            newnode->next = NULL;
            rear->next = newnode;
            rear = newnode;
            length++;
        }
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty..." << endl;
        }
        else
        {
            node *temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    }
    /*11Problem 1: Check if a Number Exists 
    Write a function to return true if the given Number Exists else false.
     */
    bool isfound(int value)
    {
        bool found = false;
        node *temp = front;
        while (temp != NULL)
        {
            if (temp->item == value)
            {
                found = true;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        return found;
    }
    /*12problem 2:Check Palindrome
    Check whether the queue elements form a palindrome.
Example: Queue [1, 2, 3, 2, 1] → Palindrome
*/
    bool ispalindrome()
    {
        if(isempty())
        {
            return true;
        }
        else
        {
            stack<int>s;
            node*temp=front;
            while(temp!=NULL)
            {
                s.push(temp->item);
                temp=temp->next;
            }
            temp=front;
            while(temp!=NULL)
            {
                if(temp->item!=s.top())
                {
                    return false;
                }
                s.pop();
                temp=temp->next;
            }
            return true;
        }
    }
    /*13Task: Rotate the linked list by k positions.
    You are given a queue implemented using a singly linked list. Your task is to rotate the queue by k positions.
    Rotating the queue by k positions means moving the first k elements from the front of the queue to the rear, in the same order.
    Ex:
    Size : 5
    Elements :1 2 3 4 5
    K:2
    Output: 3 4 5 1 2
    */
    void rotate(int k)
    {
        if(isempty()||k<=0||k%length==0)
        {
            return;
        }
        k=k%length;
        for(int i=0;i<k;i++)
        {
            enqueue(front->item);
            dequeue();
            
        }
    }
};
int main()
{

}