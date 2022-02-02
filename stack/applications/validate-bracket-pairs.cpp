#include <bits/stdc++.h>
using namespace std;

bool isOpeningBracket (char c) {
  return c == '(' ? true : (c == '[' ? true : (c == '{' ? true : false));
}

bool bracketPairs(string brackets) {
  stack<char> st;

  for(int i = 0; i < brackets.length(); i++) {
    char c = brackets[i];

    if(isOpeningBracket(c))
      st.push(c);
    else if ( c == ')') {
      if(st.empty() || st.top() != '(') return false;
      st.pop();
    }
    else if ( c == '}') {
      if(st.empty() || st.top() != '{') return false;
      st.pop();
    }
    else {
      if(st.empty() || st.top() != '[') return false;
      st.pop();
    }
  }
  return st.empty();
}

int main() {
  string brackets = "([{}[{]}]])";
  bool result = bracketPairs(brackets);

  if(result) cout << "Valid Bracket Pairs";
  else cout << "Invalid Bracket Pairs";
}