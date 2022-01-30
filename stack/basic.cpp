#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Stack {
  public:
    int items[MAX];
    int top;
    int size;

    Stack() {
      top = -1;
      size = 0;
    }

    bool isFull() {
      return top == MAX -1 ? true : false;
    }

    bool isEmpty() {
      return top == -1 ? true : false;
    }

    void push(int value) {
      if(isFull()) {
        cout << "Stack is Full" << endl;
        return;
      } else {
        top++;
        items[top] = value;
      }
      size++;
    }

    void pop() {
      if(isEmpty()) {
        cout << "Stack is Empty" << endl;
        return;
      } else {
        cout << "Item " << items[top] << " is removed" << endl;
        top--;
      }
      size--;
    }

    void printStack() {
      for(int i = 0; i < size; i++)
        cout << items[i] << " ";
      cout << endl;
    }

    void peek() {
      if(isEmpty()) {
        cout << "Stack is Empty" << endl;
        return;
      }
      cout << "Top Element is: " << items[top] << endl;
    }
};


int main() {
  Stack *st = new Stack();

  for(int i = 0; i < 5; i++)
    st->push(i);

  st->pop();
  st->printStack();
  return 0;
}