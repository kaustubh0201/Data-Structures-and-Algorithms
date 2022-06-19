#include<iostream>

using namespace std;

int findPivot(int arr[], int low, int high){

  if(low > high)
    return -1;

  if(low == high)
    return low;

  int mid = (low + high) / 2;

  if(mid < high and arr[mid] > arr[mid + 1]){
    return mid;
  }

  if(mid > low and arr[mid] < arr[mid - 1])
    return mid - 1;

  if(arr[low] >= arr[mid])
    return findPivot(arr, low, mid - 1);

  return findPivot(arr, mid + 1, high);
}

int binarySearch(int arr[], int low, int high, int key){

  if(low > high)
    return -1;

  int mid = (low + high) / 2;

  if(arr[mid] == key)
    return mid;

  if(key > arr[mid])
    return binarySearch(arr, mid + 1, high, key);

  return binarySearch(arr, low, mid - 1, key);
}

int search(int arr[], int n, int key){
  int pivot = findPivot(arr, 0, n - 1);

  if(pivot == -1)
    return binarySearch(arr, 0, n - 1, key);

  if(arr[pivot] == key)
    return pivot;

  if(arr[0] <= key){
    return binarySearch(arr, 0, pivot - 1, key);
  }

  return binarySearch(arr, pivot + 1, n - 1, key);
}

int main(void){

  int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 10;

  cout << search(arr, n, key) << endl;

  return 0;
}
