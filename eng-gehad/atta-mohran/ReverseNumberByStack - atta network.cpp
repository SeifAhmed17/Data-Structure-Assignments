#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int reverseNumber(int num ){
    string numStr = to_string(num);
    stack <char> nums;
    string numrev = "";
    if (numStr.length()==1)
    {
        return stoi(numStr);
    }else
    {
        for (int i = 0; i < numStr.length(); i++)
        {
            nums.push(numStr[i]);
        }
        for (int i = 0; i < numStr.length(); i++)
        {
            numrev.push_back(nums.top());
            nums.pop();
        }
        return stoi(numrev);   
    }    
}
int main (){
    cout<<reverseNumber(5356)<<endl;
}