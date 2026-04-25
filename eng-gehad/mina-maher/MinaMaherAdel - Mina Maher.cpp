#include<bits/stdc++.h>
using namespace std;
#define dv vector

template <typename T>
struct Node{
  T data{};
  Node *next{};
  Node(T data):data(data){}
};

template <typename T>
class linkedlist{
  private:
    int size{};
    Node<T> *head{};
    Node<T> *tail{};
  public:
    linkedlist(){}
    linkedlist(T data){
      head = tail = new Node<T>(data);
      size=1;
    }
    void setsize(int x){
      size = x;
    }
    int getsize(){return size;}
    Node<T>* getHead(){return head;}
    Node<T>* getTail(){return tail;}
    void setHead(Node<T>* node){ head = node; }
    void setTail(Node<T>* node){ tail = node; }
    void insert(T x){
      Node<T> *newNode = new Node<T>(x);
      if(!head){
        head = tail = newNode;
      }else{
        tail->next=newNode;
        tail = newNode;
      }
      size++;
    }
    void deleteEnd(){
      if(!head) return void(cout << "empty linkedlist" << endl);
      Node<T> *cur = head;
      if(head==tail){
        size = 0;
        head = tail = nullptr;
        delete cur;
        return;
      }
      while(cur->next!=tail) cur = cur->next;
      Node<T> *deleting = cur->next;
      tail = cur;
      delete deleting;
      size--;
    }
    void getNthNode(int idx){
      if(idx > size || idx < 1 ) return void(cout<<"invalid idx" << endl);
      if(!head) return void(cout << "empty linkedlist" << endl);
      Node<T> *cur = head;
      idx--;
      while(idx){
        cur = cur->next;
        idx--;
      }
      return void(cout<<cur->data<< endl);
    }
    void reverseLL(){
      if(!head) return void(cout << "empty linkedlist" << endl);
      tail = head;
      Node<T> *cur = head;
      Node<T> *prv = nullptr;
      Node<T> *next = nullptr;
      while(cur){
        next=cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
      }
      head = prv;
    }
    void deleteNthNodeAndReturnUpdatedLL(int idx){
      if(idx >= size || idx < 0 ) return void( cout <<"invalid idx" << endl);
      if(!head) return void(cout<<"empty linkedlist" << endl);
      Node<T> *prv = head;
      idx--;
      if(idx <0){
        head = head->next;
        delete prv;
      }else{
        while(idx){
          prv = prv->next;
          idx--;
        }
        Node<T> *deleteThis = prv->next;
        prv->next = prv->next->next;
        delete deleteThis;
      }
      size--;
      display();
    }
    void display(){
      if(!head) return void(cout<<"empty linkedlist" << endl);
      Node<T> *cur = head;
      while(cur){
        cout << cur->data << " ";
        cur = cur->next;
      }
      cout << endl;
    }
};

template <typename T>
class StackLL{
  private:
    linkedlist<T> st;
  public:
  StackLL(){}
  StackLL(T x){
    st.insert(x);
  }
  void push(T x){
    st.insert(x);
  }
  void top(){
    if(!st.getTail()) return void( cout <<"empty StackLL" << endl);
    cout << st.getTail()->data;
  }
  void reverse(){
    st.reverseLL();
  }
  void pop(){
      st.deleteEnd();
  }
  bool isEmpty(){
    return (st.getsize()==0); 
  }
  void printStack(){
    st.display();
  }
  T getTop(){return st.getTail()->data;}
  void emptyTheStack(){
    st.reverseLL();
    while(!isEmpty()){
      top();
      pop();
    }
    cout << endl;
  }
};

