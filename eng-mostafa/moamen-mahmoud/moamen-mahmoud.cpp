//                                                  بِسۡمِ ٱللَّهِ ٱلرَّحۡمَٰنِ ٱلرَّحِيمِ
// El_Mooo ==> 1 (^_^)
 #include <iostream>
using namespace std;
#define elmoo ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl "\n"
// for( auto &it : v ) cin >> it ; // (^_^)
/*============================================================================*/

template<class t>
class Stack_arr {
    int max_size;
    int stack_size;
    t* arr;
    int top;

public:

    Stack_arr(int x) : max_size(x) {
        arr = new t [max_size];
        top = -1;
        stack_size = 0;
    }

    int size() {
        return stack_size;
    }

    bool is_empty() {
        return size() == 0;
    }

    bool is_full() {
        return stack_size == max_size;
    }

    void push(t x) {
        if (is_full()) return void (cout << "The stack is full.\n");
        arr[++top] = x;
        stack_size++;
    }

    void pop() {
        if (is_empty()) return void (cout << "There are no elements to delete!\n");
        arr[top--] = 0;
        stack_size--;
    }

    void peak(t &x , bool &ch) {
        ch = false;
        if (is_empty()) return void (cout << "There are no elements to get!");
        ch = true;
        x = arr[top];
    }

    void display() {
        cout << "The elements are: [ ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] ;
            if (i) cout << " , ";
        }
        cout << " ]" << endl;
    }

};

void elmooo() {
    // Task 1 :
    /*
        int n ; cin >> n; Stack_arr<int> st(10);
        while (n) {
            st.push(n%10);
            n /= 10;
        }
        int cur = 1 , x ; bool ch;
        while (!st.is_empty()) {
            st.peak(x,ch);
            n += x * cur;
            cur *= 10;
            st.pop();
        }
        cout << n;
     */

    // Task 2 :
    /*
        string s ; cin >> s; Stack_arr<char> st(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]);
            else {
                char c ; bool ch ;
                st.peak(c,ch);

                if ( (s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') ) st.pop();
                else return void (cout << "The String is Invalid!");
            }
        }
        cout << (st.is_empty() ? "The String is Valid!" : "The String is Invalid!") ;
     */

    // Task 3 :
    /*
        string s ; cin >> s; Stack_arr<char>st(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') st.pop();
            else st.push(s[i]);
        }
        Stack_arr<char>tmp(s.length());
        char c ; bool ch;
        while (!st.is_empty()) {
            st.peak(c,ch);
            tmp.push(c);
            st.pop();
        }
        while (!tmp.is_empty()) {
            tmp.peak(c,ch);
            cout << c;
            tmp.pop();
        }
     */

    // Task 4 :
    /*
        Stack_arr<int>st1(100);
        for (int i = 1; i <= 30; i++) st1.push(i);
        Stack_arr<int>st2(st1);
        st2.display();
     */

    // Task 5 :
    /*
        Stack_arr<int>st(100);
        for (int i = 1; i <= 30; i++) st.push(i);
        cout << st.size() << endl;
     */

}

int main() {
    // elmoo;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while (t--);
        elmooo();
    return 0;

}