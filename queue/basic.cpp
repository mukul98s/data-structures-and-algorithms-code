#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Queue {
  private:
    int items[MAX];
    int front;
    int rear;

  public:
    Queue() {
      front = -1;
      rear = -1;
    }

    bool isFull() {
      return (front == 0 && rear == MAX - 1) ? true : false;
    }

    bool isEmpty() {
      return front == -1 ? true : false;
    }

    void enQueue(int value) {
      if(isFull()) {
        cout << "Queue is Full" << endl;
        return;
      }
      if(front == -1) {
        front = 0;
      }
      rear++;
      items[rear] = value;
    }

    void deQueue() {
      if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
      } else {
        if(front >= rear) {
          front = -1;
          rear = -1;
        } else {
          front++;
        }
      }
    }

    void display() {
      if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
      } else {
        cout << "Front is " << front << endl;
        cout << "Rear is " << rear << endl;
        for( int i = front; i <= rear; i++)
          cout << items[i] << " ";
        cout << endl;
      }
    }
};

int main() {
  Queue *qu = new Queue();

  for(int i = 0; i < 10; i++) {
    qu->enQueue(i);
  }

  qu->deQueue();
  qu->display();
  return 0;
}