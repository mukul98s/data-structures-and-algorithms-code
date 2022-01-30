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

void insertionSort(int arr[], int size) {
  for(int step = 1; step < size; step++) {
    // selecting the key element
    int key = arr[step];
    cout << "Key => " << key << endl;
    int j = step - 1;

    // if key is smaller previous element, move the arr element to right by 1
    while(j >= 0 && key < arr[j]) {
      cout << arr[j+1] << " => " << arr[j] << endl;
      arr[j+1] = arr[j];
      j--;
    }
    cout << arr[j+1] << " => " << key << endl;
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {3, 2, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  insertionSort(arr, size);
  printArray(arr, size);
  return 0;
}