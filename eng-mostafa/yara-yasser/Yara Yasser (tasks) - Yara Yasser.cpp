// Name: Yara Yasser Mostafa 
// Level : Second Year

#include <iostream>
#include <algorithm>
using namespace std;



//------------------------------------- Section 2 ------------------------------------//

template <class t>
class Node {
public:
	t  data;
	Node<t>* next;

};

template <class t>
class LinkedList {
public:
	Node<t>* head;

	LinkedList() :head(nullptr) {}

	LinkedList(Node<t>* newnode) {
		head = newnode;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	int count() {
		int cnt = 0;
		Node<t>* temp = head;
		while (temp != nullptr) {
			cnt++;
			temp = temp->next;
		}
		return cnt;
	}


	//----------- Task1 ----------
	//----- print using loop -----
	void printLoop() {
		Node<t>* temp = head;

		for (; temp != nullptr; temp = temp->next) {
			cout << temp->data << " ";
		}
		cout << endl;
	}


	//----------- Task2 ----------
	//------- get_nth_Node -------
	t get_nth_Node(int index) {

		if (count() >= index && !isEmpty() && index != 0) {

			Node<t>* temp = head;
			for (int i = 1; i < index; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
		else
			return t();
	}


	//----------- Task3 ----------
	//---------- Reverse ---------
	Node<t>* reverse() {
		Node<t>* reversed = nullptr;
		Node <t>* temp = head;
		while (temp != nullptr) {
			Node<t>* newnode = new Node<t>();
			newnode->data = temp->data;
			newnode->next = reversed;
			reversed = newnode;
			temp = temp->next;
		}
		return reversed;
	}

};

//----------- Task4 ----------
//----------- Merge ----------
template <class t>
Node<t>* mergeCopy(Node<t>* list1, Node<t>* list2) {
	if (!list1 && !list2) return nullptr;
	Node<t> dummy;
	Node<t>* tail = &dummy;
	dummy.next = nullptr;

	while (list1 && list2) {
		Node<t>* newNode = new Node<t>();
		if (list1->data <= list2->data) {
			newNode->data = list1->data;
			list1 = list1->next;
		}
		else {
			newNode->data = list2->data;
			list2 = list2->next;
		}
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}

	Node<t>* remaining = list1 ? list1 : list2;
	while (remaining) {
		Node<t>* newNode = new Node<t>();
		newNode->data = remaining->data;
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
		remaining = remaining->next;
	}
	return dummy.next;
}




//------------------------------------- Section 3 ------------------------------------//

template <class t>
class stack {
private:
	int top;
	int size;
	t* items;

public:

	stack(int s) : top(-1), size(s) {
		items = new t[size];
	}

	bool isEmpty() {
		return top < 0;
	}

	bool isFull() {
		return top >= size - 1;
	}

	void push(t new_element) {
		if (isFull())
			cout << "Stack is Full" << endl;
		else
			items[++top] = new_element;
	}

	t pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return t();
		}
		else {
			t val = items[top];
			--top;
			return val;
		}
	}

	t peek() {
		if (isEmpty())
			return t();
		else
			return items[top];
	}

	//------------ Task 2 ----------------
	//----------- Copy stack -------------
	void copy(stack& st) {
		top = st.top;
		size = st.size;
		for (int i = 0; i <= top; i++) {
			items[i] = st.items[i];
		}
	}


	//------------ Task 3 ----------------
	//----------- Get size ---------------
	int getSize() {
		return top + 1;
	}

};

//------------ Task 1 ----------------
//----------- Remove Stars -----------
string remove_stars(string s) {
	stack<char> s2(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			if (!s2.isEmpty())
				s2.pop();
		}
		else {
			s2.push(s[i]);
		}
	}
	string after_remove(s2.getSize(), ' ');
	int i = s2.getSize() - 1;
	while (!s2.isEmpty()) {
		after_remove[i] = s2.peek();
		s2.pop();   i--;
	}
	return after_remove;
}





//------------------------------------- Section 4 ------------------------------------//

//----------infinx to prefix-----------
bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	return 0;
}

string infixToPrefix(string exp) {

	//---------Reverse----------
	reverse(exp.begin(), exp.end());

	//------Swap brackets-------
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(')
			exp[i] = ')';
		else if (exp[i] == ')')
			exp[i] = '(';
	}


	stack<char> st(100);
	string postfix = "";

	//------Infix -> Postfix------
	for (int i = 0; i < exp.length(); i++) {
		char ch = exp[i];

		 if (ch == '(')   
			 st.push(ch);
	
		 else if (ch == ')') {
			 while (!st.isEmpty() && st.peek() != '(') 
				 postfix += st.pop();
			 st.pop();}

		 else if (isOperator(ch)) {
			 while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) 
				 postfix += st.pop();
			 st.push(ch);}

		else
			 postfix += ch;
	}

	while (!st.isEmpty())
        postfix += st.pop();

	//------ Reverse -> Prefix ---------
	reverse(postfix.begin(), postfix.end());

	return postfix;
}

int main() {
	string exp = "(A-B/C)*(A/K-L)";
	cout << "Prefix: " << infixToPrefix(exp);
	return 0;
}






//------------------------------------- Section 5 ------------------------------------//


//-------------- Task 1 -----------------
//-------Queue using two stacks----------
template <class t>
class Queue {
private:
	stack<t> s1;
	stack<t> s2;

public:
	Queue(int size) : s1(size), s2(size) {}

	void enqueue(t element) {
		s1.push(element);
	}

	t dequeue() {
		if (s1.isEmpty() && s2.isEmpty()) {
			cout << "Queue is Empty\n";
			return t();
		}

		if (s2.isEmpty()) {
			while (!s1.isEmpty()) {
				s2.push(s1.pop());
			}
		}
		return s2.pop();
	}

	t peek() {
		if (s1.isEmpty() && s2.isEmpty()) {
			cout << "Queue is Empty\n";
			return t();
		}
		if (s2.isEmpty()) {
			while (!s1.isEmpty()) 
				s2.push(s1.pop());
		}
		return s2.peek();
	}

	bool isEmpty() {
		return s1.isEmpty() && s2.isEmpty();
	}
};

//-------------- Task 2 ------------------
//---Queue array-based (shift approach)---
template <class t>
class Queue {
private:
	int front;
	int rear;
	int size;
	t* arr;

public:
	Queue(int s) {
		size = s;
		front = 0;
		rear = -1;
		arr = new t[size];
	}

	bool isEmpty() {
		return rear < front;
	}

	bool isFull() {
		return rear == size - 1;
	}

	void enqueue(t element) {
		if (isFull()) 
			cout << "Queue is Full\n";
	
		else 
			arr[++rear] = element;
	}

	t dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty\n";
			return t();
		}
		else {
			t val = arr[front];

			for (int i = front; i < rear; i++) 
				arr[i] = arr[i + 1];
			rear--; 
			return val;
		}
	}

	t peek() {
		if (isEmpty())
			return t();
		return arr[front];
	}

	int getSize() {
		return (rear - front + 1);
	}

	void display() {
		for (int i = front; i <= rear; i++) 
			cout << arr[i] << " ";
		cout << endl;
	}
};



																						