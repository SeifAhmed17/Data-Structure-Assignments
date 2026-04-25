#include <bits/stdc++.h>
#include <ctime>
#include<ext/pb_ds/assoc_container.hpp>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <windows.h>
#pragma warning(disable : 4996)
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedset;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>orderdmultiset;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
class Stack {
    int top=-1;
    int size=100;
    char arr[100];

public:
    bool is_empty() {
        return top==-1;
    }
    bool is_full() {
        return top==size-1;
    }
    void push(char x) {
        if(is_full()) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=x;
    }
    int pop() {
        if (is_empty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return --top;
    }
    int peek() {
        if (is_empty()) {
            return -1;
        }
        return arr[top];
    }
    void display() {
        for (int i=top;i>=0;i--) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};



class Queue {
Stack inbox, outbox;
    int size=0;
    void Transfer() {
        while (!inbox.is_empty()) {
            outbox.push(inbox.peek());
            inbox.pop();
        }

    }
public:

    void enqueue(int x) {
        if (inbox.is_full()) {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        inbox.push(x);
        size++;
    }
    int dequeue() {
        if (outbox.is_empty()) {
            if (inbox.is_empty()) {
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            else {
                Transfer();
            }
        }
            int val=outbox.peek();
            outbox.pop();
            size--;
            return val;

    }
    int peek() {
        if (outbox.is_empty()) {
            if (inbox.is_empty()) {
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            else {
                Transfer();
            }
        }

        return outbox.peek();

    }
    bool isEmpty() {
            return inbox.is_empty() and outbox.is_empty();
        }

};



signed main() {
    fast();

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

}