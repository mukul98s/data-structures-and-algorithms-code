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

void printLinkedList(Node *head) {
  while(head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void appendToList(Node **head, int data) {
  Node *temp = new Node(data);
  Node *last = *head;
  temp->next = NULL;

  if( *head == NULL) {
    *head = temp;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }
  last->next = temp;
}

Node* reverseList(Node *head) {
  Stack *st = new Stack();
  // 1. push every node of the linked list into the stack
  Node *ptr = head;
  while(ptr->next != NULL) {
    st->push(ptr->data);
    ptr = ptr->next;
  }

  head = ptr;
  // 2. Now pop every element from the stack
  // assign the popped element as a linked list Node
  while(!st->isEmpty()) {
    ptr->next = st->topOfStack();
    ptr = ptr->next;
    st->pop();
  }
  ptr->next = NULL;
  return head;
}

int main() {
  Node* head = NULL;

  for(int i = 1; i <= 10; i++)
    appendToList(&head,i);

  cout << "Before reversing List:" << endl;
  printLinkedList(head);

  head = reverseList(head);

  cout << "After reversing List:" << endl;
  printLinkedList(head);
  return 0;
}