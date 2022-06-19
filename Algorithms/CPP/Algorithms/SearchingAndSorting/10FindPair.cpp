#include<iostream>
#include<algorithm>

using namespace std;

bool findPair(int arr[], int size, int n){

  sort(arr, arr + size);

  int i = 0, j = 1;

  while(i < size and j < size){

    if(i != j and (arr[i] - arr[j] == n or arr[j] - arr[i] == n)){
      return true;
    }

    if(arr[j] - arr[i] < n){
      j++;
    }else{
      i++;
    }
  }

  return false;
}

int main(void){
  int arr[] = {5, 20, 3, 2, 5, 80};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << findPair(arr, n, 78) << endl;

  return 0;
}
