#include <iostream>
#include <stack>
using namespace std;
class queue{
    private :
    stack <int> s1 , s2;
    void enqueue (int data){
        s1.push(data);
    }
    int dequeue (){
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        int value = s2.top();
        s2.pop();
        return value;
        
    }
};
int main (){

}