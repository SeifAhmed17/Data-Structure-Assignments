#include <iostream>
using namespace std;

// TASK ONE :

/*class node
{
public :
    int data ;
    node*next ;
    node()
    {
        data = 0 ;
        next = nullptr ;
    }
};
class linked
{
public :
    node*head ;
    int numberOfNodes ;
    linked()
    {
        head = nullptr ;
    }
     void inserting (int value)
    {
        node*newnode = new node ;
        newnode->data = value ;
        if(head == nullptr)
        {
            head = newnode ;
            newnode->next = nullptr ;
        }
        else
        {
            node*temp = head ;
            while(temp->next != nullptr)
            {
                temp = temp->next ;
            }
            temp->next = newnode ;
            newnode->next = nullptr ;
        }
    }
    void counter ()
     {
        node*temp = head ;  int cnt = 0 ;
        while(temp != nullptr)
        {
            cnt++ ;
            temp = temp->next ;
        }
        numberOfNodes = cnt ;
        cout << " Number of nodes is : " << numberOfNodes << endl ;
     }
     int get_nth (int n)
     {
         if (n > numberOfNodes)
            cout<< "This node not exist" << endl  ;
         else
         {
             node * temp = head ;
             for(int i = 1 ; i <= numberOfNodes ; i++)
             {
                 if(i == n)
                    return temp->data ;
                 else
                    temp = temp->next ;
             }
         }
     }
};
int main()
{
   linked ob ;
   int item ;
   cout << "Enter items of list ob : " << endl ;
    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> item ;
        ob.inserting(item) ;
    }
    ob.counter();
    ob.get_nth(5) ;
    cout << ob.get_nth(2) << endl ;
}*/


// TASK TWO :

/*#include <algorithm>
class node
{
public :
    int data ;
    node*next ;
    node()
    {
        data = 0 ;
        next = nullptr ;
    }
};
class linked
{
public :
    node*head ;
    int numberOfNodes ;
    linked()
    {
        head = nullptr ;
    }
     void inserting (int value)
    {
        node*newnode = new node ;
        newnode->data = value ;
        if(head == nullptr)
        {
            head = newnode ;
            newnode->next = nullptr ;
        }
        else
        {
            node*temp = head ;
            while(temp->next != nullptr)
            {
                temp = temp->next ;
            }
            temp->next = newnode ;
            newnode->next = nullptr ;
        }
    }
    void display ()
    {
        node*temp = head ;
        while(temp != nullptr)
        {
            cout << temp->data << "   " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
    int counter ()
     {
        node*temp = head ;  int cnt = 0 ;
        while(temp != nullptr)
        {
            cnt++ ;
            temp = temp->next ;
        }
        numberOfNodes = cnt ;
        return numberOfNodes ;
     }
     void mergeing (linked l1 , linked l2)
     {
         head = l1.head ;
         node*temp = l1.head ;
         while(temp->next != nullptr)
        {
            temp = temp->next ;
        }
        temp->next = l2.head ;
     }
     void sortint ()
     {
         int arr[numberOfNodes] ;
         node*x = head ;
         for(int i = 0 ; i < numberOfNodes ; i++)
         {
             arr[i] = x->data ;
             x = x->next ;
         }
         sort(arr , arr+numberOfNodes) ;
         node*y = head ;
         for(int i = 0 ; i < numberOfNodes ; i++)
         {
             y->data = arr[i];
             y = y->next ;
         }
     }
};
int main()
{
    linked ob1 , ob2 , ob ;
    int item1 , item2 ;
    for(int i = 0 ; i <3 ; i++)
    {
        cin>>item1 ;
        ob1.inserting(item1);
    }
    cout << endl ;
     for(int i = 0 ; i <3 ; i++)
    {
        cin>>item2 ;
        ob2.inserting(item2);
    }
    // merge :
    ob.mergeing(ob1 , ob2);
    ob.display();
    // sort :
    ob.counter();
    ob.sortint();
    ob.display();
}*/


// TASK THREE :

/*class node
{
public :
    int data ;
    node*next ;
    node()
    {
        data = 0 ;
        next = nullptr ;
    }
};
class linked
{
public :
    node*head ;
    int numberOfNodes ;
    linked()
    {
        head = nullptr ;
    }
     void inserting (int value)
    {
        node*newnode = new node ;
        newnode->data = value ;
        if(head == nullptr)
        {
            head = newnode ;
            newnode->next = nullptr ;
        }
        else
        {
            node*temp = head ;
            while(temp->next != nullptr)
            {
                temp = temp->next ;
            }
            temp->next = newnode ;
            newnode->next = nullptr ;
        }
    }
    void display ()
    {
        node*temp = head ;
        while(temp != nullptr)
        {
            cout << temp->data << "   " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
    void reverseing ()
    {
        node*previous = nullptr ;
        node*current = head ;
        node*nex = nullptr ;
        while(current != nullptr)
        {
            nex = current->next ;
            current->next = previous ;
            previous = current ;
            current = nex ;
        }
        head = previous ;
    }
};
int main()
{
    linked ob1  ;
    int item ;
    cout << "Enter items of ob1 : " << endl ;
    for(int i = 0 ; i <5 ; i++)
    {
        cin>>item ;
        ob1.inserting(item);
    }
    ob1.display() ;
    ob1.reverseing();
    ob1.display();
}*/


