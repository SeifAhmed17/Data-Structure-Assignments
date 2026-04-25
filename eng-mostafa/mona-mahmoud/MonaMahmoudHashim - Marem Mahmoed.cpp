 // Infix To Postfix :

 /*#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const int s = 20 ;
class stac
{
public :
    int top ;
    char arr[s];
    stac()
    {
        top = -1;
    }
    void push (char c)
    {
        top++;
        arr[top] = c ;
    }
    int pop ()
    {
        return arr[top--];
    }
};
int priority (char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
}
string in_TO_post (string exp)
{
    stac st ;
    string result ;
    for (int i = 0 ; i < exp.length() ; i++)
    {
        if (exp[i] == ' ')
            continue ;
        else if (exp[i] == '(')
                 st.push(exp[i]) ;
        else if (isdigit(exp[i]) || isalpha(exp[i]))
            result = result + exp[i] ;
        else if (exp[i] == ')')
            {
                while(st.arr[st.top] != '(')
                {
                   result += st.pop() ;
                }
                st.pop();
            }
        else
        {
            if ((st.top == -1) || (st.arr[st.top] == '(') || (priority(exp[i]) > priority(st.arr[st.top])))
            {
                st.push(exp[i]) ;
            }
            else if ( priority(exp[i]) <= priority(st.arr[st.top]) )
            {
                while( (st.top != -1) || (st.arr[st.top] != '(') || (priority(exp[i]) <= priority(st.arr[st.top])) )
                {
                    result += st.pop() ;
                }
                st.push(exp[i]) ;
            }
        }
    }
    if (st.top == -1)
    {
        return result ;
    }
    else
    {
        while (st.top != -1)
        {
            result += st.pop() ;
        }
        return result ;
    }
}
float temp (float f , float s , char o)
{
    if (o == '+')
        return f + s ;
    else if (o == '-')
        return f - s ;
    else if (o == '*')
        return f * s ;
    else if (o == '/')
        return f / s ;
}
float final_result (string exp)
{
    stac x ;
    for (int i = 0 ; i < exp.length() ; i++)
    {
        if (isdigit(exp[i]))
        {
            x.push(exp[i] - '0') ;
        }
        else
        {
            float first , second , y ;
            second = x.pop() ;
            first = x.pop() ;
            y = temp(first , second , exp[i]) ;
            x.push(y) ;
        }
    }
    float answer = x.pop() ;
    return answer ;
}
int main()
{
    string str_z = in_TO_post("(2+3)*4") ;
    cout << "Final Expression : " << str_z << endl ;
    cout << endl ;
    float z = final_result(str_z) ;
    cout << "Final Result : " << z << endl ;
}*/



/*#include <iostream>
using namespace std;

// Task By Approach One :

 const int s = 5 ;
class stak
{
public :
    int arr[s];
    int top ;
    stak()
    {
        top = -1;
    }
    void push (int val)
    {
        top++;
        arr[top] = val ;
    }
    int pop ()
    {
       return arr[top--];
    }
    void display ()
    {
        for(int i = top ; i >= 0 ; i--)
        {
            cout << arr[i] << "   ";
        }
        cout << endl ;
    }
};

stak s1 , s2 ;
void enqu (int val)
{
    if(s1.top==-1)
    {
        s1.push(val);
    }
    else
    {
        for(int i = s1.top ; i >= 0 ; i--)
        {
            int x = s1.pop();
            s2.push(x);
        }
        s1.push(val);
        for(int i = s2.top ; i >= 0 ; i--)
        {
            int x = s2.pop();
            s1.push(x);
        }
    }
}
void dequ ()
{
    cout << "Deleted Item : " << s1.pop() << endl ;
}
void displayQU ()
{
    s1.display();
}
int main()
{
    enqu(3);
    enqu(9);
    enqu(2);
    enqu(5);
    enqu(1);

    dequ();
    dequ();

    displayQU(); // 2 5 1
}*/




/*#include <iostream>
using namespace std;

// Task By Approach Two :

const int s = 5 ;
class stak
{
public :
    int arr[s];
    int top ;
    stak()
    {
        top = -1;
    }
    void push (int val)
    {
        top++;
        arr[top] = val ;
    }
    int pop ()
    {
       return arr[top--];
    }
    void display ()
    {
        for(int i = top ; i >= 0 ; i--)
        {
            cout << arr[i] << "   ";
        }
        cout << endl ;
    }
};

stak s1 , s2 ;
void enqu (int val)
{
    s1.push(val);
}
void dequ ()
{
    for(int i = s1.top ; i >= 0 ; i--)
    {
        int x = s1.pop();
        s2.push(x);
    }
    cout << "Deleted Item : " << s2.pop() << endl ;
}
void displayQU ()
{
    s2.display() ;
}

int main()
{
    enqu(3);
    enqu(9);
    enqu(2);
    enqu(5);
    enqu(1);

    dequ(); // 3
    dequ(); // 9

    displayQU(); // 2 5 1
}*/



