#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int arr[], int size) {
  for( int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void selectionSort(int arr[], int size) {
  for(int step = 0; step < size; step++) {
    int min_index = step;
    // loop to compare our min_index element with the whole array
    for( int i = step + 1; i < size; i++) {
      // if next element is smaller than the min element, we'll shift the min_index to that element
      if(arr[i] < arr[min_index]) {
        min_index = i;
      }
    }
    // put min element at its correct position
    swap(&arr[min_index],&arr[step]);
  }
}

int main() {
  int arr[] = {3, 2, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  selectionSort(arr, size);
  printArray(arr, size);
  return 0;
}