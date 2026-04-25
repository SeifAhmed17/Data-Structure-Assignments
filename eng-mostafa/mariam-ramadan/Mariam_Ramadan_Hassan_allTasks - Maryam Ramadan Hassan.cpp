// task get nth item
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
};
class linkedlist{
public:
Node*head=nullptr;
void insertitems(int item){
Node*newnode= new Node();
newnode->data=item;
newnode->next=nullptr;
if(head==nullptr)
{head=newnode;}
else{
Node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;}}
void print(){
for(Node*temp=head;temp!=nullptr;temp=temp->next)
    {cout<<temp->data<<" ";}
cout<<"\n";}
Node*get_nth(int n){
int counter=1;
Node*temp=head;
while(temp!=nullptr)
{
if(counter==n){return temp;}
temp=temp->next;
counter++;
}
return nullptr;
}

};

int main()
{
linkedlist List;
List.insertitems(6);
List.insertitems(10);
List.insertitems(8);
List.insertitems(15);
cout<<"list items is :"<<"\n";
List.print();
 Node*temp=List.get_nth(4);
if(temp!=nullptr)
{
cout<<"item number 4 is :\n"<<temp->data;
}
else
{
cout<<" the item not found"<<"\n";
}
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//task merge two sorted list
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
};
class linkedlist{
public:
Node*head=nullptr;
void insertitems_list1(int item){
Node*newnode= new Node();
newnode->data=item;
newnode->next=nullptr;
if(head==nullptr)
{head=newnode;}
else{
Node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;}}
void print_list1(){
for(Node*temp=head;temp!=nullptr;temp=temp->next)
    {cout<<temp->data<<" ";}
cout<<"\n";}



void insertitems_list2(int item){
Node*newnode= new Node();
newnode->data=item;
newnode->next=nullptr;
if(head==nullptr)
{head=newnode;}
else{
Node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;}}
void print_list2(){
for(Node*temp=head;temp!=nullptr;temp=temp->next)
    {cout<<temp->data<<" ";}
cout<<"\n";}


Node* mergeTwoLists(Node* list1, Node* list2) {
if (list1 == nullptr) return list2;

if (list2 == nullptr) return list1;

Node* head;
if (list1->data < list2->data) {
head = list1;
list1 = list1->next;
}
else {
head = list2;
list2 = list2->next;
}
Node* current = head;
while (list1 != nullptr && list2 != nullptr) {
if (list1->data < list2->data) {
current->next = list1;
list1 = list1->next;
}
else {
current->next = list2;
list2 = list2->next;
}
current = current->next;
}
if (list1 != nullptr) {
current->next = list1;
}
if (list2 != nullptr) {
current->next = list2;
}
return head;
}

};


int main()
{
linkedlist list1;
list1.insertitems_list1(1);
list1.insertitems_list1(2);
list1.insertitems_list1(4);

linkedlist list2;
list2.insertitems_list2(1);
list2.insertitems_list2(3);
list2.insertitems_list2(4);

cout << "List 1: ";
list1.print_list1();

cout << "List 2: ";
list2.print_list2();


linkedlist mergedlist;
mergedlist.head = mergedlist.mergeTwoLists(list1.head, list2.head);
cout << "Merged List: ";
mergedlist.print_list1();



return 0;
}

//////////////////////////////////////////////////////////////////////////////////
// task reverse linked list
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
};
class linkedlist{
public:
Node*head=nullptr;
void insertitems(int item){
Node*newnode= new Node();
newnode->data=item;
newnode->next=nullptr;
if(head==nullptr)
{head=newnode;}
else{
Node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;}}
void print(){
for(Node*temp=head;temp!=nullptr;temp=temp->next)
    {cout<<temp->data<<" ";}
cout<<"\n";}
void print_reversed(Node*head){
if(head==nullptr)
    return;
print_reversed(head->next);
cout<<head->data<<" ";


}


};

int main()
{
linkedlist List;
List.insertitems(6);
List.insertitems(10);
List.insertitems(8);
List.insertitems(15);
cout<<"list items is :"<<"\n";
List.print();
List.print_reversed(List.head);
return 0;
}
//////////////////////////////////////////////////////////////////
// task remove at position
#include <iostream>
using namespace std;
class Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
Node* removeAt(Node* head, int x) {
    if (head == NULL) return NULL;
    if (x == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    for (int i = 0; current != NULL && i < x - 1; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        return head;
    }
    Node* nodeToDelete = current->next;
    current->next = current->next->next;
    delete nodeToDelete;

    return head;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);

    cout << "list :"<<"\n";
    printList(head);
    head = removeAt(head, 1);

    cout << "new list:";
    printList(head);

    return 0;
}
//////////////////////////////////////////////////////////////////////
// task reverse stack
#include <iostream>
#include <stack>
using namespace std;

int reverse_num(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }

    int reversed = 0;
    int multiplier = 1;
    while (!s.empty()) {
        reversed += s.top() * multiplier;
        s.pop();
        multiplier *= 10;
    }

    return reversed;
}

