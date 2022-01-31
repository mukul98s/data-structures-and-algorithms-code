#include <bits/stdc++.h>
#include <stack>
using namespace std;

int factorial(int number) {
  int factorial_result = 1;
  if(number == 0 || number == 1) {
    return factorial_result;
  }

  stack <int> s;
  for(int i = number; i > 0; i--)
    s.push(i);

  while(!s.empty()) {
    factorial_result *= s.top();
    s.pop();
  }

  return factorial_result;
}

int main() {
  int number;
  cout << "Enter the Number : " ;
  cin >> number;

  int fact = factorial(number);

  cout << "Factorial of " << number << " is: " << fact << endl;
  return 0;
}