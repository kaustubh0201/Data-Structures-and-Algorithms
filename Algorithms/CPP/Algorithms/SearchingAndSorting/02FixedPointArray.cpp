#include<iostream>

using namespace std;

int searchIndex(int arr[], int low, int high){
  
  if(low <= high){
    
    int mid = low + (high - low) / 2;

    if(mid == arr[mid]){
      return mid;
    }

    int res = -1;

    if(mid + 1 <= arr[high])
      res = searchIndex(arr, mid + 1, high);

    if(res != -1)
      return res;

    if(mid - 1 >= arr[low])
      return searchIndex(arr, low, mid - 1);
  }

  return -1;

}

int main(void){

    int arr[10] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << searchIndex(arr, 0, n - 1) << endl;

  return 0;
}
