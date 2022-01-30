#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int value) {
      data = value;
    }
};

void printLinkedList(Node *head) {
  while(head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
}

void insertAtHead(Node **head, int data) {
  Node *temp = new Node(data);
  temp->next = *head;
  *head = temp;
}

void insertAtEnd(Node **head, int data) {
  Node *temp = new Node(data);
  Node *last = *head;

  // if linked list is empty
  if (*head == NULL) {
    *head = temp;
    return;
  }

  while(last->next != NULL) {
    last = last->next;
  }

  last->next = temp;
  return;
}

void insertAfter(Node *prev, int data) {
  if(prev == NULL)
    cout << "Element cannot be null" << endl;

  Node *temp = new Node(data);
  temp->next = prev->next;
  prev->next = temp;
}

void deleteHead(Node *head) {
  head = head->next;
  cout << "Deleted Head" << endl;
}

void deleteEnd(Node *head) {
  while(head->next->next != NULL) {
    head = head->next;
  }

  head->next = NULL;
  cout << "End is Deleted " << endl;
}

void deleteRandon(Node **head, int key) {
  Node *temp = *head, *prev;

  if(temp != NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

int main() {
  Node *head;
  Node *one = new Node(1);
  Node *two = new Node(2);
  one->next = two;
  two->next = NULL;

  head = one;

  insertAtHead(&head,0);
  insertAtEnd(&head,2);
  insertAfter(two,3);

  deleteHead(head);
  // deleteEnd(head);
  deleteRandon(&head, 3);

  printLinkedList(one);

  return 0;
}