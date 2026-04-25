#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Task 1 : */

/* class stac
{
public :
    char arr[50];
    int top ;
    stac()
    {
        top = -1 ;
    }
    void push (char x)
    {
        if(top == 49)
        {
            cout << "is full" << endl ;
        }
        else
        {
            top++ ;
            arr[top]=x ;
        }
    }
    char pop ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top--];
        }
    }
    char peek ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top];
        }
    }
    void printOFstack ()
    {
        for (int i = top ; i >= 0 ; i--)
        {
            cout << arr[i] << endl ;
        }
    }
    void printOFstring ()
    {
        for (int i = 0 ; i <= top ; i++)
        {
            cout << arr[i]  ;
        }
    }
};
void starRemove (string exp)
{
   stac ob ;
   for (int i = 0 ; i < exp.length() ; i++)
   {
       if(exp[i] != '*')
       {
           ob.push(exp[i]) ;
       }
       else
       {
           ob.pop();
       }
   }
   ob.printOFstring();
}
int main()
{
    string s ;
    s = "leet**cod*e" ;
    starRemove(s); // lecoe
}*/


/* Task 2 : */


/* class stac
{
public :
    int arr[50];
    int top ;
    stac()
    {
        top = -1 ;
    }
    void push (int x)
    {
        if(top == 49)
        {
            cout << "is full" << endl ;
        }
        else
        {
            top++ ;
            arr[top]=x ;
        }
    }
    int pop ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top--];
        }
    }
    int peek ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top];
        }
    }
    void printOFstack ()
    {
        for (int i = top ; i >= 0 ; i--)
        {
            cout << arr[i] << endl ;
        }
    }
};
void xyz (stac s1 , stac s2)
{
    stac t ;
    int x ;
    for (int i = s1.top ; i >= 0 ; i--)
    {
        x = s1.pop();
        t.push(x);
    }
    int y ;
    for (int i = t.top ; i >= 0 ; i--)
    {
        y = t.pop();
        s2.push(y);
    }
    s2.printOFstack();
}

int main ()
{
    stac ob1 , ob2 ;
    ob1.push(3);
    ob1.push(7);
    ob1.push(9);
    ob1.push(2);
    ob1.push(5);
    xyz(ob1 , ob2) ;
}*/


/* Task 3 : */


/*class stac
{
public :
    int arr[50];
    int top ;
    stac()
    {
        top = -1 ;
    }
    void push (int x)
    {
        if(top == 49)
        {
            cout << "is full" << endl ;
        }
        else
        {
            top++ ;
            arr[top]=x ;
        }
    }
    int pop ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top--];
        }
    }
    int peek ()
    {
        if(top==-1)
        {
            cout << "is empty" << endl ;
        }
        else
        {
            return arr[top];
        }
    }
    void printOFstack ()
    {
        for (int i = top ; i >= 0 ; i--)
        {
            cout << arr[i] << endl ;
        }
    }
    void counter ()
    {
        int cnt = 0 ;
        for (int i = top ; i >= 0 ; i--)
        {
            cnt++ ;
        }
        cout << "number of elements : " << cnt << endl;
    }

};
int main ()
{
    stac ob ;
    int x ;
    for (int i = 0 ; i <= 5 ; i++)
    {
        cout << " enter element : " ;
        cin >> x ;
        ob.push(x);
    }
    ob.counter(); // 6
}*/

