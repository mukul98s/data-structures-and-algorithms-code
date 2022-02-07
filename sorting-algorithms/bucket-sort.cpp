#include <bits/stdc++.h>
using namespace std;

#define SIZE_OF_ARRAY 7    // size of array
#define NUMBER_OF_BUCKETS 6   // number of buckets
#define INTERVAL 10  // bucket capacity

class Node {
  public:
    int data;
    Node *next;
    Node(int d) {
      data = d;
    }
};

// function for printing an array
void print(int arr[]) {
  for(int i = 0; i < SIZE_OF_ARRAY; i++)
    cout << setw(3) << arr[i];
  cout << endl;
}

// function on printing linked list
void printBuckets(Node *list) {
  Node *current = list;
  while(current) {
    cout << setw(3) << current->data;
    current = current->next;
  }
}

// insertion sort for linked list
Node* InsertionSort(Node *list) {
  Node *k, *nodeList;

  // if list is empty or list has only one item return the list
  if(list == 0 || list->next == 0)
    return list;


  nodeList = list;

  // store the linked list from second element
  k = list->next;
  // isolate the first element from the linked list
  nodeList->next = 0;

  // traverse through the linked list from second element
  while(k != 0) {
    Node *ptr;

    // if the data of first element is greater than the second element
    // swap them and continue
    if(nodeList->data > k->data) {
      Node *temp = k;
      k = k->next;
      temp->next = nodeList;
      nodeList = temp;
      continue;
    }

    for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if(ptr->next->data > k->data)
        break;
    }

    if(ptr->next != 0) {
      Node *temp;
      temp = k;
      k = k->next;
      temp->next = ptr->next;
      ptr->next;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }

  return nodeList;
}

// function for assigning index to an element
int getBucketIndex(int value) {
  return value / INTERVAL;
}

// function to sort the array using buckerSort
void BucketSort(int arr[]) {

  // create an array of type Node
  // this array will store node items which will represent the individual bucket
  Node **buckets;

  // Allocating the memory for the buckets
  buckets = (Node **)malloc(sizeof(Node *) * NUMBER_OF_BUCKETS);

  // initialize empty buckets
  for(int i = 0; i < NUMBER_OF_BUCKETS; i++)
    buckets[i] = NULL;

  // fill the bucket with respective elements
  // traverse through the array and put each element in it's bucket category
  for(int i = 0; i < SIZE_OF_ARRAY; i++) {
    Node *current = new Node(arr[i]);
    int pos = getBucketIndex(arr[i]);
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // print the buckets along with their elements
  for(int i = 0; i < NUMBER_OF_BUCKETS; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  }

  // sort the elements of each bucket
  // traverse through the bucket list and
  // sort each bucket using insertion sort
  for( int i = 0; i < NUMBER_OF_BUCKETS; i++) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  cout << "-------------" << endl;
  cout << "Bucktets after sorted" << endl;
  for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  }

  // put sorted element on array
  // traverse through the bucket list
  // for each bucket traverse and put element into the array
  for( int i = 0, j = 0; i < NUMBER_OF_BUCKETS; i++) {
    Node *node = buckets[i];
    while(node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  // clear the memory of individual bucket item
  for( int i = 0; i < NUMBER_OF_BUCKETS; i++) {
    Node *node = buckets[i];
    while(node) {
      Node *temp = node;
      node = node->next;
      free(temp);
    }
  }

  // clear the memory of the buckets
  free(buckets);
  return;
}

int main() {
  int array[SIZE_OF_ARRAY] = {42, 32, 33, 52, 37, 47, 51};

  cout << "Initial array: " << endl;
  print(array);
  cout << "-------------" << endl;

  BucketSort(array);
  cout << "-------------" << endl;
  cout << "Sorted array: " << endl;
  print(array);
  return 0;
}