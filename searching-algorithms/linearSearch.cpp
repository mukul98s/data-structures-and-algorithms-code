#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int element) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == element)
      return i;
  }

  return -1;
}

int main() {
  int arr[] = {1,6,5,9,4,7,8,5};
  int size = sizeof(arr)/sizeof(arr[0]);

  int result = linearSearch(arr, size, 5);

  if(result == -1)
    cout << "Element is not found " << endl;
  else
    cout << "Element is found at index " << result << endl;
  return 0;
}