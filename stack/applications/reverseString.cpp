#include <bits/stdc++.h>
using namespace std;

void reverseString(char *c, int length) {
  stack<char> s;
  for(int i = 0; i < length; i++) {
    s.push(c[i]);
  }

  for(int i = 0; i < length; i++) {
    c[i] = s.top();
    s.pop();
  }

  cout << c;
}

int main() {
  char c[51];
  cout << "Enter the String: " << endl;
  gets(c);

  reverseString(c,strlen(c));
  return 0;
}