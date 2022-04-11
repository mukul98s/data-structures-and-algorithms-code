#include <bits/stdc++.h>
using namespace std;

class Queue {
  public:
    stack<int> st;
    stack<int> temp;

    Queue() {
      for(int i = 1; i <= 10; i++ )
        st.push(i);
    }

    void enQueue(int val) {
      st.push(val);
    }

    int deQueue() {
      if (temp.empty()) {
        while (!st.empty()) {
          temp.push(st.top());
          st.pop();
        }
      }

      int x = temp.top();
      temp.pop();
      return x;
    }

    void print() {
      if(st.empty()) {
        cout << "Stack is Empty";
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
  q->enQueue(11);
  q->deQueue();

  return 0;
}