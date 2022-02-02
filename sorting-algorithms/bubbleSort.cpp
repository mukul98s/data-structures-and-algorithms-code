#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


// this algorithm will always yeild time complexity of n^2
// to further optimize this we can use a swapped boolean
// if a part of an array is already sorted then it will break the loop

// void bubbleSort(int arr[], int size) {
//   for( int step = 0; step < size; step++ ) {
//     for( int j = 0; j < size - step; j++) {
//       if(arr[j] > arr[j+1]){
//         swap(&arr[j],&arr[j+1]);
//       }
//     }
//   }
// }

// Function to implement bubble sort
void bubbleSort(int arr[], int size) {
  for( int step = 0; step < size; step++ ) {
    bool swapped = false;
    for( int j = 0; j < size - step; j++) {
      if(arr[j] > arr[j+1]){
        swap(&arr[j],&arr[j+1]);
        swapped = true;
      }
    }

    if(swapped == false) break;
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {-1,3,2,1,0,10,8,7,6,5,4,2,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  cout<<"Original array: \n";
  printArray(arr, size);
  bubbleSort(arr, size);
  cout<<"Sorted array: \n";
  printArray(arr, size);
  return 0;
}
