#include <iostream>
#include <stack>
using namespace std;
stack <int> s1, s2;
void enqueue(int value)
{
    s1.push(value);
}
int dequeue() {
    if (s2.empty())
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();

        }
    }
        int item =s2.top();
        s2.pop();
        return item;
    }
    
       
    











int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << dequeue();
    enqueue(40);
    cout << dequeue();
    cout << dequeue();
    cout << dequeue();

}