template <typename T>
class StackArr{
  private:
    int size{};
    int top{};
    T *arr{};
  public:
  StackArr(int size):top(-1),size(size){
    arr = new T[size];
  }
  StackArr(T x , int size):top(0),size(size){
    arr = new T[size];
    arr[top] = x;
  }
  void insert(int value){
    if(isFull()) return void(cout << "stack is full"<< endl);
    top++;
    arr[top] = value;
  }
  bool isFull(){
    return (top==size-1);
  }
  bool isEmpty(){
    return (top == -1);
  }
  void pop(){
    if(isEmpty()) return void( cout <<"empty stack" << endl);
    top--;
  }
  void peek(){
    if(isEmpty()) return void(cout<<"empty stack"<< endl);
    cout <<"top : " << arr[top] << endl;
  }
};
template  <typename T>
class queueLL : public linkedlist<T>{
  private:
    linkedlist<T> ll;
  public:
    queueLL(){}
    void enqueue(T x){
      ll.insert(x);
    }
    void dequeue(){
      ll.deleteEnd();
    }
    void reverseByK( int k){
      while(k--){
        Node<T> *rv = ll.getHead();
        ll.setHead(ll.getHead()->next);
        Node<T> *ls = ll.getTail();
        ls->next = rv;
        rv->next = nullptr;
        ll.setTail(rv);
      }
    }
    void displayQLL(){
      ll.display();
    }
};
template<typename T>
class queueSt{
  private:
    StackLL<T> st1;
    StackLL<T> st2;
  public:
  queueSt(){}
  void enqueue( T x){
    st1.push(x);
  }
};
template  <typename T>
class queueArr{
  private:
    int rear{};
    int front{};
    T *arr{};
    int addedElements{};
    int size{};
  public:
    queueArr(int size) : size(size){
      arr = new T[size];
    }
    void dequeue(){
      if(isEmpty()) return void(cout<<"empty queue"<<endl);
      T n = arr[front];
      next(front);
      addedElements--;
      return void(cout<<n<<endl);
    }
    void enqueue(T x){
      if(isFull()) return void(cout<<"full queue"<<endl);
      arr[rear]=x;
      next(rear);
      addedElements++;
    }
    bool isFull(){
      return addedElements==size;
    }
    bool isEmpty(){
      return addedElements==0;
    }
    void next(int&p){
      if(p==size-1) p = 0;
      else p++;
    }
    void prv(int&x){
      if(x==0)x=(size-1);
      else x--;
    }
    bool palindrome(){
      if(rear>=front){
        for( int i = front , j = rear ; i < j ; j--,i++){
          if(arr[i]!=arr[j])return false;
        }
        return true;
      }else{
        for( int i = front , j = rear ; i > j ; i--,j++){
          if(arr[i]!=arr[j])return false;
        }
        return true;
      }
    }
    bool xExists(int x){
      for(int i = front , j = 0 ; j < addedElements ; next(i) , j++){
        if(arr[i]==x) return true;
      }
      return false;
    }
};
template <typename T>
void merge( Node<T> *cur1 , Node<T> *cur2 , linkedlist<T>&merged){
  while(cur1&&cur2){
    if(cur1->data <= cur2->data){
      merged.insert(cur1->data);
      cur1 = cur1->next;
    }else{
      merged.insert(cur2->data);
      cur2 = cur2->next;
    }
  }
  while(cur1){
    merged.insert(cur1->data);
    cur1 = cur1->next;
  }
  while(cur2){
    merged.insert(cur2->data);
    cur2 = cur2->next;
  }
}

