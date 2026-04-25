// task one
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node() { next = nullptr; }
};

class MyStack {
public:
Node* top;
MyStack(){
top = nullptr;
 }
bool isempty() {
return top == nullptr;
}

void push(char item) {
Node* newnode = new Node();
newnode->data = item;
newnode->next = top;
top = newnode;
}
char pop() {
if (isempty()) return '\0';
char item = top->data;
Node* del = top;
top = top->next;
delete del;
return item;
}
};


string filter(string s) {
string result = "";
for (char c : s) {
if (c == '*') {
if (!result.empty()) {
result.pop_back();
}
}
else {
result.push_back(c);
}
}
return result;
}

int main() {
string s = "leet**cod*e";
cout << "result: " << filter(s) << endl;

    return 0;
}
=============================================================================
 //task two
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() { next = nullptr; }
};

class mystack {
public:
Node* top;
mystack(){
top = nullptr;
 }
bool isempty() {
return top == nullptr;
}

void push(int item) {
Node* newnode = new Node();
newnode->data = item;
newnode->next = top;
top = newnode;
}
int pop() {
if (isempty()) return '\0';
char item = top->data;
Node* del = top;
top = top->next;
delete del;
return item;
}};
void copystack(mystack &S1, mystack &S2) {
if (S1.top == nullptr) return;
Node* current = S1.top;
mystack temp;
while (current != nullptr) {
temp.push(current->data);
current = current->next;
}
while (!temp.isempty()) {
S2.push(temp.pop());
}
}


int main() {
mystack S1, S2;
S1.push(1);
S1.push(2);
S1.push(3);
copystack(S1, S2);
cout << "Elements in S2 (Copied Stack): ";
Node* curr = S2.top;
while (curr != nullptr) {
cout << curr->data << " ";
curr = curr->next;
}
    cout << endl;
    return 0;
}
=====================================================
//task three

#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() { next = nullptr; }
};

class mystack {
public:
Node* top;
mystack(){
top = nullptr;
 }
bool isempty() {
return top == nullptr;
}

void push(int item) {
Node* newnode = new Node();
newnode->data = item;
newnode->next = top;
top = newnode;
}
int pop() {
if (isempty())
    return '\0';
int value;
Node*del=top;
top=top->next;
delete del;
return value;
}
void counte(){
if(isempty())
    cout<<"stack is empty"<<"\n";
else
{
int counter=0;
Node*temp=top;
while(temp!=nullptr){
    counter++;
    temp=temp->next;

}
cout<<"stack size is :"<<counter<<"\n";
}

}
};

int main() {
mystack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.counte();

return 0;
}
