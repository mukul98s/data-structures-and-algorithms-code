#include <bits/stdc++.h>
using namespace std;

// initial max capacity of stack
#define MAX 4

int top = -1;
int length = 0;

// function to create a new stack
int* create_new_stack(int *a) {
  int *temp_stack = new int(length + MAX);

  // copying element of previous stack in the new stack
  for(int i = 0; i < length; i++)
    temp_stack[i] = a[i];

  // re-sizing the length
  length += MAX;

  return temp_stack;
}

// function to push element into the stack
int* push(int *a, int element) {
  // if stack is full, create a new stack
  if(top == length - 1) {
    a = create_new_stack(a);
  }

  top++;
  a[top] = element;

  return a;
}

void pop() {
  top--;
}

void display(int* a) {
  // if top is -1, that means stack is empty
  if (top == -1)
    cout << "Stack is Empty" << endl;
  else {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
      cout << a[i] << " ";
    cout << endl;
  }
}

int main() {
  int *a = create_new_stack(a);

  a = push(a,1);
  a = push(a,2);
  a = push(a,3);
  a = push(a,4);
  a = push(a,5);
  a = push(a,6);
  pop();
  display(a);
  return 0;
}