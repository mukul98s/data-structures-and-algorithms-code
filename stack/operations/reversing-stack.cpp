#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int val) {
  if(st.empty()) {
    st.push(val);
    return;
  }

  int top =st.top();
  st.pop();
  insertAtBottom(st, val);
  st.push(top);
}

void reverseStack(stack<int> &st) {
  if(st.empty())
    return;

  int x = st.top();
  st.pop();
  reverseStack(st);
  insertAtBottom(st, x);
}

int main() {
  stack<int> st;
  string result;

  for( int i = 1; i <= 10; i++)
    st.push(i);

  reverseStack(st);

  // print the stack
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}