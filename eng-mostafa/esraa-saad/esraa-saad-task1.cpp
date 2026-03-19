
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string withoutstars(string s) {
	stack<char> c;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '*')
		{
			c.push(s[i]);

		}
		else
		{
			if (!c.empty()) {
				c.pop();
			}
		}
	}
   string r = "";

    while(!c.empty()){
	r = c.top() + r;
		c.pop();
     }   
	return r;

}

int main(){
	string s;
	cout << "enter s" << endl;
	cin >>s;
	cout << withoutstars(s) << endl;
}

