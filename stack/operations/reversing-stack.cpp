#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> st, int val) {
  if(st.size() == 0)
    st.push(val);
  else {
    int a = st.top();
    st.pop();
    insertAtBottom(st, a);
  }
}

void reverseStack(stack<int> st) {
  if(st.size() > 0) {
    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
  }
}

int main() {
  stack<int> st;
  string result;

  for( int i = 1; i <= 10; i++)
    st.push(i);

  reverseStack(st);


  return 0;
}