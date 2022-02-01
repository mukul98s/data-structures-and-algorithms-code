#include <bits/stdc++.h>
using namespace std;

long postfix(char *exp) {
  stack <long> st;

  // loop through the the expression
  for( int i = 0; i < strlen(exp); i++ ) {

    // pick out char one by one.
    char val = exp[i];

    // if it is a digit, push it into the stack
    if(isdigit(val)) {
      st.push(val - '0');
    }

    // if it is a operator
    else {

      // make top as first char
      char one = st.top();
      // remove the top var
      st.pop();
      // make top as second char
      char two = st.top();
      // remove the top
      st.pop();

      // now bases on the operator
      // perform the operation and push it into the stack
      switch (val) {
        case '+':
          st.push(one + two);
          break;
        case '-':
          st.push(two - one);
          break;
        case '*':
          st.push(one * two);
          break;
        case '/':
          st.push(two / one);
          break;
        case '^':
          st.push(pow(two,one));
          break;
        default:
          break;
      }
    }
  }

  // the top of the stack is the result now.
  return st.top();
}

int main() {
  char exp[] = "1234^5-678*+-*+9-";
  long result = postfix(exp);
  cout << result << endl;
  return 0;
}