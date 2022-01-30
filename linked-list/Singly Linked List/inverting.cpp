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

Node* reverse(Node *head) {
  // store the pointer of previous element
  Node *prev = NULL;
  // take care of present element
  Node *current = head;
  // remember next element when we change current's pointer
  Node *following = head;

  while(current != NULL) {
    // pointing the following to the next node to preserve the value of the current
    following = following->next;

    // set the current->next to previous element
    current->next = prev;

    // set previous to current. This will move the prev one step ahead in the linked list
    prev = current;

    // set current to the following. Which is storing the next node in the linked list
    current = following;
  }

  // now return prev because it will act as an head for the inverted linked list
  return prev;
}

int main() {
  Node* head;
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);

  one->next = two;
  two->next = three;
  three->next = four;
  four->next = NULL;

  head = one;

  cout << "Intial Linked List" << endl;
  printLinkedList(head);

  Node *newHead = reverse(head);

  cout << "Final Linked List" << endl;
  printLinkedList(newHead);

  return 0;
}