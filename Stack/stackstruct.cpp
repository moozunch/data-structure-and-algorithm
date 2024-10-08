#include <iostream>
#include <string>

using namespace std;

const int MAX = 100; // Maximum size of the stack

struct Stack {
    int top;
    string items[MAX];
};

void initialize(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, string item) {
    if (isFull(s)) {
        cout << "Stack is full!" << endl;
        return;
    }
    s.items[++s.top] = item;
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return;
    }
    s.top--;
}

void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Data masih kosong!" << endl;
        return;
    }
    cout << "Data buku yang tersimpan:" << endl;
    for (int i = s.top; i >= 0; i--) {
        cout << s.items[i] << endl;
    }
}

int main() {
    Stack s;
    initialize(s);

    // Example operations
    push(s, "si anak pemberani");
    push(s, "si anak cerdas");

    display(s);

    pop(s);
    display(s);

    return 0;
}