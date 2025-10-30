#include <iostream>
#include <string>
#define MAX 100

using namespace std;

class Stack {
public:
    string st[MAX];
    int top;

    Stack() {
        top = -1;
    }

    bool isFull();
    bool isEmpty();
    void push(string x);
    string pop();
};

bool Stack::isFull() {
    return (top == MAX - 1);
}

bool Stack::isEmpty() {
    return (top == -1);
}

void Stack::push(string x) {
    if (isFull()) {
        cout << "Stack is full. Cannot add element: " << x << endl;
    } else {
        st[++top] = x;
        cout << "Pushed: " << x << endl;
    }
}

string Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to pop." << endl;
        return "";
    } else {
        cout << "Element is going to be popped: " << st[top] << endl;
        return st[top--];
    }
}

int main() {
    Stack s;
    s.push("apple");
    s.push("banana");
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    return 0;
}

