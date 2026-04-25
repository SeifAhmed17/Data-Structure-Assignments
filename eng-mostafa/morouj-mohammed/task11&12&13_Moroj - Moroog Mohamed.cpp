#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
template<class t>
class queue {
    struct node {
        t item;
        node* next;
    };
    int length;
    node* front, * rear;
public:
    queue() :front(nullptr), rear(nullptr), length(0) {};
    bool isempty() {
        return length == 0;
    }
    void enqueue(t element) {
        node* newnode = new node();
        newnode->item = element;
        newnode->next = nullptr;
        if (isempty()) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
        length++;
    }
    t popfront() {
        assert(!isempty());
        node* temp = front;
        front = front->next;
        length--;
        if (isempty())
            rear = nullptr;
        t val = temp->item;
        delete temp;
        return val;
    }
    void display() {
        assert(!isempty());
        node* cur = front;
        while (cur != nullptr) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    int getsize() {
        return length;
    }
    node* getfront() {
        assert(!isempty());
        return front;
    }
    void copy( queue<t>&other) {
        node* cur = other.getfront();
        while (cur) {
            enqueue(cur->item);
            cur = cur->next;
        }
    }
    // exist?!
    bool exist(t element) {
        if (isempty()) return 0;
        node* temp = front;
        while (temp) {
            if (temp->item == element) return 1;
            temp = temp->next;
        }
        return 0;
    }
};
//palidrome?!
template<class t>
bool palidrome (queue<t> q) {
    stack<t> st;
    queue<t>temp;
    temp.copy(q);
    while (!temp.isempty()) {
        st.push(temp.popfront());
    }

    while (!q.isempty()) {
        if (q.popfront() != st.top())
            return false;

        st.pop();
    }

    return true;
}
//rotate
template<class t>
void rotate(int k, queue<t>&q) {
    if (q.isempty() || k == 0) return;
    k %= q.getsize();
    while (k--) {
        q.enqueue(q.popfront());
    }
}
int main() {
    queue<int>q;
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);
    q.enqueue(500);
    q.display();
    cout << q.exist(500) << endl;
    cout << palidrome(q);
    int k; cin >> k;
    rotate(k, q);
    q.display();
    return 0;
}