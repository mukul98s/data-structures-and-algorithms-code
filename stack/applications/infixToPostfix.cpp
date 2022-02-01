#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
  if(c == '^') return 3;
  else if(c == '/' || c=='*') return 2;
  else if(c == '+' || c == '-') return 1;
  else return -1;
}

void infix_to_postfix(string exp) {
  stack<char> st;
  string result;

  for(int i = 0; i < exp.length(); i++) {
    char c = exp[i];

    // if it a character or number add it to the result string
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // if char is "(" push it in the stack
    else if (c == '(')
      st.push('(');
    // if char is ")" add the top of stack to result and pop it
    // until top does not become "("
    // finally also remove the top
    else if( c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }
    // else loop until stack is not empty and priority of char is less that equal to the to top of the stack
    // add the top to the result and pop
    // if loop doesn't exit than push the char to the stack
    else {
      while (!st.empty() && priority(c) <= priority(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // at last loop until stack is not empty
  // add the element to result and pop
  while(!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << result << endl;
}

int main() {
  string exp = "a+b*(c^d-e)^(f+g*h)-i";
  infix_to_postfix(exp);
  return 0;
}