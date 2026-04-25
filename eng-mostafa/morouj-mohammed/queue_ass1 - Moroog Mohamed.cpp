#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
template<class t>
class array_queue {
private:
	int  rear, size;
	t* items;
public:
	array_queue(int s) :size(s), rear(-1) {
		items = new t[size];
	}
	bool isempty() {
		return rear == -1;
	}
	bool isfull() {
		return rear == size - 1;
	}
	void enqueue(t element) {
		assert(!isfull());
		items[++rear] = element;
	}
	t dequeue() {
		assert(!isempty());
		t val = items[0];
		for (int i = 0; i < rear; i++) {
			items[i] = items[i + 1];
		}
		rear--;
		return val;
	}
	void display() {
		for (int i = 0; i <= rear; i++) cout << items[i] << " ";
		cout << endl;
	}
};

int main() {
	array_queue<int>q1(10);
	for (int i = 0; i < 9; i++) {
		q1.enqueue(i);
	}
	q1.dequeue();
	q1.display();
	return 0;
}
