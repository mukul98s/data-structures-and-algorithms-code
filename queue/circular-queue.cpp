#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class Queue {
  public:
    int items[MAX];
    int front;
    int rear;

    Queue() {
      front = -1;
      rear = -1;
    };

    void enQueue(int val) {
      if(isFull()) {
        cout << "Queue is Full" << endl;
        return;
      }
      if(front == -1) {
        front = 0;
      }
      rear = (rear + 1) % MAX;
      items[rear] = val;
    }

    int deQueue() {
      if(isEmpty()) {
        cout << "Queue is Empty";
        exit(0);
      }
      int element = items[front];
      if(front == rear) {
        front = -1;
        rear = -1;
      } else {
        // Queue has only one element
        // so we are resetting the queue
        front = (front + 1) % MAX;
      }
      return element;
    }

    bool isFull() {
      if (front == 0 && rear == MAX - 1)
        return true;
      if (front == rear + 1)
        return true;
      return false;
    }

    bool isEmpty() {
      return front == -1 ? true : false;
    }

   void display() {
    int i;
    if (isEmpty()) {
      cout << endl << "Empty Queue" << endl;
    }
    else {
      cout << "Front -> " << front;
      cout << endl << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % MAX) {
        cout << items[i] << " ";
      }
      cout << items[i];
      cout << endl << "Rear -> " << rear;
    }
  }
};

int main() {
  Queue *q = new Queue();

  q->enQueue(1);
  q->enQueue(2);
  q->enQueue(3);
  q->enQueue(4);
  q->enQueue(5);

  q->display();
  return 0;
}