int main(){
//   //linked list
//   linkedlist<int> ll;
//   for( int i = 1 ; i <= 10 ; i++){
//     ll.insert(i);
//   }
//   // getNthNode problem
//   ll.getNthNode(-1);
//   cout << "the 1st node = " ; ll.getNthNode(1); 
//   cout << "the 2nd node = " ; ll.getNthNode(2);
//   cout << "the 3rd node = " ; ll.getNthNode(3);
//   for( int i = 4 ; i <= 10 ; i++){
//     cout << "the " << i << "th node = ";  ll.getNthNode(i); cout << endl;
//   }
//   ll.getNthNode(101);
// /************************************************************/
// //seperator
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
//   // reverse linkedlist problem
//   cout <<"before reversing linkedlist : " << endl;
//   ll.display();
//   cout <<"after reversing linkedlist : " << endl;
//   ll.reverseLL();
//   ll.display();
//   ll.reverseLL();
// /************************************************************/
// //seperator
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
//   //deleteNthNode and return the updated linkedlist problem
//     ll.display();
//   for( int i = 9 ; i >= 0 ; i--){
//     cout << "deleting the " << i+1 << " node" << endl;
//     ll.deleteNthNodeAndReturnUpdatedLL(i);
//   }
// /************************************************************/
// //refill
//   for( int i = 1 ; i <= 10 ; i++){
//     ll.insert(i);
//   }
// /************************************************************/
// //seperator
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
// //merge two sorted linkedlists into one sorted linkedlist
//   linkedlist<int> l1 , l2 , mergedlist;
//   for( int i = 0 ; i < 5 ; i++) 
//     l1.insert(i);
//   cout << "list 1"<< endl;
//   l1.display();
//   for( int i = 2 ; i < 8 ; i++)
//     l2.insert(i);
//   cout << "list 2 " << endl;
//   l2.display();
//   Node<int> *cur1 = l1.getHead();
//   Node<int> *cur2 = l2.getHead();
//   cout <<"the result of merging list 1 and list 2 " << endl;
//   merge(cur1 , cur2 ,mergedlist);
//   mergedlist.display();

// /************************************************************/
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
//   //reverse integer digits using StackLL 
//   StackLL<char> st;
//   string num; cin >> num;
//   for( int i = 0 ; i < num.size() ; i++){
//     st.push(num[i]);
//   } 
//   while(!st.isEmpty()){
//     st.top();
//     st.pop();
//   } 
//   cout << endl;
// /************************************************************/
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
//   //remove stars from string 
//   StackLL<char> st2;
//   string s; cin >> s;
//   for( int i = 0 ; i < s.size() ; i++){
//     if(s[i]=='*') st.pop();
//     else st.push(s[i]);
//   }
//   st.printStack();
//   st.emptyTheStack();
// /************************************************************/
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /*************************************************************/
//   //implement stack using array 
//   StackArr<int> stArr(10);
//   cout << (stArr.isEmpty() ? "empty stack" : "not empty")<< endl;
//   for( int i = 0 ; i < 10 ; i++) stArr.insert(i);
//   cout << (stArr.isEmpty() ? "empty stack" : "not empty") << endl;
//   stArr.peek();
//   stArr.pop();
//   stArr.peek();
// /************************************************************/
//   for( int  i = 0 ; i < 3 ; i++){
//     for( int j = 0 ; j < i ; j++)
//       cout << " ";
//     for( int j = 0 ; j < 20 ; j++) 
//       cout << "*";
//     cout << endl;
//   }
// /************************************************************/
//   //make a set using stack
//   int n; cin >> n;
//   int arr[n];
//   for( int i = 0 ; i < n ; i++) cin >> arr[i];
//   StackLL<int> stt(arr[0]);
//   for( int i = 1 ; i < n ; i++){
//     if(stt.getTop()!=arr[i])stt.push(arr[i]);
//   }
//   stt.printStack();
// /************************************************************/
// for( int  i = 0 ; i < 3 ; i++){
//   for( int j = 0 ; j < i ; j++)
//     cout << " ";
//   for( int j = 0 ; j < 20 ; j++) 
//     cout << "*";
//   cout << endl;
// }
// /************************************************************/
//   //check palindrome
//   int nn; cin >> nn;
//   dv<int> v(nn); for( int i = 0 ; i < nn ; i++) cin >>v[i];
//   queueArr<int> q(nn);
//   for( int i = 0 ; i < nn ; i++)
//     q.enqueue(v[i]);
//   cout << (q.palindrome()?"the queue is palindrome":"the queue is not palindrome")<<endl;

// /************************************************************/
  // for( int  i = 0 ; i < 3 ; i++){
  //   for( int j = 0 ; j < i ; j++)
  //     cout << " ";
  //   for( int j = 0 ; j < 20 ; j++) 
  //     cout << "*";
  //   cout << endl;
  // }
// /************************************************************/
  // //check if x exits in the queue
  // int nnn; cin >> nnn;
  // queueArr<int> qq(nnn);
  // for( int i = 0 ; i < nnn ; i++){
  //   int x; cin >> x;
  //   qq.enqueue(x);
  // }
  // cout << (qq.xExists(102)?"yes":"no")<<endl;
// /************************************************************/
  // for( int  i = 0 ; i < 3 ; i++){
  //   for( int j = 0 ; j < i ; j++)
  //     cout << " ";
  //   for( int j = 0 ; j < 20 ; j++) 
  //     cout << "*";
  //   cout << endl;
  // }
// /************************************************************/
  queueLL<int> qLL;
  for( int i = 1 ; i < 6 ; i++) qLL.enqueue(i);
  qLL.reverseByK(2);
  qLL.displayQLL();
  return 0;
}