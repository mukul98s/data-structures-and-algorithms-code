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

bool searchNode(Node *head, int key) {
  while(head != NULL) {
    if(head->data == key)
      return true;
    head = head->next;
  }
  return false;
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

  cout << searchNode(head,1) << endl;
  cout << searchNode(head,4) << endl;
  printLinkedList(head);

  return 0;
}