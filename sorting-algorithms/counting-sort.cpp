#include <bits/stdc++.h>
using namespace std;

/************************
  COUNTING SORT ALGORITHM
*************************/

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int findLargestElement(int arr[], int size) {
  int largest = arr[0];
  for(int i = 0; i < size; i++) {
    if(largest < arr[i])
      largest = arr[i];
  }
  return largest;
}

void countingSort(int arr[], int size) {
  int output[size];
  // 1. find the max element from the array
  int max = findLargestElement(arr, size);

  // 2. create and initialize count array
  int count[max+1];
  for(int i = 0; i < max + 1; i++)
    count[i] = 0;

  // 3. count element's appreane in the array and store the count at element's index in the count array
  for(int i = 0; i < size; i++)
    count[arr[i]]++;

  // 4. find the cumulitive sum in the count arr
  for(int i = 0; i < max+1; i++)
    count[i+1] = count[i] + count[i+1];

  // 5. Find the index of each element of the original array in count array, and place the elements in output array
  for(int i = size - 1; i >= 0; i--) {
    int element = arr[i];
    count[element]--;
    output[count[element]] = element;
  }

  // 6. copy the element of ouput into the original arr
  for(int i = 0; i < size; i++)
    arr[i] = output[i];

}

int main() {
  int arr[] = {5, 1, 7, 5, 4, 8, 10, 9, 6, 2, 1, 4, 5, 6, 2, 3, 4};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << "Before Sorting:" << endl;
  printArray(arr, size);

  countingSort(arr, size);

  cout << "After Sorting:" << endl;
  printArray(arr, size);

  return 0;
}