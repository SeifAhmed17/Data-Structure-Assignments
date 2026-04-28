#include <iostream>
#include <stack>
using namespace std;
string removeStar(string str){
    stack <char> s;
    for(char c : str){
        if (c!='*')
        {
            s.push(c);
        }else
        {
            if (!s.empty())
            {
                s.pop();
            }
            
        }
    }
    string result = "";
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    string s2 =  "";
    for (int i = result.length()-1; i >=0; i--)
    {
        s2 += result[i];
    }
    return s2;
    
}
int main (){
    cout<<removeStar("leet**cod*e")<<endl;
}