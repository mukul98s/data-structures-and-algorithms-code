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
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << endl;
}

void sort(Node **head) {
  Node *current = *head;
  Node *index = NULL;
  int temp;

  if(current == NULL) {
    return;
  } else {
    while(current != NULL) {
      index = current->next;
      while(index != NULL) {
        if(current->data > index->data) {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}

int main() {
  Node* head;
  Node* one = new Node(3);
  Node* two = new Node(2);
  Node* three = new Node(1);

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;

  printLinkedList(head);
  sort(&head);
  printLinkedList(head);

  return 0;
}