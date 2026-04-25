#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long sl;
template<class t>
class queue1{
private:
    int count , size ;
    stack<t>a,b;
    void move (stack<t> &a , stack<t> &b) {
        assert (b.empty());
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }
public:
    bool isfull() {
        return count == size ;
    }
    bool isempty() {
        return count == 0 ;
    }
    queue1(int s):size(s),count(0) {}
    void enqueue(t val) {
        assert(!isfull());
        a.push(val);
        count++;
    }
    t  dequeue() {
        assert(!isempty());
        if (b.empty()) move(a,b);
        t top = b.top();
        b.pop();
        count--;
        return top;
    }
    void display() {
        assert(!isempty());
        stack<t>temp_a= a ,temp_b=b;
        while (!temp_b.empty()) {
            cout << temp_b.top() << " ";
            temp_b.pop();
        }
        while (!temp_a.empty()) {
            temp_b.push(temp_a.top());
            temp_a.pop();
        }
        while (!temp_b.empty()) {
            cout << temp_b.top() << " ";
            temp_b.pop();
        }
        cout << endl;

    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    queue1<int>q1(10);
    for (int i=0;i<9;i++) {
        q1.enqueue(i);
    }
    q1.dequeue();
    q1.display();

    return 0;
}