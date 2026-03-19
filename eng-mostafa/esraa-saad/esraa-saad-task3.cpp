
#include <iostream>
#include <stack>
using namespace std;
const int MAX = 100;
class Stack {
private:
    int top;
    int s[MAX];
public:
    Stack() {
        top = -1;

    }
    void push(int x) {
        if (top < MAX - 1) {
            top++;
            s[top] = x;
        }
    }
    void display() {
        if (top != -1) {
            for (int i = top; i >= 0; i--)
           
            {
                cout << s[i];
            }
        }
        else
        {
            cout << "stack is empty" << endl;
        }

    }
    int getsize()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(11);
    s.display();
    cout << endl;
    cout << "stack size" << ":" << s.getsize();


}