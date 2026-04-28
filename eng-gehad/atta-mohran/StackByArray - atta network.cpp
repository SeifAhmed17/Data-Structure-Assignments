#include <iostream>
using namespace std;
class stack {
    private:
        int top ;
        int size ;
        int len;
        int * arr;
    public : 
        stack(int s){
            top= -1;
            len = 0;
            this->size = s;
            arr = new int[size];
        }
        bool isEmpty (){
            return len ==0;
        }
        bool isFull(){
            return top+1==size;
        }
        void push (int data){
            if (!isFull())
            {
                top++;
                len++;
                arr[top]=data;
            }else{
                cout<<"stack is Full";
            }
        }
        int pop (){
            if (isEmpty())
            {
                cout<<"stack is Empty"<<endl;
                return -1;
            }
            else{
                len--;
                return arr[top--];
            }
            
        }
        int peek(){
            if (isEmpty())
            {
                    cout<<"stack is empty";
                    return -1;
            }else
            {
                return arr[top];
            }        
        }
};
int main (){
    stack s1(5);

}