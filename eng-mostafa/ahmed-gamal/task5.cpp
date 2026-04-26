#include <iostream>
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
        top = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node();

        newNode->data = val;

        newNode->next = top;

        top = newNode;
    }

    int pop()
    {
        if(top == NULL)
        {
            cout<<"Stack Empty"<<endl;
            return -1;
        }

        int value = top->data;

        Node* temp = top;

        top = top->next;

        delete temp;

        return value;
    }

    int peek()
    {
        if(top == NULL)
            return -1;

        return top->data;
    }

    bool isEmpty()
    {
        if(top==NULL)
            return true;

        return false;
    }
};

int main()
{
    Stack s;

    s.push(2);
    s.push(3);
    s.push(5);

    cout<<"Top element: "<<s.peek()<<endl;

    cout<<"Popped element: "<<s.pop()<<endl;

    cout<<"New top: "<<s.peek()<<endl;

    if(s.isEmpty())
        cout<<"Stack is Empty";
    else
        cout<<"Stack is Not Empty";

    return 0;
}