int main() {
    int n = 1234;
    cout << "number: " << n << endl;
    cout << "new number: " << reverse_num(n) << endl;

    return 0;
}
////////////////////////////////////////////////////////////////////////
// task valid paranthesis
#include <iostream>
#include<stack>
#include<string>
using namespace std;
bool arepair(char open,char close){
if(open=='('&&close==')')
    return true;
else if(open=='{'&&close=='}')
    return true;
else if(open=='['&&close==']')
    return true;

return false;

}
bool arebalanced(string exp){
stack<char>s;
int length=exp.length();
for(int i=0;i<length;i++){
if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        s.push(exp[i]);
else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
{
   if(s.empty()||!arepair(s.top(),exp[i]))
       {return false;}
   else
       {s.pop();}
}
}

if(s.empty())
    return true;

}
int main()
{
string expression;
cout<<"enter an expression:"<<endl;
cin>>expression;
if(arebalanced(expression))
   {
   cout<<"balanced"<<endl;
   }
else
    {
    cout<<"not balanced";
    }

    return 0;
}
//////////////////////////////////////////////////////////////
//task removing stars
#include <iostream>
using namespace std;
const int max_size = 100;
class stack{
public:
char items[max_size];
int top=0;
char result[max_size];
stack(){
cout<<"enter your string"<<endl;
cin>>items;
}

void remove_star(){
for(int i=0;items[i]!='\0';i++){
if(items[i]=='*'){
if(top>0){
    top--;
}
}
else{
result[top]=items[i];
 top++;
}
}
result[top]='\0';
cout<<"result:"<<result<<endl;


}
};

int main()
{
stack s;
s.remove_star();

    return 0;
}
////////////////////////////////////////////////////////////////
// task stack with array
#include <iostream>
using namespace std;
const int max_size=100;
class stack{
public:
int top;
int items[max_size];
stack(){
top=-1;
}
bool isempty(){
if(top==-1)
    return true;
else
    return false;

}
void push(int value){
if(top>=max_size-1){
    cout<<"stack full on push"<<"\n";

}
top++;
items[top]=value;

}
void pop(){
if(isempty())
    cout<<"stack is empty"<<"\n";
else{
int element=items[top];
top--;
cout<<element<<"was deleted"<<"\n";
}}
void print(){
    cout<<"[";
for(int i=top;i>=0;i--){

   cout<<items[i]<<" " ;

}
cout<<"]";
cout<<"\n";

}

};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    s.pop();
    s.print();

    return 0;
}
////////////////////////////////////////////////////////////////////////////
// task remove duplicate
void removeduplicate(){
assert(!isEmpty());
Node<t> *curr=head;

while(curr&&curr->next){
    if(curr->next->data==curr->data){
        Node<t> *temp=curr->next;
        curr->next=curr->next->next;
        delete teemp;
        length--;
    }
    else{
        curr=curr->next;
    }
}

}

////////////////////////////////////////////////////////////
// task queue using 2 stacks
#include <iostream>
#include<cassert>
#include<stack>
using namespace std;
class stackqueue{
public:
stack<int> s1;
stack<int> s2;

void enqueue(int item){
s1.push(item);
cout<<"Enqueued:"<<item<<"\n";
}

int dequeue(){
if(s2.empty()){
    if(s1.empty()){
        cout<<"Queue is empty"<<"\n";
        return -1;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
int topvalue=s2.top();
s2.pop();
return topvalue;
}
}

bool isempty(){
return s1.empty()&&s2.empty();
}
};

int main()
{
stackqueue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
cout<<"Dequeued:"<<q.dequeue()<<"\n";


    return 0;
}
////////////////////////////////////////////////////////////////
// task check if number exist
bool checkNumber(int n)
    {
        queue Node<t> *temp = front;
        while (temp != NULL)
        {
            if (temp->next == n)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }

    void display()
    {
        queue Node<t> *temp = front;
        while (temp != NULL)
        {
            cout << temp->data<< " ";
            temp = temp->next;
        }
        cout << endl;
    }

////////////////////////////////////////////////////////////////////
// task check palindrome
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(queue<int> q) {
    stack<int> s;
    queue<int> temp = q;
    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }
    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }
        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(2);
    myQueue.push(1);

    if (isPalindrome(myQueue)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
///////////////////////////////////////////////////////////////////
// task rotate the linked list by k position
#include <iostream>
using namespace std;
class Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class Queue {
private:
    Node *front, *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    int dequeue() {
        if (front == nullptr) return -1;

        Node* temp = front;
        int val = temp->data;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        delete temp;
        size--;
        return val;
    }
    void rotate(int k) {
        if (size == 0 || k % size == 0) return;
        k = k % size;

        for (int i = 0; i < k; i++) {
            int val = dequeue();
            enqueue(val);
        }
    }
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    int k = 2;
    cout << "Queue before rotation: ";
    q.display();
    q.rotate(k);
    cout << "Queue after rotating by " << k << " positions: ";
    q.display();

    return 0;
}