// TASK FOUR :

/*class node
{
public :
    int data ;
    node*next ;
    node()
    {
        data = 0 ;
        next = nullptr ;
    }
};
class linked
{
public :
    node*head ;
    int numberOfNodes ;
    linked()
    {
        head = nullptr ;
    }
     void inserting (int value)
    {
        node*newnode = new node ;
        newnode->data = value ;
        if(head == nullptr)
        {
            head = newnode ;
            newnode->next = nullptr ;
        }
        else
        {
            node*temp = head ;
            while(temp->next != nullptr)
            {
                temp = temp->next ;
            }
            temp->next = newnode ;
            newnode->next = nullptr ;
        }
    }
    void display ()
    {
        node*temp = head ;
        while(temp != nullptr)
        {
            cout << temp->data << "   " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
    void remove_node (int x)
    {
        node*y ;
        node*z = head ;
        int c = -1 ;
        while (c != x-1)
        {
            c++;
            y = z ;
            z = y->next ;
        }
        y->next = z->next ;
        delete z ;
    }
};
int main()
{
    linked ob ;
    int a ;
    for(int i = 0 ; i < 3 ; i++)
    {
        cin >> a ;
        ob.inserting(a);
    }
    ob.display();
    ob.remove_node(1);
    ob.display();
}*/


// TASK FIVE :

/*class st
{
public :
    int arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (int v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
    int peek ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top] ;
        }
    }
    void print ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            for(int i = top ; i >= 0 ; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};
int reflex (int num)
{
    st t ;
    if(num == 0)
    {
        return num ;
    }
    else
    {
        int x ;
        while(num != 0)
        {
           x = num % 10 ;
           t.push(x);
           num = num / 10 ;
        }
    }
    int tens = 1 ;
    while(t.top != -1)
    {
        num = (t.pop() * tens) + num ;
        tens = tens * 10 ;
    }
    cout << " Reflex number =>     " << num << endl ;

}
int main ()
{
    int n ;
    cin >> n ;
    reflex(n);
}*/


//TASK SIX :

/*#include <string>
class st
{
public :
    char arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (char v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
    int peek ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top] ;
        }
    }
    void print ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            for(int i = top ; i >= 0 ; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};
int ass (char o , char c)
{
    if(o == '(' && c == ')')
        return 1 ;
    else if (o == '[' && c == ']')
        return 1 ;
    else if (o == '{' && c == '}')
        return 1 ;
    else
        return 0 ;
}
void check (string s)
{
    st open ;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            open.push(s[i]) ;
        else
        {
            if((ass(open.arr[open.top] , s[i])) == 1)
                open.pop();
        }
    }
    if (open.top == -1)
        cout << "Balanced" << endl ;
    else
        cout << "Not" << endl ;
}
int main()
{
    check("(]}");
    check("({})");
}*/


//TASK SEVEN :

/*#include <string>
class st
{
public :
    char arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (char v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
    int peek ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top] ;
        }
    }
    void print ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            for(int i = top ; i >= 0 ; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};
void star (string s)
{
    st t ;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] != '*')
            t.push(s[i]);
        else
            t.pop();
    }
    for (int i = 0 ; i <= t.top ; i++)
    {
        cout << t.arr[i] ;
    }
}
int main ()
{
    star("leet**cod*e");
}*/


//TASK EIGHT :

/*class st
{
public :
    int arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (int v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
    int peek ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top] ;
        }
    }
    bool isEmpty ()
    {
        if (top == -1)
            return true ;
        else
            return false ;
    }
};*/


// TASK NINE :

/*class st
{
public :
    int arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (int v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
    int peek ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top] ;
        }
    }
    void print ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            for(int i = 0 ; i <= top ; i++)
            {
                cout << arr[i] << "," ;
            }
        }
    }
};
void dup (int a[] , int n)
{
   st t ;
   t.push(a[0]);
   for (int i = 1 ; i < n ; i++)
   {
       if(a[i] != t.arr[t.top])
       {
           t.push(a[i]) ;
       }
   }
   t.print();
}
int main ()
{
    int x ;
    cin >> x ;
    int y[x];
    for (int i = 0 ; i < x ; i++)
    {
        cin >> y[i];
    }
    cout << endl ;
    dup(y , x) ;

}*/


