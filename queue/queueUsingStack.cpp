#include <bits/stdc++.h>
using namespace std;

// In this code, we are assuming that the top of the queue
// and the stack is on the same side.

class Queue {
  public:
    stack<int> st;
    stack<int> temp;

    Queue() {
      for(int i = 1; i <= 10; i++ )
        st.push(i);
    }

    void enQueue(int val) {
      while(!st.empty()) {
        temp.push(st.top());
        st.pop();
      }

      st.push(val);

      while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
      }
    }

    void deQueue() {
      st.pop();
    }

    void print() {
      if(st.empty()) {
        cout << "Queue is Empty";
        return;
      }

      while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
      }
    }
};

int main() {
  Queue *q = new Queue();
  q->deQueue();
  q->enQueue(10);
  q->enQueue(11);
  q->print();

  return 0;
}