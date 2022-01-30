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
}

int main() {
  Node* head;
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;

  printLinkedList(head);

  return 0;
}