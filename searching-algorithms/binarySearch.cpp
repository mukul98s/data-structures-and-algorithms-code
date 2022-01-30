#include <bits/stdc++.h>
using namespace std;

// iterative approach
/*
int binarySearch(int arr[],int element, int low, int high) {
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(arr[mid] == element)
      return mid;
    else if(arr[mid] < element)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
*/

// recursive approach
int binarySearch(int arr[], int element, int low, int high) {
  if(low <= high) {
    int mid = low + (high - low)/2;

    return arr[mid] == element
    ? mid
    : (arr[mid] < element
      ? binarySearch(arr, element, mid + 1, high)
      : binarySearch(arr, element, low, mid - 1));

    // if(arr[mid] == element)
    //   return mid;
    // else if (arr[mid] < element)
    //   return binarySearch(arr, element, mid + 1, high);
    // else
    //   return binarySearch(arr, element, low, mid - 1);
  }
  return -1;
}

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int element = 1;
  int size = sizeof(arr)/sizeof(arr[0]);

  int result = binarySearch(arr, element, 0, size - 1);

  if (result == -1)
    cout << "Element is not found" << endl;
  else
    cout << "Element is found at " << result << " index" << endl;
  return 0;
}