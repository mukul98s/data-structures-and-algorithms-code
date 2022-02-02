#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int val) {
      data = val;
    }
};

class Stack {
  public:
    Node *top;
    Stack() {
      top = NULL;
    }

    void push(int data) {
      Node *temp = new Node(data);

      if(!temp) cout << "Heap Overflow" << endl;

      temp->next = top;
      top = temp;
    }

    void pop() {
      Node *temp;
      if(top == NULL){
        cout << "Stack Underflow" << endl;
        exit(1);
      } else {
        temp = top;
        top = top->next;
        temp->next = NULL;
      }
    }

    void printStack() {
      Node *ptr = top;

      while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
      }
      cout << endl;
    }

    int isEmpty() {
      return top == NULL;
    }

    Node* topOfStack() {
      return top;
    }
};

int main() {
  Stack *st = new Stack();

  for(int i = 1; i <= 5; i++)
    st->push(i);

  st->printStack();
  return 0;
}