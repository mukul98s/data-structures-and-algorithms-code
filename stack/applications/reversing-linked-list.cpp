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
  stack<Node *> st;
  // 1. push every node of the linked list into the stack
  // traverse till the last element of the linked list
  // push n -1 items in the stack
  Node *ptr = head;
  while(ptr->next != NULL) {
    st.push(ptr);
    ptr = ptr->next;
  }

  // make the last element as head
  head = ptr;

  // 2. Now pop every element from the stack
  // assign the popped element as a linked list Node
  while(!st.empty()) {
    ptr->next = st.top();
    ptr = ptr->next;
    st.pop();
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