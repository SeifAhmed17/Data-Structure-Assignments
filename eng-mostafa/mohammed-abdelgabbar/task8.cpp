#define N 100
int arr[N];
int top = -1;

void push(int x) {
    if (top < N - 1)
        arr[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return arr[top--];
}

int peek() {
    if (top == -1) return -1;
    return arr[top];
}

bool isEmpty() {
    return top == -1;
}