#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string str){
    stack <char> s;
    for(int i = 0 ; i <str.length();i++){
        char c = str[i];
        if (c =='('||c=='{'||c=='[')
        {
            s.push(c);
        }else
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            if ((c==')'&&top=='(')||(c=='}'&&top=='{')||(c==']'&&top=='['))
            {
                s.pop();
            }else{
                return false;
            }
            
        }
    }
    return s.empty();
}
int main (){
cout<<isValid("[{()}]")<<endl;
cout<<isValid("[{()}]]")<<endl;
}