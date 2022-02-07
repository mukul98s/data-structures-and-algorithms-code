#include <bits/stdc++.h>
using namespace std;

/*******************************
  Sort the stack using recursion
********************************/

void sortedInsert(stack<int> &st, int element) {
  if(st.empty() || element > st.top()) {
    st.push(element);
    return;
  }
  int insert_temp = st.top();
  st.pop();
  sortedInsert(st, element);
  st.push(insert_temp);
}

void sortStack(stack<int> &st) {
  if(st.empty())
    return;

  int sort_temp = st.top();
  st.pop();
  sortStack(st);
  sortedInsert(st, sort_temp);
}

int main() {
  stack<int> st;
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(1);
  st.push(0);

  sortStack(st);

  // print the stack
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}