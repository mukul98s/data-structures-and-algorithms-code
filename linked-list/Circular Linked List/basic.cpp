#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;

    Node(int d) {
      data = d;
    }
};

void traverse(Node* last) {
  Node* p;
  if (last == NULL) {
    cout << "The list is empty" << endl;
    return;
  }

  p = last->next;

  do {
    cout << p->data << " ";
    p = p->next;
  } while (p != last->next);
}

Node* addToEmpty(Node *last, int data) {
  if(last != NULL) {
    return last;
  }

  Node *temp = new Node(data);
  last = temp;
  last->next = last;

  return last;
}

Node* addToFront(Node *last, int data) {
  if(last == NULL)
    return addToEmpty(last,data);

  Node *temp = new Node(data);
  temp->next = last->next;
  last->next = temp;

  return last;
}

Node* addToEnd(Node *last, int data) {
  if(last == NULL)
    return addToEmpty(last,data);

  Node *temp = new Node(data);
  temp->next = last->next;
  last->next = temp;

  last = temp;

  return last;
}

Node* insertAfter(Node *last, int data, int item) {
  if(last == NULL)
    return NULL;

  Node *temp = new Node(data), *p;
  p = last->next;

  do {
    if (p->data == item) {
    // make the next of the current node as the next of newNode
    temp->next = p->next;
    // put newNode to the next of p
    p->next = temp;
    // if p is the last node, make newNode as the last node
    if (p == last)
      last = temp;
    return last;
  }

  p = p->next;
  } while (p != last->next);

  return last;
}

int main() {
  Node *last = NULL;

  last = addToEmpty(last,1);
  last = addToFront(last,0);
  last = addToEnd(last,2);
  last = insertAfter(last,3,2);

  traverse(last);
}