// TASK TEN :

/*const int s = 5 ;
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



/*const int s = 5 ;
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



// TASK ELEVEN :

/*const int s = 5 ;
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
    bool searching (int val)
    {
        int f = 0;
        for(int i = top ; i >= 0 ; i--)
        {
            if(arr[i] == val)
                f = 1 ;
        }
        if(f == 0)
            return false ;
        else if (f == 1)
            return true ;
    }
};
int main()
{
    stak s ;
    int x ;
    for(int i = 1 ; i <= 5 ; i++)
    {
        cin >> x ;
        s.push(x);
    }
    cout << s.searching(100) << endl ;
    cout << s.searching(9) << endl ;
}*/


// TASK 12 :

/*const int s = 10;
class qu
{
public :
    int qu[s];
    int f = -1 , r = -1 ;

void enqu (int val)
{
    if(r == s-1)
    {
        cout << "Full" << endl ;
    }
    else
    {
        if(f == -1 && r == -1)
        {
            r++;
            qu[r] = val ;
            f++;
        }
        else
        {
            r++;
            qu[r] = val ;
        }
    }
}
void dequ ()
{
    if((f == -1 && r == -1)||(f == r+1))
    {
        cout << "Empty" << endl ;
    }
    else
    {
        f++;
    }
}
};
class st
{
public :
    int arr [20] ;
    int top ;
    st ()
    {
        top = -1 ;
    }
    void push (int v)
    {
        if(top == 19)
        {
            cout << "full" << endl ;
        }
        else
        {
            top++;
            arr[top] = v ;
        }
    }
    int pop ()
    {
        if(top == -1)
        {
            cout << "empty" << endl ;
        }
        else
        {
            return arr[top--] ;
        }
    }
};
void check (qu x)
{
    qu temp = x ;
    st s ;
    while(temp.f != temp.r+1)
    {
        s.push(temp.qu[temp.f]);
        temp.dequ();
    }
    while((x.f != x.r + 1) && (s.top != -1) )
    {
        if(x.qu[x.f] == s.arr[s.top])
        {
            x.dequ();
            s.pop();
        }
        else
        {
            break ;
        }
    }
    if((x.f == x.r + 1) && (s.top == -1))
    {
        cout << "palindrome" << endl ;
    }
    else
    {
        cout << "not" << endl ;
    }

}
int main()
{
    qu z ;
    z.enqu(3);
    z.enqu(2);
    z.enqu(1);
    z.enqu(2);
    z.enqu(3);
    check(z);
}*/


//TASK 13 :


/*class node
{
public :
    int d ;
    node*n ;
    node()
    {
        d = 0 ;
        n = nullptr ;
    }
};
class QU
{
public :
    node*f ; // front
    node*r ; // rear  or  back
    QU()
    {
        f = nullptr ;
        r = nullptr ;
    }
    void enqu (int val)
    {
        node*nn = new node ;
        nn->d = val ;
        if (f == nullptr && r == nullptr)
        {
            f = r = nn ;
            nn->n = nullptr ;
        }
        else
        {
            node*x = r ;
            x->n = nn ;
            nn->n = nullptr ;
            r = nn ;
        }
    }
    void dequ ()
    {
        int y ;
        if(f == nullptr && r == nullptr)
        {
            cout << "queue is empty" << endl ;
        }
        else if(f == r)
        {
            node*del=f ;
            f = r = nullptr ;
            y = del->d ;
            delete del ;
        }
        else
        {
            node*del = f ;
            f = del->n ;
            y = del->d ;
            delete del ;
        }
        cout << "deleted value is : " << y << endl ;
    }
    void dis ()
    {
        node*t = f ;
        while(t != nullptr)
        {
            cout << t->d << "   ";
            t = t->n ;
        }
        cout << endl ;
    }
};
void rotat (QU x , int k)
{
    node*temp = x.f ;
    int c = 0;
    while(c != k-1)
    {
        c++;
        temp=temp->n ;
    }
    node*z = x.f ;
    while(z->n != nullptr)
    {
        z = z->n;
    }
    node*y = x.f ;
    x.f=temp->n ;
    z->n = y ;
    x.r = temp ;
    temp->n = nullptr;
    x.dis();
}
int main ()
{
    QU a ;
    int item ;
    for(int i = 1 ; i<= 5 ; i++)
    {
        cin >> item ;
        a.enqu(item);
    }
    cout << endl ;
    rotat(a , 2);
}*/
