#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


// this algorithm will always yeild time complexity of n^2
// to further optimize this we can use a swapped boolean
// if a part of array if already sorted then it will break the loop

// void bubbleSort(int arr[], int size) {
//   for( int step = 0; step < size; step++ ) {
//     for( int j = 0; j < size - step; j++) {
//       if(arr[j] > arr[j+1]){
//         swap(&arr[j],&arr[j+1]);
//       }
//     }
//   }
// }

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

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {-1,3,2,1,0,10,8,7,6,5,4,2,1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  bubbleSort(arr, size);
  printArray(arr, size);
  return 0;
}