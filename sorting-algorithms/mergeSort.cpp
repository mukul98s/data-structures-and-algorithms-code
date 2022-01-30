#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// merge two subarray i.e. L and M into arr
// p is starting index, q is the middle index where we need to break the array, r is index of last element
void merge(int arr[], int p, int q, int r) {
  //array lengths for L and M respectively
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1];
  int M[n2];

  // add elements in L
  for(int i = 0; i < n1; i++) {
    L[i] = arr[p + i];
  }

  // add elements in M
  for(int i = 0; i < n2; i++) {
    M[i] = arr[q + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = p;

  // until we reached the end of either L or M
  // pick the larger element and place it in the arr at correct position
  while(i < n1 && j < n2) {
    if(L[i] <= M[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }

    k++;
  }

  // if we ran out of elements from M, then we'll pick the elements of L
  // place them at the correct position in arr
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // if we ran out of elements from L , then we'll pick the elements of M
  // place them at the correct position in arr
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void MergeSort(int arr[], int l, int r) {
  if( l < r) {
    // this is the point where we need to divide the array
    int m = l + (r - l)/2;

    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);

    // Merge the sorted subarray
    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {0, 5, 1, 7, 1, 4, 2, 3, 5, -7, -8, -1, 4, 5, 6, 8, 7, 87, 4, 5, 100, 15, 45, 48, 45, 1, 6, 0, 78 };
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  MergeSort(arr, 0, size - 1);
  printArray(arr, size);

  return 0;
}