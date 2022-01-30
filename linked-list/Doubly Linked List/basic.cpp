#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
      data = val;
    }
};

void print(Node *head) {
  // Node *last;

  if(head == NULL) {
    cout << "Empty Linked List" << endl;
  }

  while(head != NULL) {
    cout << head->data << "->";
    // last = head;
    head = head->next;
  }
}

void insertAtStart(Node **head, int val) {
  Node *temp = new Node(val);

  temp->next = *head;
  temp->prev = NULL;

  // point the first Node (Now second Node) to the new create temp Node
  if( (*head) != NULL) {
    (*head)->prev = temp;
  }

  // changing the head element.
  *head = temp;
}

void insertInBetween(Node *prevNode, int val) {
  if(prevNode == NULL) {
    cout << "Previous Node Cannot be NULL" << endl;
    return;
  }

  // 1. create a new Node
  Node *newNode = new Node(val);

  // set the next of newNode to the next of prevNode
  newNode->next = prevNode->next;

  // set the next of prevNode to newNode
  prevNode->next = newNode;

  // set the prev of newNode to prevNode
  newNode->prev = prevNode;

  // set prev of newNode's next to newNode
  if(newNode->next != NULL) {
    newNode->next->prev = newNode;
  }
}

void insertAtEnd(Node *head, int val) {
  Node *newNode = new Node(val);
  newNode->next = NULL;

  // if head is empty we'll create the newNode as an head
  if(head == NULL) {
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  // traverse to the last element of the linked list
  while(head->next != NULL) {
    head = head->next;
  }

  // set the next node of the last element to the newNode
  head->next = newNode;

  // set the prev of the newNode to the last node
  newNode->prev = head;
}

void deleteNode(Node **head, Node *deleteNode) {
  // if both head and deleteNode is NULL return
  if(*head == NULL && deleteNode == NULL)
    return;

  // if deleteNode is head, set head as the next node of deleteNode
  if(*head == deleteNode)
    *head = deleteNode->next;

  // if delete element is not the last element
  // set the prev of next of deleteNode as prev of deleteNode
  if(deleteNode->next != NULL)
    deleteNode->next->prev = deleteNode->prev;

  // if deleteNode is node the first element
  // set the next of prev of deleteNode as next of deleteNode
  if(deleteNode->prev != NULL)
    deleteNode->prev->next = deleteNode->next;

  // free the memory of delete node
  free(deleteNode);
}

int main() {
  Node *head;
  Node *one = new Node(1);
  Node *two = new Node(2);
  Node *three = new Node(3);
  Node *four = new Node(4);

  one->prev = NULL;
  one->next = two;

  two->prev = one;
  two->next = three;

  three->prev = two;
  three->next = four;

  four->prev = three;
  four->next = NULL;

  head = one;

  insertAtStart(&head,0);
  insertInBetween(one,5);
  insertAtEnd(head,6);

  deleteNode(&head, head->next);
  deleteNode(&head,head->next->next);

  print(head);

  return 0;
}