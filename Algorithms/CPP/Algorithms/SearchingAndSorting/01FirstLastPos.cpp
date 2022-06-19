#include<iostream>

using namespace std;

int first(int arr[], int n, int x){

  int low = 0, high = n - 1, res = -1;

  while(low <= high){

    int mid = (low + high) / 2;

    if(arr[mid] > x){
      high = mid - 1;
    }else if(arr[mid] < x){
      low = mid + 1;
    }else{
      res = mid;
      high = mid - 1;
    }
  }

  return res;
}

int last(int arr[], int n, int x){
  
  int low = 0, high = n - 1, res = -1;

  while(low <= high){
    
    int mid = (low + high) / 2;

    if(arr[mid] > x){
      high = mid - 1;
    }else if(arr[mid] < x){
      low = mid + 1;
    }else{
      res = mid;
      low = mid + 1;
    }  
  }

  return res;
}

int main(void){

  int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 2;

  cout << first(arr, n, x) << " " << last(arr, n, x) << endl;

  return 0;
}
