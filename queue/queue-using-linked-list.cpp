#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int d) {
      data = d;
    }
};

class Queue {
  public:
    Node *front;
    Node *rear;

    Queue() {
      front = NULL;
      rear = NULL;
    }

    bool isEmpty() {
      return front == NULL;
    }

    void enQueue(int data) {
      Node *temp = new Node(data);

      if(!temp)
        cout << "Heap Overflow" << endl;

      if(rear == NULL) {
        front = rear = temp;
      }

      rear->next = temp;
      rear = temp;
    }

    void deQueue() {
      if(front == NULL) {
        cout << "Queue is Empty" << endl;
        return;
      }

      Node *temp = front;
      front = front->next;

      if(front == NULL) rear = NULL;
      free(temp);
    }
};

int main() {
  Queue *q = new Queue();

  q->enQueue(3);
  q->enQueue(4);
  q->enQueue(5);
  q->enQueue(6);
  q->deQueue();

  cout << "Front: " << q->front->data << endl;
  cout << "Rear: " << q->rear->data << endl;
  return 0;
}