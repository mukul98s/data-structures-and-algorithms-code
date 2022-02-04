#include <bits/stdc++.h>
using namespace std;

/*********************
  RADIX SORT ALGORITHM
**********************/

// function to print array
void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// function to find the largest element in the array
int find_largest_element_in_arrary(int arr[], int size) {
  int largest = arr[0];
  for(int i = 0; i < size; i++) {
    if(largest < arr[i])
      largest = arr[i];
  }
  return largest;
}

void countingSort(int arr[], int size, int place) {
  int max = find_largest_element_in_arrary(arr, size);
  int count[max+1];
  int output[size];

  for(int i = 0; i < max + 1; i++)
    count[i] = 0;

  for(int i = 0; i < size; i++)
    count[(arr[i]/place) % 10]++;

  for(int i = 0; i < max+1; i++)
    count[i+1] = count[i] + count[i+1];

  for(int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i]/place) % 10]--;
  }

  for(int i = 0; i < size; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int size) {
  // find the maximum element in the array
  int max = find_largest_element_in_arrary(arr, size);

  // applying counting sort for each digit place
  for(int place = 1; max / place > 0; place*=10)
    countingSort(arr, size, place);
}

int main() {
  int arr[] = {121, 432, 564, 23, 1, 45, 788};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << "Before Sorting: " << endl;
  printArray(arr, size);

  radixSort(arr, size);

  cout << "After Sorting: " << endl;
  printArray(arr, size);

  return 0;
}