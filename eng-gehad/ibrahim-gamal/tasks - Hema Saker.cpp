#include <iostream>

using namespace std;

//  1
node* get_nth(int n)
{
    int counter = 0;
    node* temp = head;

    while (temp != NULL)
    {
        if (counter == n)
        {
            return temp;
        }

        counter++;
        temp = temp->next;
    }

    return NULL;
}



//  2
void reverse()
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}


//  3
linkedlist merge(linkedlist l1, linkedlist l2)
{
    linkedlist result;

    node* t1 = l1.head;
    node* t2 = l2.head;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            result.append(t1->data);
            t1 = t1->next;
        }
        else
        {
            result.append(t2->data);
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        result.append(t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        result.append(t2->data);
        t2 = t2->next;
    }

    return result;
}



//  4
void remove_at(int x) {
    if (x == 0) {
        node* delptr = head;
        head = head->next;
        delete delptr;
        return;
    }
    node* temp = head;

    for (int i = 0; i < x - 1; i++) {
        temp = temp->next;
    }

    node* delptr = temp->next;
    temp->next = temp->next->next;
    delete delptr;
}



//  5

//   6

//   7

//   8
class Stack {
    int* arr;
    int top;
    int N;

public:
    Stack(int size) {
        N = size;
        arr = new int[N];
        top = -1;
    }

    void push(int val) {
        arr[++top] = val;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

//   9
int removeDuplicates(int arr[], int n) {
    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }

    arr[j++] = arr[n - 1];

    return j;
}


//   10
class Queue {
    stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
};

//   11
  bool isfound (int key)
  {
    bool found=false;
    node*temp=head;
    while (temp != NULL)
    {
       if (temp->data==key)
       {
        found=true;
       }
       temp=temp->next;

    }
    return found;
  }


