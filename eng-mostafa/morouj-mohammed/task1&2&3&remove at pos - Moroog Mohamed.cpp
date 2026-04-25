#include <iostream>
using namespace std;
template <class t>
class linkedlist {
    struct node {
        t item;
        node* next;
    };

    int length;
    node* tail, * head;

public:
    linkedlist() : tail(nullptr), head(nullptr), length(0) {}

    node* gethead() {
        return head;
    }

    node* gettail() {
        return tail;
    }

    int getlength() {
        return length;
    }

    void insertleft(t element) {
        node* newnode = new node;
        newnode->item = element;
        newnode->next = nullptr;

        if (!length) {
            head = newnode;
        } else {
            tail->next = newnode;
        }

        tail = newnode;
        length++;
    }

    t getnthitem(int n) {
        if (n < 0 || n >= length)
            return t();

        node* temp = head;
        int i = 0;

        while (i < n) {
            temp = temp->next;
            i++;
        }

        return temp->item;
    }

    void sorted(linkedlist& x, linkedlist& y) {
        node* cur1 = head;
        node* cur2 = x.gethead();

        while (cur1 && cur2) {
            if (cur2->item <= cur1->item) {
                y.insertleft(cur2->item);
                cur2 = cur2->next;
            } else {
                y.insertleft(cur1->item);
                cur1 = cur1->next;
            }
        }

        node* rem = (cur1) ? cur1 : cur2;

        while (rem) {
            y.insertleft(rem->item);
            rem = rem->next;
        }
    }

    void reverse() {
        node* pre = nullptr;
        node* cur = head;
        node* nex = nullptr;

        tail = head;

        while (cur != nullptr) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        head = pre;
    }

    void print() {
        node* cur = head;
        while (cur) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    void remove_pos(int n) {
        if (n < 0 || n >= length) return;

        if (n == 0) {
            node* temp = head;
            head = head->next;
            delete temp;
            if (length == 1) tail = nullptr;
        } else {
            node* cur = head;
            for (int i = 1; i < n; i++) {
                cur = cur->next;
            }

            node* temp = cur->next;
            cur->next = temp->next;

            if (temp == tail)
                tail = cur;

            delete temp;
        }

        length--;
    }
};

int main() {
    return 0;
}